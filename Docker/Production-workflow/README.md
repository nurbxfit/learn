# Typical Workflow.
- in typical development enviroment, we will have
    - central code repository
    - a CI (continous Integration) system.
    - a production server.

- when a developing develop a system, they will make changes in a repositories.
- the repo will have a `master` and other branches for development.
- the developer doesn't directly updating the master branch.
- instead they add features to another branches.
- when pushing a new featres to a branch, they will make a `pull request` for that branch to be merge into the master branch.
- a senior or person in charge will go thru the commits and decide wether to accept or reject the `pull request`.
- after tthe merge, the master code will be pull down by our `CI` system, and perform various testing, before then proceed to push to the production server.


# using Docker in our flow.
- this typical workflow doen't necessarily use docker, there are various other software and ways to build the enviroment.
- but docker is a good tool in helping setting things up.
- where does docker come to use ?
    - we use docker to create two container.
    - a development container
    - a test container
    - a production container.
- each containers will run differents things.
    - a development container will run `npm run start` and contains our development code.
    - a test container will run `npm run test` and contains our master code, ready for production.
    - a production container will run using `npm run build`, and then serve it using nginx or httpd.


# Excluding node_module 
- if we use COPY in our project containing `node_modules`
```Dockerfile
COPY ./ ./
```
- it will also copy together the node_modules into the image.
- this ended up increase the size of our image.
- we can avoid this by either simply delete `node_modules` in our project folder.
- or we can use `.dockerignore` to exclude it.
- we add `.dockerignore` inside our project directory together with our Dockerfile and we simply write `node_modules` inside it to exclude.


# Dockerfile.dev
- in our project folder, we create two `Dockerfile`, one is for production and another is for development called `Dockerfile.dev`.
- we can then build our dev image using `docker build -t reactexample -f Dockerfile.dev`.
- our `Dockerfile.dev` look like this, where we run `npm start` when the conainer start.

```Dockerfile
# Dockerfile.dev
FROM alpine

# install node
RUN apk update && apk upgrade
RUN apk add --update nodejs
RUN apk add --update npm
RUN apk add --update git

# set working directory
WORKDIR '/usr/app'
# copy package.json and install node dependencies
COPY package.json ./
RUN npm install

# copy the rest of files
COPY ./ ./

# running npm start
CMD ["npm","start"]
```
- we can list our images that we build using 
```bash
$sudo docker images
```
# Volume.
- when we run our container, and making change to our project file,
 the change doesn't effect our running container.
- we need to rebuild our container and re-run it to view the changes.
- this can be quite tedious, and to overcome this, we can use docker features called `volume`.
- `volume` create a link or reference in our container that point to the folder or files inside our local machine.
- we can use volume, by using the `-v` flag and specify the <localpath>:<containerpath>, when running our container using `docker run`.
- example command will be
```bash
docker run -it -p 3000:3000 --rm -v $(pwd):/usr/app reactexample
```
- these will map the folder we copied into our container with the folder and files inside our local machine.
- let say there is a folder inside our container that we don't have in our local machine,
- let say we remove our `node_modules` from our local machine, to reduce our image size instead of using dockerignore.
- if we run our container, inside our container will have the `node_modules` folder because we run `npm install` in it.
- our container folder have no ideas where to map the `node_modules` folder to our local machine.
- to overcome this issue, we use extra `-v` flag again and specify only the folder we want to map from our container not the path to be map in our local machine.
```bash
docker run -it -p 3000:3000 --rm -v /usr/app/node_modules -v $(pwd):/usr/app reactexample
```  
- noticed that there is not colon `:` to specify where we want to map into our local machine. instead just the path of folder we want to map from our container `/usr/app/node_modules` 

- now when we make a change to our project file let say `src/App.js`, and we save it.
- the changes will get reflected in our browser immediately. without having to re-build our image and re-run our container.


# Using Docker Compose.
- so far we've, setup our projects, create a `Dockerfile` build our image, run our container and map it to our local machine.
- we can use `docker-cli` to run `docker build` and `docker run` anytime we want to run our container, but it's not recommended and tedious.
- we can use Docker compose to setup all of that.
- refer to `Docker-compose.md` to learn more on docker-compose.
- to get started, lets create new `docker-compose.yml` file in our project folder.
- and then add these into our file.
```yml
version: '3'
services: 
    reactexample:
        build: 
            context: .
            dockerfile: Dockerfile.dev
        ports:
            - "3000:3000"
        volumes:
            - /usr/app/node_modules
            - .:/usr/app
```
- here we specify the `volumes` options which contains `/usr/app/node_modules` and `.:/usr/app`. the same argument we previously used with docker run.
- we also specify `context` and `dockerfile` to tell docker build, where to find our file (which is inside current directory `.` ). and which dockerfile to refer to ( in this development case `Dockerfile.dev`).
- then we can run it using `docker-compose up` inside our project directory.
- if you use `dockerignore` to exclude `node_modules` instead of deleting it, please comment the `/usr/app/node_modules` under the volumes config.
- our docker-compose file will look like this.
```yml
version: '3'
services: 
    reactexample:
        build: 
            context: .
            dockerfile: Dockerfile.dev
        ports:
            - "3000:3000"
        volumes:
            # - /usr/app/node_modules
            - .:/usr/app
```
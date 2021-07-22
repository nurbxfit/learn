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
    - we use docker to create three containers.
    - a development container
    - a test container
    - a production container.
- each containers will run differents things.
    - a development container will run `npm run start` and contains our development code.
    - a test container will run `npm run test` and contains our master code, ready for production.
    - a production container will run using `npm run build`, and then serve it using nginx or httpd.





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

# Excluding node_module 
- if we use COPY in our project containing `node_modules`
```Dockerfile
COPY ./ ./
```
- it will also copy together the node_modules into the image.
- this will end up increasing the size of our image.
- we can avoid this by either simply delete `node_modules` in our project folder.
- or we can use `.dockerignore` to exclude it.
- we add `.dockerignore` inside our project directory together with our Dockerfile and we simply write `node_modules` inside it to exclude.

# Volume.
- when we run our container, and making change to our project file,
 the change doesn't effect our running container.
- we need to rebuild our container and re-run it to view the changes.
- this can be quite tedious, and to overcome this, we can use docker features called `volume`.
- `volume` create a link or reference in our container that point to the folder or files inside our local machine.
- we can use volume, by using the `-v` flag and specify the `<localpath>:<containerpath>`, when running our container using `docker run`.
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
    devserver:
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
    devserver:
        build: 
            context: .
            dockerfile: Dockerfile.dev
        ports:
            - "3000:3000"
        volumes:
            # - /usr/app/node_modules
            - .:/usr/app
``` 

## Adding `npm test` to our docker-compose.
- previously we mentioned that we will create 3 containers, developments, test  and production.
- we already created our development image using `Dockerfile.dev`, and added it as a services to our docker compose file.
- for the `test` container, we can either create a new custom `Dockerfile.test` or we can make use of the existing `Dockerfile.dev` images and just overide the startup command to run `npm run test` instead.
- in this example, we are going to simply use the existing `Dockerfile.dev` and use it to build new `test` image and overide the startup.
- we use the existing `docker-compose.yml` file and add a new service name `test`.
- using the same argument as our `devserver` but added a command options to overide the default startup command.
```yml
version: '3'
services: 
    devserver:
        build: 
            context: .
            dockerfile: Dockerfile.dev
        ports:
            - "3000:3000"
        volumes:
            # - /usr/app/node_modules
            - .:/usr/app

    testserver:
        build:
            context: .
            dockerfile: Dockerfile.dev
        volumes:
            - .:/usr/app
        command: ["npm","run","test","--","--coverage"]
```
- here we do not need the ports mapping, because we do not need it when we run `npm run test`. 
- we save this and run `docker-compose up` and it will create 2 containers if we check using `docker ps`. 
- the drawback for this approch is, if our test scripts require I/O interaction, there is no way for us to give I/O feeds to our container.
- other drawback is we can only see if our test script success via the console we use to run `docker-compose up`.
- it sometimes get jumble up with other console output from the devserver.
- we will see something like this.
```
testserver_1  | PASS src/App.test.js
testserver_1  |   ✓ renders learn react link (43 ms)
testserver_1  | 
testserver_1  | --------------------|---------|----------|---------|---------|-------------------
testserver_1  | File                | % Stmts | % Branch | % Funcs | % Lines | Uncovered Line #s 
testserver_1  | --------------------|---------|----------|---------|---------|-------------------
testserver_1  | All files           |    9.09 |        0 |   33.33 |    9.09 |                   
testserver_1  |  App.js             |     100 |      100 |     100 |     100 |                   
testserver_1  |  index.js           |       0 |      100 |     100 |       0 | 7-17              
testserver_1  |  reportWebVitals.js |       0 |        0 |       0 |       0 | 1-8               
testserver_1  | --------------------|---------|----------|---------|---------|-------------------
testserver_1  | Test Suites: 1 passed, 1 total
testserver_1  | Tests:       1 passed, 1 total
testserver_1  | Snapshots:   0 total
testserver_1  | Time:        3.262 s
testserver_1  | Ran all test suites.
testserver_1  | 

```
- but this is as far enough for our simple project.
- for the developer working on this project on their pc, they will use this docker-compose file to start a developer server and test containers on their local machine.
- then when there is no problem with local testing, they will push their code to the github on development branchs (branch other than master or deployment).
- they will create a pull request to merge their branch with master.
- then maybe a senior or manager that are reponsible to verify the code will merge the repo into master.
- then, we will make use of [Travis CI](https://travis-ci.com/), to watch our repositories.
- whenever a new code get merge into the master, travis will be alerted, and then travis will run again the test container online.
- if there is no error, travis will then proceed to deploy it to production server.


# Travis CI for testing
- create a new file in our project folder called `.travis.yml`
- we will make use of travis CI to watch over our github repositories for a commit made by developer.
- travis then will run our test container and if the test is success, we will push it to production.
```yml
sudo: required
services:
    - docker
before_install:
    - docker build -t testserver -f Dockerfile.dev .

script:
    - docker run testserver  npm run test -- --coverage
```
- what travis do, basically, it build an image using Dockerfile.dev 
- then it run the image and overide the startup script to run `npm run test`.
- travis will then wait until the test script end, and will let us know if it is success.

- we are not finished yet editing our travis CI file here.
- we will later continue editing our `.travis.yml` to add deploy options, on how to deploy our production server container.


# Production server container. 
- for our production container, we need our container to run `npm run build`, 
- this will build our react files into a single index.html file with bundles of js files.
- we then take these files, and serves it using http server such as apache or nginx.
- we will create a new `Dockerfile` for our production server.
- we will make use of two base images, our alpine image and nginx image.
- we will implement a multi stage builds to first build our react app, and then take the result build folder into our nginx server.

```Dockerfile
# This is the first (builder) stage wehere we build our project
FROM alpine as builder

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

# build our react project
RUN npm run build

# Second stage start here.
FROM nginx
COPY --from=builder /usr/app/build /usr/share/nginx/html
```
- then we are ready to use this Dockerfile to deploy in our production server.
- we will make use of `heroku` as our production server to deploy our docker container.
- you can use other service such as `AWS elasticbeanstalk` to deploy our docker container.


# Travis CI for Deployment.
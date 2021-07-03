# Dockerfile
- in previous example, we run our docker container via docker-cli
- we make use of other images such as busybox from docker-hub.
- we can actually build our own image.
- we can also use other people images as base image and customize it into our need.
- to do this we use `Dockerfile`, a file named `Dockerfile` without any extension.
- inside `Dockerfile` we define our docker image, we can define volume to be mounted to our images.
- we can run commands to install software.
- and we can specify startup command whenever our image spawn into a container.

# Creating our simple linux image.
- first we need to create a directory for our project.
- then create a new file in it called `Dockerfile`.
- then we need to edit the file.
- inside it, we first need to specify our base image, which is `alpine`
- [alpine](https://hub.docker.com/_/alpine) is a minimal linux image.
- you can use [ubuntu](https://hub.docker.com/_/ubuntu) or busybox if you want.
- then we tell it to update the dependency.
- then we ask it to install `nmap`
- then we specify a startup command.
- our Dockerfile will look like this.
```Dockerfile
# This is a command
#first specify base image
FROM alpine
# update and install nmap
RUN apk update && apk upgrade
RUN apk add --update nmap

# create startup command for our container
CMD ["nmap","scanme.nmap.org"]
```
- this is a simple file, that will create an image based on `alpine`
- install nmap in it and tell it to scan `scanme,nmap.org` when the container start.
- here we use 3 major [instructions](https://docs.docker.com/engine/reference/builder/)
- `FROM` tells docker to refer the base image from `alpine`.
- `RUN` tells docker to run these command inside alpine to build our custom image.
- `CMD` tells docker to make this a startup command.
    - this format `CMD ["command","arg1","args2"]` (this is exec format)
    - or `CMD command arg1 arg2 agr3` (this is shell format)
## Building image.
- after we save the file, we need to build the image.
- using `docker build <project path>`
    - example: `docker build .`
    - we use `.` if we already inside the project directory.
    - if the project directory is in folder named `BasicLinux`
    - we use `docker build BasicLinux/`
- after successfully build, it will output our image id
```
Successfully built 3655b4723426
```
- we can then copy it and run it using `docker run`.
```bash
$sudo docker run --rm -it 3655b4723426
```
- and we will see the result
```
Starting Nmap 7.91 ( https://nmap.org ) at 2021-06-18 09:26 UTC
Nmap scan report for scanme.nmap.org (45.33.32.156)
Host is up (0.30s latency).
Other addresses for scanme.nmap.org (not scanned): 2600:3c01::f03c:91ff:fe18:bb2f
Not shown: 996 closed ports
PORT      STATE SERVICE
22/tcp    open  ssh
80/tcp    open  http
9929/tcp  open  nping-echo
31337/tcp open  Elite

Nmap done: 1 IP address (1 host up) scanned in 21.47 seconds
```
- we just successfully created a simple linux image with `nmap` installed in it.

## Giving name to our image.
- we can give name to our iamge by using `-t` or `--tag` flags when building our image using `docker build`.
- example 
```bash
$sudo docker build -t nmapnux BasicLinux/
```
- here we give our image a name `nmapnux`.

## Using ENTRYPOINT and CMD
- here in our image, when we run it will only scan for `scanme.nmap.org`
- we can change this behaviour so that we can specify which hostname to scan.
- to do this we use `ENTRYPOINT` and `CMD` instructions.
- we use `ENTRYPOINT` to specify that `nmap` is the command that going to be run upon startup and we use `CMD` to specify the arguments for our entrypoints.
- our `Dockerfile` will look like this.
```Dockerfile
# This is a command
#first specify base image
FROM alpine
# update and install nmap
RUN apk update && apk upgrade
RUN apk add --update nmap

# create startup command for our container
ENTRYPOINT ["nmap","-v"] 
CMD ["scanme.nmap.org"]
```
- here by dafault when we run `docker run nmapnux` it will scan for scanme.nmap.org.
- but we can overide the default startup command like we previously learn using `docker run <image> <command>`.
- so to overide the argument we can run it like this
```bash
$sudo docker run --rm -ti nmapnux cs.usm.my
```
- here it will run our container with cs.usm.my as the overide arguments for nmap.


## Generate Images out of Container
- let say we have our nmap container running.
- then get into the shell command, and make changes to the container.
- let say we want to change the default of nmap scan from scanme.nmap.org to cs.usm.my
- here we can save our changes as a snapshot into a new images.
- to do this we use : `docker commit`.
```bash
docker commit -C 'CMD ["cs.usm.my"]' <containerid or tag>
```
- then we can run it using the newly created image id.
- note that using docker cli command is bad practice.
- always use dockerfile to setup an images.
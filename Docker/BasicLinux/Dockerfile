# This is a command
#first specify base image
FROM alpine
# update and install nmap
RUN apk update && apk upgrade
RUN apk add --update nmap

# create startup command for our container
# CMD ["nmap","scanme.nmap.org"]
ENTRYPOINT ["nmap", "-v"] 
CMD ["scanme.nmap.org"]
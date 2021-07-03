FROM alpine

#setting up our volume.
# copy from our current directory into our container.
WORKDIR /usr/app
COPY ./ /usr/app

#install dependencies.
RUN apk update && apk upgrade
RUN apk add --update npm
RUN apk add --update nodejs

# install node dependencies.
RUN npm install

# on container start
CMD ["npm","start"]
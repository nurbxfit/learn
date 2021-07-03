FROM alpine

# install software dependencies
RUN apk update && apk upgrade
RUN apk add --update npm
RUN apk add --update nodejs

# setup work dir
WORKDIR /usr/app

# if we made change to package.json, using cache ends here.
# copy package.json into work dir
COPY ./package.json ./

# install node dependencies.
RUN npm install

# if we made change to source file, using cache ends here.
# COPY the rest of files in our host project directory.
COPY ./ ./ 

# RUN OUR WEBSERVER
CMD ["npm","start"]
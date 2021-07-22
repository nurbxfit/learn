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
EXPOSE 80
COPY --from=builder /usr/app/build /usr/share/nginx/html
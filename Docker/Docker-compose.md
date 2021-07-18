# Desclaimer
- this example is based Stephen Grider Udemy Courses on Docker.
- this is just my note taking based on his course.


# Docker Compose.
- in dockerfile example.
- we create an image from a configuration file.
- and run a container out of it using `docker run`.
- we can spawn multiple container based on multiple images as we want.
- let say we want to create a simple webapp with a database.
- one way to do this is to install both the webapps (nodejs or nginx) and the database within the same container.
- or alternatively we can spawn a webserver container and a database container sperately.
- these two container will then need a way to communicate with each other.
- doing this on a command line, can be quite troublesome.
- there is where Docker compose come to help.
- we can create a configuration file to spawn multiple container using docker-compose.
 
 # Setting up our project.
 - we use the `nodejsapp` project as our base project.
 - we simply copy it into another project directory.
 - we will add new file under `views` folder called `index.ejs`
 - then we edit the `index.js` and `package.json` files to add redis to our project.
 - we use redis as our example database.

 ```json
 //package.json
{
    "dependencies": {
        "express":"*",
        "redis":"2.8.0"
    },
    "scripts": {
        "start": "node index.js"
    }
}
 ```
 - next is our index js file
 ```js
 //index.js
const express = require('express');
const redis = require('redis');
const path = require('path');

const app = express();
const client =  redis.createClient({
    host: 'redis-server',
    port: 6379
});

//init redis db
client.set('name',"");

//set our view engine
app.set('view engine','ejs');
app.set('views','views');

//set body parse to parse request body.
app.use(express.urlencoded({extended:false}));
app.use(express.static(path.join(__dirname,'public')));

//ROUTES
app.get("/",(req,res)=>{
    //get from redis
    client.get('name',(err,name)=>{
        if(err) return res.status(500).send("Something Bad Happened");
        res.status(200).render('index',{key:name});
    })
});

app.post("/submit",(req,res)=>{
    const {keyword} = req.body;
    
    //store in redis
    client.set('name',name);
    res.redirect('/');

})

const PORT = 5000 || process.env.PORT
app.listen(PORT,()=>{
    console.log(`Server listening on http://localhost:${PORT}/`)
})
 ```
 - our index.ejs file, is just a simple html with an input form.
 ```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Node Redis Example</title>
</head>
<body>
    <header>
        <div>
            <h1>Hello Docker</h1>
        </div>
    </header>
    <section>
        Keyword: <%= key %>
    </section>
    <main>
        <form action="submit" method="POST">
            <label for="keyword">Enter a name:</label>
            <input type="text" id="keyword" name="keyword" >
            <button type="submit">submit</button>
        </form>
    </main>
</body>
</html>
 ```

 - we can now build our images.
 - if we try to run our container, we will get an error as there is no redis server for our webapp to connect.
 - we can start a redis container, but that container have no way of communicating with our werbapp.
 - we can run the container and map the port to our host.
 - it can be troublesome to perform all these setup using docker-cli.
 - people mostly don't use docker-cli in production enviroment.
 - we can do all those setup in our `docker-compose.yml` file.
 - then we simply use `docker-compose` command to run a single `docker-compose.yml` file.

 # OUR docker-compose.yml example.
 ```yml
version: '3'

services: 
    redis-server:
        image: 'redis'

    web-app:
        build: .
        ports:
            - "5000:5000"
 ```
 - here the `version:'3'`, indicating that we are using docker-compose version 3.
 - the services is where we write all our container that we want to run.
 - here `redis-server` is the container name for our redis server.
 - that container use `redis` default image that will be pulled from the docker-hub.
 - below it `web-app` is name of our nodejs application.
 - here we use `build: .` command tu run docker build in our current working directory.
 - so it will refer our previously made `Dockerfile` to build our image.
 - the `ports` is where we map our host port to the container ports.
 - because we only accessing the webapp from our host. we are not specifying the ports configuration for `redis-server`.
 - but you might be wondering how do we connect our `redis-server` with our `web-app` ??
 - when we create our container from docker-compose. docker will automatically create a single docker network with our defined container connected to it.
 - so by default our `web-app` are able to connect to our redis-server on port `6379`. 
 - docker will create a DNS mapping of our redis-server container to a hostname `redis-server`.
 - noticed that in our `index.js` file, we specify the connection host as `redis-server`. 


# Running our containers.
- make sure docker-compose are installed in your system.
- refer [here](https://docs.docker.com/compose/install/) to install.
- for fedora, you can simply use 
```bash
$sudo dnf install docker-compose
```
- to run our container, we can use `docker-compose up`.
- to run our container and also build docker image use `docker-compose up --build`.
- to run in background we use `-d` option.
```bash
$sudo docker-compose --build -d
```

# Stoping our containers.
- we can list running containers using `docker ps`
- to stop all of our containers, we can use `docker-compose down`.
- we run `docker-compose down` in our docker project folder that contains our `docker-compose.yml` file.

# Auto Restart Container
- if let say there is an error in our code, 
and our service stop itself and return exit code.
- we can add a restart policies in our `docker-compose.yml` file,
to tells docker to auto restart the container.
- example restart policies:
    - `"no"`: never restart container (don't forget double quotes).
    - `always`: always attempt to restart, no matters the reason.
    - `on-failure`: restart if stop due to failure or error.
    - `unless-stopped` : always restart unless, the dev forcibly stop it.

- we use it by adding `restart` in our yml file.
```yml
# docker-compose.yml
version: '3'

services: 
    redis-server:
        image: 'redis'

    web-app:
        restart: always #here we add restart policies.
        build: .
        ports:
            - "5000:5000"
```

# Checking the status of our running container.
- when we start our container using `docker-compose up -d`
- we can check the status of our container using `docker-compose ps`
- note that we must run that command in the directory containing the `docker-compose.yml` file.
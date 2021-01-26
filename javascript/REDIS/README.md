# REDIS
- redis is a caching server.


## Installing redis server.
1. Ubuntu based system.
    - `sudo apt update`
    - `sudo apt install redis`
    - `sudo systemctl start redis`
    - `redis-cli ping`

2. Centos/RHEAL based system
    - [Digital Ocean Reference](https://www.digitalocean.com/community/tutorials/how-to-install-secure-redis-centos-7)
    - `sudo yum install epel-release`
    - `sudo yum install redis -y`
    - `systemctl start redis.service`
    - `redis-cli ping`

- after running `redis-cli ping` you will get `PONG` in return from the server

## Connecting Javascript project to redis.
- to connect our javascript to redis, we use [redis](https://www.npmjs.com/package/redis) node module.
- install redis using: `npm install redis`.
- then you can require the module using: `const redis = require('redis')`
- default redis url for redis server in localhost : `redis://127.0.0.1:6379`
- example code to create connection to server. 
``` js 
    const redis  = require('redis');
    const redisUrl = 'redis://127.0.0.1:6379'; 
    const client = redis.createClient(redisUrl);
```

## Storing and Getting Data to Redis
- redis store data in form of `(key,value)` index.
- to store data in redis, we use the `set` method from the `redis` node module.
- example code.
    ``` js
    client.set('myKey','myValue',myCallback);
    ```
- to get date from redis, we use `get` method by giving the `key` as the parameter
- example code.
``` js
    client.get('myKey',myCallback)
```
- the callback for `get` method returns two value, `error` and `value` of the key.
- so let say we simply want to print the value.
``` js
    //this will print the value 'myValue` we previously set.
    client.get('myKey',(error,value)=>console.log(value)); 
```
- noticed that we are require to pass a callback in order to receive data from server, because this is an asynchronous operation.
- if you don't want to use callback and instead want to use `promise`, we can make use of `promisify` to convert our function into returning a promise.

```js
    const {promisify} = require('util');
    const getAsync = promisify(client.get).bind(client);    
```
- `getAsync` is now our new function that will return a promise
- we can use it with `await` or using `then`
- example using await.
``` js
    //make sure this code run in async function
    try{
        const value = await getAsync('myKey');
        console.log(value);
    }catch(error){
        console.error(error)
    }
```
- example using `.then`
``` js
    getAsync('myKey').then(console.log).catch(console.error)
```
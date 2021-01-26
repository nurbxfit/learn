
# HTTP Basic.
- HTTP => `Hypertext` Transfer Protocol
- `Hypertext` means text contains link to the recourses.
- HTTP is an application layer protocol (Based on OSI model, it is in the 7th layer).
- application layer protocol usually handled by user application such as web browser.
- Application layer software is also know as `User Agent`
- this `User Agent` is the client that send the request to server.
- The HTTP communication, requires two entities, (Client & Server).
- sometimes the communication may involve other entities such as `Proxy`.
- A client `==Send Request=>` Server.
- A Server `==Send Response=>` Client.
- Default Port for HTTP is : 80. though configurable to other unassigned port.
- HTTP request is stateless, means that each request issued are seperated and have not link with another.
- to make HTTP request statefull, `cookies` are used and stored in the browser.

- A resource in a server is published and accessable via a URL (Uniform Resource Locator).
- the structure of an URL consisted of, following items
    - Protocol Schema   : eg => `HTTP`, `HTTPS`, `FTP`, `mongodb`, `mysql`
    - User Info         : user authentication eg => `myusername:mypassword`, this is optional
    - Host              : host address, can be a domain name or  IP addresses.
    - Port              : the service port number 
    - path              : path or namespace sperated by `/` where recourse are stored or just the file item itself eg: => `mymusic/hello.mp3`
    - query string      : one or many `key=value` pair sperated by `&` passed to the path, to provide extra information to the resource 
    - fragment          : a fragment location of an HTML page.
- example URL 
    - ``https://cs.usm.my/index.php/search-v2?searchword=example&searchphrase=all``
        - in above example.
        - `https` is the protocol
        - `cs.usm.my` is the hostname
        - `index.php/search-v2` is the path
        - `searchword=example` is the query where `searchword` is the key and `example` is the value.
        - `searchphrase=all` is another query

    - ``mongodb://localhost:27017/?readPreference=primary&appname=MongoDB%20Compass&ssl=false``
        - this is another example for mongodb connection url.
        - `mongodb` is the protocol
        - `localhost` is the host
        - `27017` is the port number
        - `/` is the path
        - `readPreference=primary&appname=MongoDB%20Compass&ssl=false` is the query string

## Making a Request.
- when we make a request to a website using our browser.
- the browser will read the url and parsed the URL.
- the process involve are.
    - its get the host from the url. in case of `exampleweb.com`
    - it will first make a request to a DNS server to get the IP address of `exampleweb.com` 
    - gathered that ip address it will then create a connection to the server on the `http` port `80`
    - after successfully create connection, it then send a HTTP request.
    - the server then reply to that request.

- you can try making a request to a server using netcat
    - by issuing this command in terminal` nc 202.170.57.170 80 `
    - you will get a blank promp that you can issue the get request.
    - example is : `GET /index.php HTTP/1.1`  
    - by typing this, you are issuing HTTP `GET` request to a path `/index.php` using HTTP version 1.1.
    - then you will get the response from the server. probably a bad request message.

- below is another example of GET REQUEST with a HTTP HEADERS, issued by the browser.
- `GET / HTTP/1.1` is the GET request, and below it is the HEADERS included with the request.   
```
GET / HTTP/1.1
Host: 159.65.92.160:31372
User-Agent: Mozilla/5.0 (Windows NT 10.0; rv:68.0) Gecko/20100101 Firefox/68.0
Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8
Accept-Language: en-US,en;q=0.5
Accept-Encoding: gzip, deflate
DNT: 1
Connection: close
Upgrade-Insecure-Requests: 1
```
- List of HTTP request method, more info refer to [ Mozilla Developer website ](https://developer.mozilla.org/en-US/docs/Web/HTTP/Methods)
    - `GET`
    - `POST`
    - `HEAD`
    - `PUT`
    - `PATCH`
    - `DELETE`
    - `OPTIONS`
    - `CONNECT`
    - `TRACE`

## HTTP Headers
- headers let us transfer addition info between client and server.
- headers are sent together with the HTTP request.

- header format is in a key value format. 
    - example header
    ```
    Host: 159.65.92.160:31372
    User-Agent: Mozilla/5.0 (Windows NT 10.0; rv:68.0) Gecko/20100101 Firefox/68.0
    Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8
    Accept-Language: en-US,en;q=0.5
    Accept-Encoding: gzip, deflate
    DNT: 1
    Date: Sun, 3 Mac 2020 01:01:20 GMT
    Connection : keep-alive
    ```
    - from the example above, left is the key/field sperated by `:` and the right side is the value.
    - the field name  and value follows the [HTTP protocol standard](https://www.w3.org/Protocols/rfc2616/rfc2616-sec4.html)
- there are multiple categories of header.
    - General Headers
    - Entity Headers
    - Request Headers
    - Response Headers
    - Security Headers

1. General Headers
    - A general header can both be use in Request and Response message.
    - Apply only to the message being transmitted.
    - example field is.
        - Cache-Control 
        - Connection
        - Date
        - Pragma
        - Trailer
        - Transfer-Encoding
        - Upgrade
        - Via
        - Warning

2. Entity Headers
    - this header is also like General Header which can be use both for request and response.
    - but specific to describe the `Entity` content of the request.
    - like uploading a pdf file, this header help recognize the type of item get transsfer in the message.
    - basically describe the item(Entity) being trasmmitted.
    - example use of `Media-Type` field to describe an `pdf` file is being transmitted.
    ```
    Media-Type : application/pdf
    ```
    - example of common field is. refer to [Mozilla website](https://developer.mozilla.org/en-US/docs/Web/HTTP/Headers/Content-Type) for more
        - Content-Type
        - Media-Type   
        - Boundry
        - Content-Length
        - Content-Encoding

3. Request Headers

4. Response Headers

5. Security Headers


## HTTPS Flow


## Cookies
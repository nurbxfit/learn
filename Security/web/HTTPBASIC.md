
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
    - a program can define their own custom headers, but advisable to follow the protocol standard 
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
    - Request Headers are specificly related to the http request made by the client.
    - unlike `Entity` header, this header have nothing to do with the content of the message.
    - instead, it is used to provide extra information about the client for the server to handle and manipulate.
    - as example the `Referer` field that is used to tell the server that this request come from somewhere.
    - or the `cookie` field that contains cookies value pair information for the server to process.
    - example of common Request field is.
        - Host
        - User-Agent
        - Accept
        - Cookie
        - Referer
        - Authorization
        - Origin

    - example Request Headers
    ```
    GET / HTTP/1.1
    Host: drug.cs.usm.my
    Connection: keep-alive
    Cache-Control: max-age=0
    Upgrade-Insecure-Requests: 1
    User-Agent: Mozilla/5.0 (Linux; Android 6.0; Nexus 5 Build/MRA58N) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/88.0.4324.96 Mobile Safari/537.36
    Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9
    Accept-Encoding: gzip, deflate
    Accept-Language: en-GB,en;q=0.9,en-US;q=0.8,ms;q=0.7
    ```

    - the `Host` field is used to specify the host that the request trying to query.
    in case of a single server having a multiple web service running on different domain name.
    - the `Accept` field is used to tell server, which media format the client can support. eg: a html `text/html`
    - `User-Agent` field describe the information about the client such as the Browser version, the operatin system etc ...

4. Response Headers
    - Response headers are use by the server response to provide extra information to the client.
    - example of response message from [Mozilla Developer website](https://developer.mozilla.org/en-US/docs/Glossary/Response_header)
    ```
    200 OK
    Access-Control-Allow-Origin: *
    Connection: Keep-Alive
    Content-Encoding: gzip
    Content-Type: text/html; charset=utf-8
    Date: Mon, 18 Jul 2016 16:06:00 GMT
    Etag: "c561c68d0ba92bbeb8b0f612a9199f722e3a621a"
    Keep-Alive: timeout=5, max=997
    Last-Modified: Mon, 18 Jul 2016 02:36:04 GMT
    Server: Apache
    Set-Cookie: mykey=myvalue; expires=Mon, 17-Jul-2017 16:06:00 GMT; Max-Age=31449600; Path=/; secure
    Transfer-Encoding: chunked
    Vary: Cookie, Accept-Encoding
    X-Backend-Server: developer2.webapp.scl3.mozilla.com
    X-Cache-Info: not cacheable; meta data too large
    X-kuma-revision: 1085259
    x-frame-options: DENY
    ```

    - `200 OK` is the status code for our request, in this case is 200 OK , our request is successfull.
    - more information on refer to [status code](https://developer.mozilla.org/en-US/docs/Web/HTTP/Status)
    - `Access-Control-Allow-Origin:*`, `Server:Apache`, `Set-Cookie` is the example of Response field.
    - other field such as `Content-Type`,`Content-Encoding` is the `Entity` Header.

5. Security Headers
    - resource on [Security Header](https://owasp.org/www-project-secure-headers/)
    - example of common security header
        - Content-Security-Policy
        - Strict-Transport-Security
        - Referrer-Policy
    

## HTTPS Flow


## Cookies

## Basic Authentication
- Basic Authentication is the simplest form of authentication in HTTP GET request.
- it usually will prompt a form like an alert asking for username and password.
- we can see that if a webpage require an authentication for us to see it, it will issue a `WWW-Authenticate` field in the header to the client.
- The client then need to specify the `Authorization` field in its request header to authenticate with the server.
    - Basic Authentication usually issued like this by the server.
        ```
        WWW-Authenticate: Basic realm="Restrcted Content"
        ```
    - The client then will issue a `Authorization` header to authenticate with the server.
        ```
        Authorization : Basic YWRtawskdljalskjdFSfg2cmQ=
        ```
    - the random string after the `Basic` keyword is the based64 encoded username and password that we entered to authenticate with the server.

    - Other then `Basic` there are other form for authorization such as `Bearer`, `Digest`, `OAuth`, `API Key` etc ...
    - `Digest` use MD5 hashing to transfer our username and password instead of unsecurely encode it using base64
    - `Digest` is still unsecure as md5 hash algorithm can still be attack.

- In a Browser, we can specify the Basic authentication either by filling the prompted username and password field or directly issued it in the URL.
- previously we learned that we can provide user in a url.
- example: `http://admin:password@localhost:4444/`.
- we can create a simple brute force script using curl by just simply looping and replacing the username and password in the request URL.

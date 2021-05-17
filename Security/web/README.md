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

## IMPORTAN SECURITY NOTE.

- for a web developer, it is important to make sure that there is no sensitive information get send to the front-end client because those information are publicly available to the client to view.
- we should never perform password checking or storing API keys in a client side code.
- a vulnerability in front end usually does't directly effecting the back end server permanently as it just happen in the client browser and get reset whenever client re-render the webpage.
- but it can sometimes cause problem to the end user that are using the website.

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

### In case of Code Injection.

- inject code to the server

### In case of SQL Injection.

-

### In case of Command Injection.

-

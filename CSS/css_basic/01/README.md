# 3 ways to add css.

1. Inline styling (style attributes in html tags).

```html
<section style="background:blue">
  <h1>Hello World</h1>
</section>
```

- color attributes can be their name (eg:'blue'), hex( eg: #ffff ) code or rgba( eg: `rgba(255,0,0,0.3)` ) values.

2. style tags inside html

```html
<head>
  <style>
    /* background value applied to all occurence of section tags.  
        to make it specific we can focus using selector such as class or id.
        */
    section {
      background: blue;
    }
  </style>
</head>
```

3. external stylesheet (Recomended)

- create new file for our css and reference it using link tags in html.

```css
/* inside styles.css file*/
section {
  background: blue;
}
```

```html
<!---inside html file-->
<head>
  <link rel="stylesheet" href="./styles.css" />
</head>
```

- advantages of using external stylesheet is that.
  - browser can cache the css file.
  - reduce the size of our html file.
  - improve page load time.
  - avoid cluttering our html file with many css.

# tricks (font).

- to install custom font for our css, we can use font online such as `google fonts` and using the `link` tag to add it to our html.
- eg".

```html
<head>
  <link rel="preconnect" href="https://fonts.gstatic.com" />
  <link
    href="https://fonts.googleapis.com/css2?family=Ubuntu&display=swap"
    rel="stylesheet"
  />
  <link rel="stylesheet" href="./styles.css" />
</head>
```

- alternatively we can use `@import` statment in our css file or in css tags inside html.

```css
@import url("https://fonts.googleapis.com/css2?family=Ubuntu&display=swap");
```

- below is example of styles.css file.

```css
@import url("https://fonts.googleapis.com/css2?family=Ubuntu&display=swap");
section {
  background: aqua;
}

h1 {
  color: white;
  font-family: "Ubuntu", sans-serif;
}
```

# Selectors

- Selectors are devided into `Elements`, `class`, `unique`,`Attributes` and `universal` selectors.
- `Elements` selectors is our html tags/element.
  - in html we have tags such as, `h1`, `head`, `p` etc ... and when used in our html, we consider it as the element of the html.
  - element selector will apply styling to the all occurence of the element.
  - example of element selector inside of styles.css.
  ```css
  /* this will apply to all h1 element in our webpage
   not effecting h2 or other element. unless it is a parent element such as div.
  */
  h1 {
    color: white;
    font-family: "Anton", sans-serif;
  }
  ```
- `Class` selector is a defined set of attributes that can be applied to multiple elements.
  - multiple elements that is member of the same class will get applied to the same styling.
  ```css
  /* example of classname redText in styles.css
   class selector denoted with dot (.) and followed with the classname 
  */
  .redText {
    color: red;
  }
  ```
  - any elements that are members of the class `redText` will applied that styling.
  ```html
  <!--example index.html-->
  <body>
    <main>
      <section>
        <!-- this specific h1 is red-->
        <h1 class="redText">Hello World</h1>
      </section>
      <section>
        <!-- this specific p is also red-->
        <p class="redText">Hello This is a css example</p>
      </section>
    </main>
  </body>
  ```
  ### notes:
  - css is case insensitive, so be alert when naming the class name.
- `Unique` or `Id` selector is only uniquely applied to element matching the specific id.
  - because it's match to an unique Id thus it is considered unique.
  ```css
  /* example of id selector in styles.css
  ID selector denoted with hashtag (#) and followed with the unique name 
  */
  #myUniqueH1 {
    color: red;
  }
  ```
  - any elements that are members of the class `redText` will applied that styling.
  ```html
  <!--example index.html-->
  <body>
    <main>
      <section>
        <!-- this specific h1 is red-->
        <h1 id="myUniqueH1">Hello World</h1>
      </section>
      <section>
        <!-- this h1 will not turn red-->
        <h1>Hello This is a css example</h1>
      </section>
    </main>
  </body>
  ```
- `Attributes` selector, set styling to all elements that match the attributes we selecting.

  - we select an element by specifying the attributes in [ square bracket ]

  ```html
  <!--example of disabled attribute for button elements in html-->
  <button disabled>click me</button>
  <p title="tooltip">hover over me</p>
  ```

  ```css
  /* example selecting disabled attributes in css
          every disabled button will have color grey as the font color.
      */
  [disabled] {
    color: grey;
  }

  /*this select element with title=tooltip as its attribute and assign color green to that element font.
      */
  [title="tooltip"] {
    color: green;
  }
  ```

- `Universal` selector, applied the css attribute to all element in our html.
  - example of it is by using asterisk `*`.
  ```css
  /* example declaration of universal selector*/
  * {
    color: black;
  }
  ```

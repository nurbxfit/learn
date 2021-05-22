## Box Model

![boxmodel](./images/boxmodel.png)

- box model look like this, each element in html have this basic properties
  - margin: indicate space between element with another element.
  - border: simply the border of our box.
  - padding: the space between the border and element within our element.
- our body element by default have a margin given by the browser.
- to make our body to be fullscreen (not showing white spaces)
- we can disable default margin using.

```css
body {
  margin: 0;
}
```

- by default elements will usually have default margin set by the browser

## shothands

```
/*
padding is like margin
order are important
becase value of same type
*/
margin: [top][right][bottom][left]
margin: [top & bottom][left & right];
margin: [all]

/*
here order doesn't matter
in case of properties that don't have the same value type
*/
border: [size][style][color]
or
border: [size][color][style]
```

## Height and Width

- block element by default have width of `100%` or full width but not for the height.
- the height by default computed dynamically by the browser
  - it influenced by the content/child it had.
  - if the content is bigger, our element will get bigger
- if we use `height:100%`, we usually will see nothing change (it's depends).
- because height=100% depends on height of it's parent element.

  - if the parent element dynamically computed the height that is small (as the content/child it had doesn't consume much space).
  - then our element height:100% simply means consumed the available heigh of the parent.
  - to make `height:100%` works, we can change the height of the parent element by specifying it ourself. intstead or letting the browser to computed it dynamically.
  - if we set height of parent to `500px` our element with `height:100%` will take the full `500px` height.

- by default, when we add height and width, the browser will apply the sizing including the border,padding.

```css
.my-box {
  width: 100%;
  height: 500px;
  padding: 10px;
  border: 5px solid black;
  margin: 10px;
}
```

- our actual height rendered by browser will be `500px`+ `2x10px` + `2x5px` = `530px`.

- this is because by default box-sizing property is set to `content-box`

```css
box-sizing: content-box;

/*
this means when set the the width and height,
we are actualy set the width and height of the content.
not including the border and sizing.
thus browser at the end will add together border and padding to create actual size rendered to screen.
*/
```

- to disable it we can set it to `border-box`

```css
box-sizing: border-box;
/*
here we are telling the browser that the height/widht that we specifying already included the size of border and padding into our calculation.
*/
```

- by doing this our final height will be `500px` as we stated in our styling.

## Display properties.

- `block` element, span accross the width, next element will be below it
- `inline` element doesn't have margin top/bottom, it not span accross width.
  - next element will be next to it.
- `inline-block` mix inline and block which enable margin/padding top and bottom.
  - this will make block element to sit next to each other, but will have block properties.

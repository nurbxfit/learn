[Best Reference](https://developer.mozilla.org/en-US/docs/Web/CSS/position)
# Positioning.

- we can change actual position of element in our website.
- using `top`,`bottom`,`right`, `left`. 
- and using `position` these property to specify the reference.
    - `fixed`
    - `relative`
    - `absolute`
    - `sticky`.

- we use the `position` property in the element that we are going to move it position.


# Static positioning (default).
- will follow default html flow.
- we can't really change position much here.
- so `top`,`bottom`,`right`, `left` have no effect

# fixed position.
- usign this value will take out our element from the html flow.
- look like it's floating but in fixed position above our page if we scroll.
- here we can specify the `top`,`bottom`,`right`, `left` position to move it around and it will fixed to that coordinate.
- it will refer the viewport (our browser).

# Absolute position.
- usign this value will take out our element from the html flow.
- different that fixed, this will make our element float near its parent or ancestor element that have a `position` property. 
- if no ancestor with `position` property, it will position itselt relative to the viewport or html.
- this will create a problem, if we try to position our element relative to a parent, by adding `position:absolute` to the parent.
- the parent itself will be of absolute position and get out of html flow.
- to fix this problem, we can set our parent element with `position:relative`.

# Relative position 
- here, the element are not taken out of the html flow.
- instead it position according to the flow of the html, but
- can ofset itseft using the `top`,`bottom`,`right`, `left`.
- it refer its own initial position in the flow and move itself around.

# sticky position
- a combination of relative and fix.
- when we set the `top`,`bottom`,`right`, `left`.
- it will create a position for our element from the viewport.
- when we move (like scrolling) and our element reach that position.
- it will change it behaviour like a fixed position.
- it will then float itselt.
- people usuly used this behaviour to create a navbar, that appear static/relative at first, and then float when user scroll thru the page.
- it stop being sticky or fixed when it reach the end of its parent element.
- `Sticky` doesn't work if the parent have `overflow` property in it
- such as 
    1. `overflow: hidden`
    2. `overflow: scroll`
    3. `overflow: auto`
- not all browser support sticky. 

# stacking element.
- when we use the position property.
- and the element overlapped with each other.
- the stacking of the element follow the position of the lement in the html flow.
- if element1 come first in the html flow, it will be at the bottom.
- if the element 4 come last, it will be at the top.
- we can change the stacking order by changing the z-index value.

# z-index
- by default all element have an index of 0.
- to make element on top of other, use positive or bigger value.
- to make element below of other, use negative or smaller value.


# overflow: hidden, will hide element that are outside of the parent.
- let say 
```html
<div id="parent" style="overflow:hidden; height:20px;">
    <p> hello </p>
    <p> some realy random long text..............</p>
<div>
```
- the long text will be hidden if it the text overflow outside of the parent.
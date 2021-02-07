## ES (ECMA Script).
- there are many version of it from version 1 until currently v11 in year 2020 from what I read in wikipedia.
- sometimes you might see something like this:
    - ES5
    - ES6
    - ES7
    - ES8
    - ES2015
    - ECMAScript2016
- what is it ?
    - it is a coding standard or specification for Javascript implementation.
    - it is a javascript standard that make sure our javascript are compatible to be run across web browsers.
    - Make sure that everyone follow the same specification.
    - ECMA is basically a standard that other vendor follow when implementing their own version of ECMA based script.
    - we can say that JavaScript that we use in our browser follow the specification of ECMA Script standard.
    - we can also make our own scripting language that are based on ECMA, by following the [ECMA Specification](https://www.ecma-international.org/publications-and-standards/standards/ecma-262/).

- Other than JavaScript there are also other languages that implement ECMA specification as their core such as ActionScript and JScript.

- most browser are supporting ES1 up to ES5 with some up to ES6 standard as their core implementation.
- but for convenient, programmers can make used of other ES version to write their code. but to make sure their code able to be run in browser, the code need to be compiled into ES5 using library such as [Babel](https://babeljs.io/).

## ES6 also known as ES2015
### Declaring Variables.
- First we need to understand something about scope.
- there are two common scope in javascript right now which are **block scope** and **function scope**.
- A block in javascript is enclosed in the curly bracket `{` this my bllock `}`
- In language like c++ or Java, when we declare variable in a block scope.
- those variable are only accessable in the scope it was declared.
- if we try to access the variable outside of the block scope it will throw an error.
- when we declare a variable in a block, those variable aren't accessable outside of that scope. 
- But if we declare a variable outside of that block, those variable are accessable inside of the block. if the block is nested.
- example C++ code.
```cpp
int main(){
    int a=10,b=5;
    if(a<15){
        //this is a new block scope
        int x = 10;
        cout << b << endl; // we can print this.
    }
    cout << x << endl; // we cannot print this. compilation will cause error.
    return 0;
}
```
- but this is not the case for javascript prior to ES6.
- in previous version of javascript, we declared most of our variable using the `var` keyword.
- we have no block scope, only the function scope. 
- everything declared with `var` in a block, will be accessable outside of that scope.
- the same code but in javascript declare with `var` will look like this.

```js
    function main(){
        var a = 10;
        var b = 5;
        if( a < 15){
            var x = 10;
            console.log(b); // we can print this
        }
        console.log(x); //this will not caused any error.
    }
```
- same as when we are looping.
```js
    function one(){
        for(var x = 0; x < 5 ; x++){
            // here is a new block scope because enclosed in { }.
            console.log(x)
        }
        console.log('X is:',x); // we can access it.
    }
```
-  here is function scope example.
```js
    function one(){
        var a = 420;
        console.log(b); // b is not accessable by one.

        function two(){
            var b = 69; 
            console.log(a) // a is accessable by two.
        }
    }
```
- the drawback of using var is that, if in our javascript file included in html, we declare a variable using var, outside of any function code, that variable will be considered as a global variable. because there is no function scope that will limit it.
- another stupid example of using var is when we nested looping using same variable name.
```js
    function doubleloop (){
        for(var i = 0; i < 10; i++){
            console.log('inside:',i); // this will only run once.

            for(var i = 0; i < 20; i ++){ //because we declare the same variable here.
                console.log('i:',i);
            }
        }
    }
```
- Bad thing about `var` is that it can cause lot of bugs. that is why in ES6, we were introduced with `let` and `const` as a new way to declared a variable.

- the `let` and `const` keyword enable the use of `block` scope variable.
- the different between `let` and `const` is that, `const` declared a variable as a constant, and not mutatable after declared.

- example of using let block scope variable.
```js
    function main(){
        var a = 10;
        let b = 5;
        if( a < 15){
            let x = 10; // here we use let in our block
            console.log(b); // we can print this
        }
        console.log(x); //this is an error.
    }
```

- with `const` we can achieved the same `block` scope variable.
- but our variable is constant and we can't mutate it.
- but if we declared an object or array with `const`,
- we can still change the value inside of the array or object. but we can't change the variable.
- example.
```js
    function main(){
        const a = 10;
        const b = [1,2,3];
        const c = {x:5};

        a = a+2;        // this is not ok.

        b[1] = 4;       // this is ok.
        b = [3,4,5];    // this is not ok.
        b.push(5);      // this is ok.
        b[4] = 10;      // this is ok.

        c.x = 10;       // this is ok.
        c.b = 69;       // this is ok.
        c = {}          // this is not ok.
        c = {a:'10'}    // this is not ok.

        console.log(`a:${a}\nb:${b}\nc:${c}`)
    }
```

### extra unrelated Info.
- Each `file.js` inside a node.js program, will be invisibly enclosed in a function.

- example when we create a file called `index.js` like this.
```js
    //index.js file
    var express = require('express');
    var a = {}
    console.log('Hello World');

    module.exports = a;
```
- and run it using **node index.js**
- our **index.js** is actually enclosed inside a function that look something like this.
```js
function(exports,require,module,__filename,__dirname){
    //index.js file
    var express = require('express');
    var a = {}
    console.log('Hello World');

    module.exports = a;
}
```
- this is why if you are familiar with node.js you can use the module system to `module.exports` and `require` file. because we have the `module.exports`, `require` passed as parameter to our index.js file by the node program.


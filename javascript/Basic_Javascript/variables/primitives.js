/*
    Javascript primitive types
    - Number => 10 , -13 , 12.0
    - String => '10', 'hello world'
    - Boolean => true, false
    - Null 
    - Undefined

    #Number
    10000000000
    > x = 100000000000
    100000000000
    > x = 1000000000000
    1000000000000
    > x = 10000000000000
    10000000000000
    > x = 100000000000000
    100000000000000
    > x = 1000000000000000
    1000000000000000
    > x = 10000000000000000
    10000000000000000
    > x = 100000000000000000
    100000000000000000
    > x = 1000000000000000000
    1000000000000000000
    > x = 10000000000000000000
    10000000000000000000
    > x = 100000000000000000000
    100000000000000000000
    > 
    > x = 1000000000000000000000
    1e+21
    > x = 10000000000000000000000
    1e+22
    > x = 100000000000000000000000
    1e+23
    > x = 1000000000000000000000000
    1e+24
    > x = 10000000000000000000000000
    1e+25

    # Basic Number Operation
        Addition
        1 + 1
        
        Subtraction
        1 - 1

        Multiplication 
        4 * 1

        Division
        4 / 2

        Modulo (return a remainder)
        3 % 2  //1 

        Exponential
        2**3  // means 2 power of 3 

        NaN ( Not a Number)
        0/0 // NaN
        1 + NaN // NaN

        Infinity
        1/0 // Infinity
        -1/0 // -Infinity
    




*/

console.log('========================================================')
console.log(`
    => Number <=
`)

var x = 10000000000000000000000000;
console.log('X is',x) // output: X is 1e+25

console.log(`Modulo example:
3 % 2 = ${3%2}
`); // output: 1

console.log(`Exponent example:
2**4 = ${2**4}
`); //output : 16

console.log(`NaN example:
0/0 = ${0/0}
1 + NaN = ${1+NaN}
`)

console.log(`
we cannot perform math operation on string.
example: 
a. 2*'Hello' = ${2*'Hello'}
b. 10 / 'Hello' = ${10 / 'Hello'}
d. 10 - 'Hello' = ${10 - 'Hello'}
c. 10 + 'Hello' = ${10 + 'Hello'}
`) // NaN and 10Hello

console.log(`Infinity Example:
1/0 = ${1/0}
-1/0 = ${-1/0}
`)

console.log(`Order of Operation Example:
a.
 1.5 + 2.5 * 3 = ${1.5 + 2.5 * 3}
 same as = (2.5*3) + 1.5

b. (10 % 8) ** 3 = ${ (10 % 8) ** 3 }

c. 2 + 0/0 = ${2 + 0/0 }
`)

console.log('========================================================')
console.log(`
    => Boolean <=

    Object that are False:
    - -0
    - 0
    - null
    - false
    - NaN
    - undefined
    - ""

    Object that are True:
    - Any Object that are
        - not undefined
        - not null
    - "false"
    - new Boolean(false)
`)

console.log(`
Example: using x as variable
a. var x = false
    output: ${Boolean(false)}

b. var x = new Boolean(false)
    output: ${ Boolean(new Boolean(false))}

c. var x = new String('Hello')
    output: ${Boolean(new String('Hello'))}

d. var x = undefined;
    output: ${Boolean(undefined)}

e. var x = NaN;
    output: ${Boolean(NaN)}

f. var x = 0;
    output: ${Boolean(0)}

g. var x = -0;
    output: ${Boolean(-0)}

   var x = 1;
    output: ${Boolean(1)}
   
   var x = 3;
    output: ${Boolean(3)}

h. var x = "";
    output: ${Boolean("")}

i. var x = null;
    output: ${Boolean(null)}

j. var x = "null";
    output: ${Boolean("null")}

k. var x = "false";
    output: ${Boolean("false")}
`)
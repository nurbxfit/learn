/*
    JavaScript Variables,
    we can declare with 3 different ways
    - var => can be refer outside of scope or block.
    - let => limited to a scope or block
    - const => create a constant variable (unchangable/ except for object value).
*/
// var example.
console.log(`
============================================
      => var <=
`)
var x = 10;
var y = 99;
function test(){
    var b = 10;
    var x = 20;
    console.log('test.B inside:',b)
    console.log('test.X inside:',x); 
    y = 30
    console.log('Changed Y inside:',x)
}
test();
b = 20; //we can use b outside of the test() scope 
console.log('test.B outside:',b)
console.log('X outside:',x);

console.log(`
============================================
      => Let <=
`)
let a = 10;
let k = 99;
function test2(){
    let a = 30;
    let c = 40;
    c = 20;
    k = 2;
    console.log('test2.a inside:',a);
    console.log('test2.c inside:',c);
    console.log('changed k inside:',k);
}
console.log('a outside:',a)
console.log('k outside:',k)
test2();
console.log('k outside after test2:',k)
try{
    console.log('Trying to change test2.c outside:',c)
}catch(error){
    console.log('Undefined c outside')
    console.error(error);
}

// but if we declare c like this
c = 77
console.log('This C is global not from test2:',c)



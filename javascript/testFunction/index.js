const meth = {};
meth.toStr = function(param){
  console.log('Hello ',param);
  return 2;
}
//const caller = 'toStr("world")';

function doSomething(){
  const test = new Function ('func','caller','console.log(func.toStr("test"))');
  test(meth,'toStr("world")');
}
doSomething();

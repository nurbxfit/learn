const fs = require('fs');
const path = require('path');

const lib = {} 
lib.baseDir = path.join(__dirname,'./regex/');

lib.buildRegex = function(input){
  if(typeof input !== 'string'){
    throw new Error('Regex Input is not a string');
  }
  //parse regex from /expression/flag, into groups
  const p = input.match(/(\/)(.+)\1([gimsuy]*)/i);
  return new RegExp(p[2],p[3]);
}

lib.load = function(filename){
  const regList = fs.readFileSync(this.baseDir+filename+'.txt','utf8').split('\n');
  regList.pop();
  const regex = regList.map((rgx)=>lib.buildRegex(rgx)); 
  return regex;
}

module.exports = lib; 

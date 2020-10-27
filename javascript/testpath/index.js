const path = require('path');

const scripts = {};

const foldername = path.join(__dirname,'routes');
require('fs').readdirSync(foldername).forEach(function(file){
  const name = file.replace('.js','');
  console.log('Name:',name);
  scripts[name] = require('./routes/' + file);

})
console.log('scripts',scripts);
console.log(__dirname);
console.log(__filename);
console.log(foldername);

module.exports = scripts;

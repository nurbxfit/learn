const path = require('path');

const foldername = path.join(__dirname,'routes');
require('fs').readdirSync(foldername).forEach(function(file){
  const name = file.replace('.js','');
  console.log('Name:',name);
  const toexport = require('./routes/' + file);
  toexport.run();

})
console.log(__dirname);
console.log(__filename);
console.log(foldername);

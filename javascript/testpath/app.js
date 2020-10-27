const scripts = require('./index');

console.log('Script in App:',scripts);
Object.values(scripts).forEach(function(script){
  script.run();
  //console.log('SCRIPT',script);
});

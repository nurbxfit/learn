const app = {}

app.text = ['Hello This is a first text, and quite normal!',
  '(2020), is the year and it is full of shit',
  '2020', 
  '(2020)',
  '&nbsp',
  '&nbsp;',
  'nbsp',
  'ⅢⅢⅢ',
  'ⅢⅢⅢⅢ',
  '[Text in Japanese]',
  '[ Text in Japanese ]',
  '[ Something in Japanese]',
  '[ in Japanese ]',
  '[in Japanese ]',
  'This is just a normal text',
  ' 1110 is also a normal text', 
  'ABSTRACT*',
  'Abbreviations',
  '1 (2013)',
  '1570-159X/09 $55.00+.00 ©2009 Bentham',
  'https://www.jamanet.com/',
];

app.regex = [
  /^\w+\*?\s?$/gi,
  /^\(\d\)$/gim,
  /\Ⅲ{3}/gim,
  /\((\d{4})\)/gim,
  /\&nbsp\;?/gi,
  /^Abbreviations$/i,
  /\[\s?(text\s)?in\sJapanese\s?\]/gi,
  /((ht|f)tps?\:)?(\/\/)?((\w+\.){2,}\w+\/?)(\w+\/?){1,}/gi,
  /((?:ht|f)tps?:\/\/)?([^\s\:]+(\.[^\s|^\,]+){2,})/gi,
  /^\d+\s\(\d+\)/i, //1 (2013)
]

app.validateText = function(text) {
  return app.regex.map(function(regx){
    return (text.match(regx))? {regx, text} : false; 
  })
}


app.test = function(){
  console.log('Regx:',this.regex);
  this.text.map(async function(text){
    const test = await app.validateText(text);
    console.log(`${text}:`,test);

  });
}

app.test();

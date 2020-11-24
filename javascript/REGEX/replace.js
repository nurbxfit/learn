
const text = [
  'Hello This is a first text, and quite normal!',
  '(2020), is the year and it is full of shit',
  '2020',
  '(2020)',
  '&nbsp',
  '&nbsp;',
  '1570-159X/09 $55.00+.00 ©2009 Bentham',
  '0013-7227/03/$15.00/0 Endocrinology',
  'ⅢⅢⅢ Natures Market?',
  '03-3 Introduction to Japanese Anma massage therapy',
  '<div id="oneGoogleBar">hello world</div>',
]


const regex = [
  /^\d+\-(\d|[^\s])+/i,
  /^\d+\s\(\d+\)/i, //1 (2013)
  /^(\d+\.){2}[^\s]/i, //10.2.3
  /^\(\d+\s(articles)+\)/g, //(243 articles)
  /\Ⅲ+[^\s]/gim, //ⅢⅢⅢ Nature's Market?
  /\$\d+\.\d[^\sa-z]+/gi, //$15.200/0
  /(<([^>]+)>)/gim, // for html tags
]

function clean(text){
  let cleaned = text 
  regex.map(function(regx){
    cleaned = cleaned.replace(regx,'').trim();
  });
  return cleaned;
}

function run(){
  text.map(async function(txt){
    const cleaned = await clean(txt);
    console.log(`\nbefore: ${txt}\nafter: ${cleaned}\n`);
  });
}

run();

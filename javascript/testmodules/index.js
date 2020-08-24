const mongoose = require('mongoose');
const tester = require('./lib/tester')(mongoose);

const app = {}

mongoose.connect('mongodb://localhost/test',{useNewUrlParser:true})
const db = mongoose.connection;
db.on('error',console.error.bind(console,'connection error'));
db.once('open',function(){
	console.log('Connected to mongodb');
})

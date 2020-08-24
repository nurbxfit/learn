const Testing = (TestModel,name) => {
	const newTest = new TestModel({
		name:name,
	});
	newTest.save(function(err,test){
		if(err) return console.error(err);
		if(test) console.log('Tested',test);
	});
}

module.exports = Testing;

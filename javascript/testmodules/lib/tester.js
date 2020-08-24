//const mongoose = require('mongoose');
const TestSchema = require('../models/test');
const Testing = require('../testing');

const Tester = (mongoose) => {
	const TestModel = mongoose.model('testing',TestSchema);
	Testing(TestModel,'Hello World')
}

module.exports = Tester;


'use strict';
var assert = require('assert');
var pwuid = require('./index')();

it('should return the an object with properties', function () {
	console.log(pwuid);
	assert.ok(typeof pwuid === 'object');
	assert.ok(typeof pwuid.name === 'string');
	assert.ok(typeof pwuid.dir === 'string');
});

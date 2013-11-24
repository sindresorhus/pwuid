'use strict';
var binding = require('./build/Release/binding');

module.exports = function (uid) {
	if (uid === undefined) {
		uid = process.getuid();
	}

	if (typeof uid !== 'number') {
		throw new Error('uid must be a number');
	}

	return binding.get(uid);
};

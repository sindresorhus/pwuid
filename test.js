import test from 'ava';
import getPwuid from './index.js';

test('main', t => {
	const pwuid = getPwuid();
	console.log(pwuid);
	t.is(typeof pwuid, 'object');
	t.is(typeof pwuid.name, 'string');
	t.is(typeof pwuid.dir, 'string');
});

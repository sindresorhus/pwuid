import test from 'ava';
import fn from './';

test(t => {
	const pwuid = fn();
	console.log(pwuid);
	t.is(typeof pwuid, 'object');
	t.is(typeof pwuid.name, 'string');
	t.is(typeof pwuid.dir, 'string');
});

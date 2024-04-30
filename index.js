import process from 'node:process';
import bindings from 'bindings';

const binding = bindings('binding');

export default function pwuid(uid = process.getuid()) {
	if (typeof uid !== 'number') {
		throw new TypeError('The `uid` must be a number.');
	}

	return binding(uid);
}

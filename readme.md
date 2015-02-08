# pwuid [![Build Status](https://travis-ci.org/sindresorhus/pwuid.svg?branch=master)](https://travis-ci.org/sindresorhus/pwuid)

> [getpwuid()](http://man7.org/linux/man-pages/man3/getpwnam.3.html) for Node.js - returns username, name, home directory, shell, gid from `uid`

If you're creating a reusable module you should probably use [passwd-user](https://github.com/sindresorhus/passwd-user) instead, as it shells out rather than using a native binding.


## Install

```
$ npm install --save pwuid
```

**This is a native binding and expects you to have the required [toolchain](https://github.com/TooTallNate/node-gyp#installation).** *(ignore the node-gyp install)*


## Windows

`getpwuid()` is a POSIX function and won't work on Windows.

Use [optionalDependencies](https://npmjs.org/doc/json.html#optionalDependencies) if you need to include it in a cross-platform environment.


## Usage

```js
var pwuid = require('pwuid');

console.log(pwuid());
/*
{
	name: 'sindresorhus',
	uid: 501,
	gid: 20,
	gecos: 'Sindre Sorhus',
	dir: '/Users/sindresorhus',
	shell: '/bin/zsh'
}
*/
```


## API

Accepts a `uid` number and returns an object with:

- `name`: username
- `uid`: user ID, same as supplied
- `gid`: group ID
- `gecos`: user information, usually the users full name
- `dir`: home directory
- `shell`: default shell

Will use current user `process.getuid()` if no `uid` is supplied.


## License

MIT © [Sindre Sorhus](http://sindresorhus.com)

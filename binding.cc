#include <sys/types.h>
#include <pwd.h>

#include <node.h>
#include "nan.h"

using namespace v8;


NAN_METHOD(pwuid) {
	NanScope();

	int uid = args[0]->Uint32Value();
	struct passwd *pw = getpwuid(uid);

	if (pw == NULL) {
		NanReturnNull();
	}

	Local<Object> obj = Object::New();
	obj->Set(NanSymbol("name"), String::New(pw->pw_name));
	obj->Set(NanSymbol("uid"),Number::New(pw->pw_uid));
	obj->Set(NanSymbol("gid"), Number::New(pw->pw_gid));
	obj->Set(NanSymbol("gecos"), String::New(pw->pw_gecos));
	obj->Set(NanSymbol("dir"), String::New(pw->pw_dir));
	obj->Set(NanSymbol("shell"), String::New(pw->pw_shell));

	NanReturnValue(obj);
}

void init(Handle<Object> exports, Handle<Object> module) {
	NODE_SET_METHOD(module, "exports", pwuid);
}

NODE_MODULE(binding, init)

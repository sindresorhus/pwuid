#include <sys/types.h>
#include <pwd.h>

#include <node.h>
#include <nan.h>

using namespace v8;

NAN_METHOD(pwuid) {
	NanScope();

	int uid = args[0]->Uint32Value();
	struct passwd *pw = getpwuid(uid);

	if (pw == NULL) {
		NanReturnNull();
	}

	Local<Object> obj = NanNew<Object>();
	obj->Set(NanNew<String>("name"), NanNew<String>(pw->pw_name));
	obj->Set(NanNew<String>("uid"), NanNew<Number>(pw->pw_uid));
	obj->Set(NanNew<String>("gid"), NanNew<Number>(pw->pw_gid));
	obj->Set(NanNew<String>("gecos"), NanNew<String>(pw->pw_gecos));
	obj->Set(NanNew<String>("dir"), NanNew<String>(pw->pw_dir));
	obj->Set(NanNew<String>("shell"), NanNew<String>(pw->pw_shell));

	NanReturnValue(obj);
}

void init(Handle<Object> exports, Handle<Object> module) {
	NODE_SET_METHOD(module, "exports", pwuid);
}

NODE_MODULE(binding, init)

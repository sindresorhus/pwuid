#include <sys/types.h>
#include <pwd.h>

#include <node.h>
#include <nan.h>

using namespace v8;

NAN_METHOD(pwuid) {
	Nan::HandleScope scope;

	int uid = info[0]->Uint32Value();
	struct passwd *pw = getpwuid(uid);

	if (pw == NULL) {
		info.GetReturnValue().Set(Nan::Null());
		return;
	}

	Local<Object> obj = Nan::New<Object>();
	obj->Set(Nan::New<String>("name").ToLocalChecked(), Nan::New<String>(pw->pw_name).ToLocalChecked());
	obj->Set(Nan::New<String>("uid").ToLocalChecked(), Nan::New<Number>(pw->pw_uid));
	obj->Set(Nan::New<String>("gid").ToLocalChecked(), Nan::New<Number>(pw->pw_gid));
	obj->Set(Nan::New<String>("gecos").ToLocalChecked(), Nan::New<String>(pw->pw_gecos).ToLocalChecked());
	obj->Set(Nan::New<String>("dir").ToLocalChecked(), Nan::New<String>(pw->pw_dir).ToLocalChecked());
	obj->Set(Nan::New<String>("shell").ToLocalChecked(), Nan::New<String>(pw->pw_shell).ToLocalChecked());

	info.GetReturnValue().Set(obj);
}

void init(Handle<Object> exports, Handle<Object> module) {
	Nan::SetMethod(module, "exports", pwuid);
}

NODE_MODULE(binding, init)

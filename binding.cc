#include <sys/types.h>
#include <pwd.h>

#include <node.h>
#include <nan.h>

using namespace v8;

NAN_METHOD(pwuid) {
	Nan::HandleScope scope;
	Local<Context> context = info.GetIsolate()->GetCurrentContext(); // Get current context

	// Check if the first argument is a number and convert it
	if (!info[0]->IsNumber()) {
		Nan::ThrowTypeError("Argument must be a number");
		return;
	}

	uint32_t uid = info[0]->Uint32Value(context).FromJust(); // Properly extract uint32_t
	struct passwd *pw = getpwuid(uid);

	if (pw == NULL) {
		info.GetReturnValue().Set(Nan::Null());
		return;
	}

	Local<Object> obj = Nan::New<Object>();
	obj->Set(context, Nan::New<String>("name").ToLocalChecked(), Nan::New<String>(pw->pw_name).ToLocalChecked()).FromJust();
	obj->Set(context, Nan::New<String>("uid").ToLocalChecked(), Nan::New<Number>(pw->pw_uid)).FromJust();
	obj->Set(context, Nan::New<String>("gid").ToLocalChecked(), Nan::New<Number>(pw->pw_gid)).FromJust();
	obj->Set(context, Nan::New<String>("gecos").ToLocalChecked(), Nan::New<String>(pw->pw_gecos).ToLocalChecked()).FromJust();
	obj->Set(context, Nan::New<String>("dir").ToLocalChecked(), Nan::New<String>(pw->pw_dir).ToLocalChecked()).FromJust();
	obj->Set(context, Nan::New<String>("shell").ToLocalChecked(), Nan::New<String>(pw->pw_shell).ToLocalChecked()).FromJust();

	info.GetReturnValue().Set(obj);
}

void init(Local<Object> exports, Local<Object> module) {
	Nan::SetMethod(module, "exports", pwuid);
}

NODE_MODULE(binding, init)

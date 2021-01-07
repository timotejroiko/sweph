#include "sweph.h"

Napi::Value sweph_get_current_file_data(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(info.Length() != 1) {
		Napi::TypeError::New(env, "Expecting 1 argument").ThrowAsJavaScriptException();
		return env.Null();
	}
	if(!info[0].IsNumber()) {
		Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
		return env.Null();
	}
	double tfstart;
	double tfend;
	int denum;
	Napi::Object obj = Napi::Object::New(env);
	const char *path = swe_get_current_file_data(
		info[0].As<Napi::Number>().Int32Value(),
		&tfstart,
		&tfend,
		&denum
	);
	obj.Set(Napi::String::New(env, "path"), Napi::String::New(env, path));
	obj.Set(Napi::String::New(env, "start"), Napi::Number::New(env, tfstart));
	obj.Set(Napi::String::New(env, "end"), Napi::Number::New(env, tfend));
	obj.Set(Napi::String::New(env, "denum"), Napi::Number::New(env, denum));
	return obj;
}

#include "sweph.h"

Napi::Value sweph_time_equ(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(info.Length() < 1) {
		Napi::TypeError::New(env, "Expecting 1 argument").ThrowAsJavaScriptException();
		return env.Null();
	}
	if(!info[0].IsNumber()) {
		Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
		return env.Null();
	}
	double e;
	char serr [SE_MAX_STNAME];
	int flag = swe_time_equ(
		info[0].As<Napi::Number>().DoubleValue(),
		&e,
		serr
	);
	Napi::Object obj = Napi::Object::New(env);
	obj.Set(Napi::String::New(env, "flag"), Napi::Number::New(env, flag));
	obj.Set(Napi::String::New(env, "serr"), Napi::String::New(env, serr));
	obj.Set(Napi::String::New(env, "e"), Napi::Number::New(env, e));
	return obj;
}

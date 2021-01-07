#include "sweph.h"

Napi::Value sweph_deltat_ex(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(info.Length() < 2) {
		Napi::TypeError::New(env, "Expecting 2 arguments").ThrowAsJavaScriptException();
		return env.Null();
	}
	if(!info[0].IsNumber()) {
		Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
		return env.Null();
	}
	if(!info[1].IsNumber()) {
		Napi::TypeError::New(env, "Argument 2 should be a number").ThrowAsJavaScriptException();
		return env.Null();
	}
	char serr [SE_MAX_STNAME];
	double delta = swe_deltat_ex(
		info[0].As<Napi::Number>().DoubleValue(),
		info[1].As<Napi::Number>().Int32Value(),
		serr
	);
	Napi::Object obj = Napi::Object::New(env);
	obj.Set(Napi::String::New(env, "serr"), Napi::String::New(env, serr));
	obj.Set(Napi::String::New(env, "deltat"), Napi::Number::New(env, delta));
	return obj;
}

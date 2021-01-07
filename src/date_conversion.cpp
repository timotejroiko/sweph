#include "sweph.h"

Napi::Value sweph_date_conversion(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(info.Length() < 5) {
		Napi::TypeError::New(env, "Expecting 5 arguments").ThrowAsJavaScriptException();
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
	if(!info[2].IsNumber()) {
		Napi::TypeError::New(env, "Argument 3 should be a number").ThrowAsJavaScriptException();
		return env.Null();
	}
	if(!info[3].IsNumber()) {
		Napi::TypeError::New(env, "Argument 4 should be a number").ThrowAsJavaScriptException();
		return env.Null();
	}
	if(!info[4].IsString()) {
		Napi::TypeError::New(env, "Argument 5 should be a string").ThrowAsJavaScriptException();
		return env.Null();
	}
	double ret;
	int flag = swe_date_conversion(
		info[0].As<Napi::Number>().Int32Value(),
		info[1].As<Napi::Number>().Int32Value(),
		info[2].As<Napi::Number>().Int32Value(),
		info[3].As<Napi::Number>().DoubleValue(),
		info[4].As<Napi::String>().Utf8Value()[0],
		&ret
	);
	Napi::Object obj = Napi::Object::New(env);
	obj.Set(Napi::String::New(env, "flag"), Napi::Number::New(env, flag));
	obj.Set(Napi::String::New(env, "jd"), Napi::Number::New(env, ret));
	return obj;
}

#include "sweph.h"

Napi::Value sweph_utc_to_jd(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(info.Length() < 7) {
		Napi::TypeError::New(env, "Expecting 7 arguments").ThrowAsJavaScriptException();
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
	if(!info[4].IsNumber()) {
		Napi::TypeError::New(env, "Argument 5 should be a number").ThrowAsJavaScriptException();
		return env.Null();
	}
	if(!info[5].IsNumber()) {
		Napi::TypeError::New(env, "Argument 6 should be a number").ThrowAsJavaScriptException();
		return env.Null();
	}
	if(!info[6].IsNumber()) {
		Napi::TypeError::New(env, "Argument 7 should be a number").ThrowAsJavaScriptException();
		return env.Null();
	}
	double ret [2];
	char serr [SE_MAX_STNAME];
	int flag = swe_utc_to_jd(
		info[0].As<Napi::Number>().Int32Value(),
		info[1].As<Napi::Number>().Int32Value(),
		info[2].As<Napi::Number>().Int32Value(),
		info[3].As<Napi::Number>().Int32Value(),
		info[4].As<Napi::Number>().Int32Value(),
		info[5].As<Napi::Number>().DoubleValue(),
		info[6].As<Napi::Number>().Int32Value(),
		ret,
		serr
	);
	Napi::Array array = Napi::Array::New(env);
	for(int i = 0; i < 2; i++) {
		array[i] = Napi::Number::New(env, ret[i]);
	}
	array.Set(Napi::String::New(env, "flag"), Napi::Number::New(env, flag));
	array.Set(Napi::String::New(env, "error"), Napi::String::New(env, serr));
	return array;
}

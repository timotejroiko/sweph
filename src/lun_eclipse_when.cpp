#include "sweph.h"

Napi::Value sweph_lun_eclipse_when(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(info.Length() < 4) {
		Napi::TypeError::New(env, "Expecting 4 arguments").ThrowAsJavaScriptException();
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
	if(!info[3].IsBoolean()) {
		Napi::TypeError::New(env, "Argument 4 should be a boolean").ThrowAsJavaScriptException();
		return env.Null();
	}
	double ret [10];
	char serr [SE_MAX_STNAME];
	int flag = swe_lun_eclipse_when(
		info[0].As<Napi::Number>().DoubleValue(),
		info[1].As<Napi::Number>().Int32Value(),
		info[2].As<Napi::Number>().Int32Value(),
		ret,
		info[3].As<Napi::Boolean>(),
		serr
	);
	Napi::Array ret1 = Napi::Array::New(env);
	for(int i = 0; i < 8; i++) {
		ret1[i] = Napi::Number::New(env, ret[i]);
	}
	ret1.Set(Napi::String::New(env, "flag"), Napi::Number::New(env, flag));
	ret1.Set(Napi::String::New(env, "error"), Napi::String::New(env, serr));
	return ret1;
}

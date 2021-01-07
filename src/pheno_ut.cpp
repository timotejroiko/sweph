#include "sweph.h"

Napi::Value sweph_pheno_ut(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(info.Length() < 3) {
		Napi::TypeError::New(env, "Expecting 3 arguments").ThrowAsJavaScriptException();
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
	double attr [20];
	char serr [SE_MAX_STNAME];
	int flag = swe_pheno_ut(
		info[0].As<Napi::Number>().DoubleValue(),
		info[1].As<Napi::Number>().Int32Value(),
		info[2].As<Napi::Number>().Int32Value(),
		attr,
		serr
	);
	Napi::Array attr1 = Napi::Array::New(env);
	for(int i = 0; i < 5; i++) {
		attr1[i] = Napi::Number::New(env, attr[i]);
	}
	attr1.Set(Napi::String::New(env, "flag"), Napi::Number::New(env, flag));
	attr1.Set(Napi::String::New(env, "error"), Napi::String::New(env, serr));
	return attr1;
}

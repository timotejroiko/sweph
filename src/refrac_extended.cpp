#include "sweph.h"

Napi::Value sweph_refrac_extended(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(info.Length() < 6) {
		Napi::TypeError::New(env, "Expecting 6 arguments").ThrowAsJavaScriptException();
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
	double ret [20];
	double out = swe_refrac_extended(
		info[0].As<Napi::Number>().DoubleValue(),
		info[1].As<Napi::Number>().DoubleValue(),
		info[2].As<Napi::Number>().DoubleValue(),
		info[3].As<Napi::Number>().DoubleValue(),
		info[4].As<Napi::Number>().DoubleValue(),
		info[5].As<Napi::Number>().Int32Value(),
		ret
	);
	Napi::Array out1 = Napi::Array::New(env);
	for(int i = 0; i < 4; i++) {
		out1[i] = Napi::Number::New(env, ret[i]);
	}
	out1.Set(Napi::String::New(env, "altitude"), Napi::Number::New(env, out));
	return out1;
}

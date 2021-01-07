#include "sweph.h"

Napi::Value sweph_deltat(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(info.Length() < 1) {
		Napi::TypeError::New(env, "Expecting 1 argument").ThrowAsJavaScriptException();
		return env.Null();
	}
	if(!info[0].IsNumber()) {
		Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
		return env.Null();
	}
	double delta = swe_deltat(info[0].As<Napi::Number>().DoubleValue());
	return Napi::Number::New(env, delta);
}

#include "sweph.h"

Napi::Value sweph_julday(const Napi::CallbackInfo& info) {
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
	if(!info[4].IsNumber()) {
		Napi::TypeError::New(env, "Argument 5 should be a number").ThrowAsJavaScriptException();
		return env.Null();
	}
	double time = swe_julday(
		info[0].As<Napi::Number>().Int32Value(),
		info[1].As<Napi::Number>().Int32Value(),
		info[2].As<Napi::Number>().Int32Value(),
		info[3].As<Napi::Number>().DoubleValue(),
		info[4].As<Napi::Number>().Int32Value()
	);
	return Napi::Number::New(env, time);
}

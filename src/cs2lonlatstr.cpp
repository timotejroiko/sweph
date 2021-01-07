#include "sweph.h"

Napi::Value sweph_cs2lonlatstr(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(info.Length() < 3) {
		Napi::TypeError::New(env, "Expecting 3 arguments").ThrowAsJavaScriptException();
		return env.Null();
	}
	if(!info[0].IsNumber()) {
		Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
		return env.Null();
	}
	if(!info[1].IsString()) {
		Napi::TypeError::New(env, "Argument 2 should be a string").ThrowAsJavaScriptException();
		return env.Null();
	}
	if(!info[2].IsString()) {
		Napi::TypeError::New(env, "Argument 3 should be a string").ThrowAsJavaScriptException();
		return env.Null();
	}
	char out [SE_MAX_STNAME];
	swe_cs2lonlatstr(
		info[0].As<Napi::Number>().Int32Value(),
		info[1].As<Napi::String>().Utf8Value()[0],
		info[2].As<Napi::String>().Utf8Value()[0],
		out
	);
	return Napi::String::New(env, out);
}

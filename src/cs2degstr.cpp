#include "sweph.h"

Napi::Value sweph_cs2degstr(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(info.Length() < 1) {
		Napi::TypeError::New(env, "Expecting 1 argument").ThrowAsJavaScriptException();
		return env.Null();
	}
	if(!info[0].IsNumber()) {
		Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
		return env.Null();
	}
	char out [SE_MAX_STNAME];
	swe_cs2degstr(
		info[0].As<Napi::Number>().Int32Value(),
		out
	);
	return Napi::String::New(env, out);
}

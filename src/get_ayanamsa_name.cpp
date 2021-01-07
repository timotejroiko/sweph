#include "sweph.h"

Napi::Value sweph_get_ayanamsa_name(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(info.Length() < 1) {
		Napi::TypeError::New(env, "Expecting 1 argument").ThrowAsJavaScriptException();
		return env.Null();
	}
	if(!info[0].IsNumber()) {
		Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
		return env.Null();
	}
	const char* name = swe_get_ayanamsa_name(info[0].As<Napi::Number>().Int32Value());
	if(name == NULL) {
		Napi::TypeError::New(env, "Invalid ayanamsa").ThrowAsJavaScriptException();
		return env.Null();
	}
	return Napi::String::New(env, name);
}

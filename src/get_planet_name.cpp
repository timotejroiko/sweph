#include "sweph.h"

Napi::Value sweph_get_planet_name(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(info.Length() != 1) {
		Napi::TypeError::New(env, "Expecting 1 argument").ThrowAsJavaScriptException();
		return env.Null();
	}
	if(!info[0].IsNumber()) {
		Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
		return env.Null();
	}
	char planet [SE_MAX_STNAME];
	swe_get_planet_name(
		info[0].As<Napi::Number>().Int32Value(),
		planet
	);
	return Napi::String::New(env, planet);
}

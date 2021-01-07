#include "sweph.h"

Napi::Value sweph_fixstar_mag(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(info.Length() < 1) {
		Napi::TypeError::New(env, "Expecting 1 argument").ThrowAsJavaScriptException();
		return env.Null();
	}
	if(!info[0].IsString()) {
		Napi::TypeError::New(env, "Argument 1 should be a string").ThrowAsJavaScriptException();
		return env.Null();
	}
	double mag;
	char serr [SE_MAX_STNAME];
	long flag = swe_fixstar_mag(
		const_cast<char*>(info[0].As<Napi::String>().Utf8Value().c_str()),
		&mag,
		serr
	);
	Napi::Object obj = Napi::Object::New(env);
	obj.Set(Napi::String::New(env, "flag"), Napi::Number::New(env, flag));
	obj.Set(Napi::String::New(env, "error"), Napi::String::New(env, serr));
	obj.Set(Napi::String::New(env, "magnitude"), Napi::Number::New(env, mag));
	return obj;
}

#include "sweph.h"

Napi::Value sweph_house_pos(const Napi::CallbackInfo& info) {
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
	if(!info[3].IsString()) {
		Napi::TypeError::New(env, "Argument 4 should be a string").ThrowAsJavaScriptException();
		return env.Null();
	}
	if(!info[4].IsArray()) {
		Napi::TypeError::New(env, "Argument 5 should be an array of 2 numbers").ThrowAsJavaScriptException();
		return env.Null();
	}
	Napi::Array pos = info[4].As<Napi::Array>();
	double planet [2];
	for(int i = 0; i < 2; i++) {
		if(!((Napi::Value)pos[i]).IsNumber()) {
			Napi::TypeError::New(env, "Argument 5 should be an array of 2 numbers").ThrowAsJavaScriptException();
			return env.Null();
		}
		planet[i] = ((Napi::Value)pos[i]).As<Napi::Number>().DoubleValue();
	}
	char serr [SE_MAX_STNAME];
	char sys = info[3].As<Napi::String>().Utf8Value()[0];
	double house = swe_house_pos(
		info[0].As<Napi::Number>().DoubleValue(),
		info[1].As<Napi::Number>().DoubleValue(),
		info[2].As<Napi::Number>().DoubleValue(),
		int(sys),
		planet,
		serr
	);
	Napi::Object obj = Napi::Object::New(env);
	obj.Set(Napi::String::New(env, "house"), house);
	obj.Set(Napi::String::New(env, "error"), Napi::String::New(env, serr));
	return obj;
}

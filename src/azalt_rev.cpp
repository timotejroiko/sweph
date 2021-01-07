#include "sweph.h"

Napi::Value sweph_azalt_rev(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(info.Length() < 4) {
		Napi::TypeError::New(env, "Expecting 4 arguments").ThrowAsJavaScriptException();
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
	if(!info[2].IsArray()) {
		Napi::TypeError::New(env, "Argument 3 should be an array of 3 numbers").ThrowAsJavaScriptException();
		return env.Null();
	}
	if(!info[3].IsArray()) {
		Napi::TypeError::New(env, "Argument 4 should be an array of 2 numbers").ThrowAsJavaScriptException();
		return env.Null();
	}
	Napi::Array geo = info[2].As<Napi::Array>();
	double geopos [3];
	for(int i = 0; i < 3; i++) {
		Napi::Value g = geo[i];
		if(!g.IsNumber()) {
			Napi::TypeError::New(env, "Argument 3 should be an array of 3 numbers").ThrowAsJavaScriptException();
			return env.Null();
		}
		geopos[i] = g.As<Napi::Number>().DoubleValue();
	}
	Napi::Array pos = info[3].As<Napi::Array>();
	double xin [2];
	for(int i = 0; i < 2; i++) {
		Napi::Value p = pos[i];
		if(!p.IsNumber()) {
			Napi::TypeError::New(env, "Argument 4 should be an array of 2 numbers").ThrowAsJavaScriptException();
			return env.Null();
		}
		xin[i] = p.As<Napi::Number>().DoubleValue();
	}
	double out [2];
	swe_azalt_rev(
		info[0].As<Napi::Number>().DoubleValue(),
		info[1].As<Napi::Number>().Int32Value(),
		geopos,
		xin,
		out
	);
	Napi::Array out1 = Napi::Array::New(env);
	for(int i = 0; i < 2; i++) {
		out1[i] = Napi::Number::New(env, out[i]);
	}
	return out1;
}

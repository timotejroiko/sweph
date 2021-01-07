#include "sweph.h"

Napi::Value sweph_azalt(const Napi::CallbackInfo& info) {
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
	if(!info[2].IsArray()) {
		Napi::TypeError::New(env, "Argument 3 should be an array of 3 numbers").ThrowAsJavaScriptException();
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
	if(!info[5].IsArray()) {
		Napi::TypeError::New(env, "Argument 6 should be an array of 3 numbers").ThrowAsJavaScriptException();
		return env.Null();
	}
	Napi::Array geo = info[2].As<Napi::Array>();
	double geopos [3];
	for(int i = 0; i < 3; i++) {
		if(!((Napi::Value)geo[i]).IsNumber()) {
			Napi::TypeError::New(env, "Argument 3 should be an array of 3 numbers").ThrowAsJavaScriptException();
			return env.Null();
		}
		geopos[i] = ((Napi::Value)geo[i]).As<Napi::Number>().DoubleValue();
	}
	Napi::Array pos = info[5].As<Napi::Array>();
	double xin [3];
	for(int i = 0; i < 3; i++) {
		if(!((Napi::Value)pos[i]).IsNumber()) {
			Napi::TypeError::New(env, "Argument 6 should be an array of 3 numbers").ThrowAsJavaScriptException();
			return env.Null();
		}
		xin[i] = ((Napi::Value)pos[i]).As<Napi::Number>().DoubleValue();
	}
	double out [3];
	swe_azalt(
		info[0].As<Napi::Number>().DoubleValue(),
		info[1].As<Napi::Number>().Int32Value(),
		geopos,
		info[3].As<Napi::Number>().DoubleValue(),
		info[4].As<Napi::Number>().DoubleValue(),
		xin,
		out
	);
	Napi::Array out1 = Napi::Array::New(env);
	for(int i = 0; i < 3; i++) {
		out1[i] = Napi::Number::New(env, out[i]);
	}
	return out1;
}

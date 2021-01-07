#include "sweph.h"

Napi::Value sweph_heliacal_ut(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(info.Length() < 7) {
		Napi::TypeError::New(env, "Expecting 7 arguments").ThrowAsJavaScriptException();
		return env.Null();
	}
	if(!info[0].IsNumber()) {
		Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
		return env.Null();
	}
	if(!info[1].IsArray()) {
		Napi::TypeError::New(env, "Argument 2 should be an array of 3 numbers").ThrowAsJavaScriptException();
		return env.Null();
	}
	if(!info[2].IsArray()) {
		Napi::TypeError::New(env, "Argument 3 should be an array of 4 numbers").ThrowAsJavaScriptException();
		return env.Null();
	}
	if(!info[3].IsArray()) {
		Napi::TypeError::New(env, "Argument 4 should be an array of 6 numbers").ThrowAsJavaScriptException();
		return env.Null();
	}
	if(!info[4].IsString()) {
		Napi::TypeError::New(env, "Argument 5 should be a string").ThrowAsJavaScriptException();
		return env.Null();
	}
	if(!info[5].IsNumber()) {
		Napi::TypeError::New(env, "Argument 6 should be a number").ThrowAsJavaScriptException();
		return env.Null();
	}
	if(!info[6].IsNumber()) {
		Napi::TypeError::New(env, "Argument 7 should be a number").ThrowAsJavaScriptException();
		return env.Null();
	}
	Napi::Array geo = info[1].As<Napi::Array>();
	double dgeo [3];
	for(int i = 0; i < 3; i++) {
		if(!((Napi::Value)geo[i]).IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be an array of 3 numbers").ThrowAsJavaScriptException();
			return env.Null();
		}
		dgeo[i] = ((Napi::Value)geo[i]).As<Napi::Number>().DoubleValue();
	}
	Napi::Array atm = info[2].As<Napi::Array>();
	double datm [4];
	for(int i = 0; i < 4; i++) {
		if(!((Napi::Value)atm[i]).IsNumber()) {
			Napi::TypeError::New(env, "Argument 2 should be an array of 4 numbers").ThrowAsJavaScriptException();
			return env.Null();
		}
		datm[i] = ((Napi::Value)atm[i]).As<Napi::Number>().DoubleValue();
	}
	Napi::Array obs = info[3].As<Napi::Array>();
	double dobs [6];
	char serr [SE_MAX_STNAME];
	for(int i = 0; i < 6; i++) {
		if(!((Napi::Value)obs[i]).IsNumber()) {
			Napi::TypeError::New(env, "Argument 3 should be an array of 6 numbers").ThrowAsJavaScriptException();
			return env.Null();
		}
		dobs[i] = ((Napi::Value)obs[i]).As<Napi::Number>().DoubleValue();
	}
	double ret [50];
	int flag = swe_heliacal_ut(
		info[0].As<Napi::Number>().DoubleValue(),
		dgeo,
		datm,
		dobs,
		const_cast<char*>(info[4].As<Napi::String>().Utf8Value().c_str()),
		info[5].As<Napi::Number>().Int32Value(),
		info[6].As<Napi::Number>().Int32Value(),
		ret,
		serr
	);
	Napi::Array dret = Napi::Array::New(env);
	for(int i = 0; i < 3; i++) {
		dret[i] = Napi::Number::New(env, ret[i]);
	}
	dret.Set(Napi::String::New(env, "flag"), Napi::Number::New(env, flag));
	dret.Set(Napi::String::New(env, "error"), Napi::String::New(env, serr));
	return dret;
}

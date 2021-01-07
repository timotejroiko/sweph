#include "sweph.h"

Napi::Value sweph_nod_aps(const Napi::CallbackInfo& info) {
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
	if(!info[2].IsNumber()) {
		Napi::TypeError::New(env, "Argument 3 should be a number").ThrowAsJavaScriptException();
		return env.Null();
	}
	if(!info[3].IsNumber()) {
		Napi::TypeError::New(env, "Argument 4 should be a number").ThrowAsJavaScriptException();
		return env.Null();
	}
	double asc [6];
	double dsc [6];
	double per [6];
	double aph [6];
	char serr [SE_MAX_STNAME];
	int flag = swe_nod_aps(
		info[0].As<Napi::Number>().DoubleValue(),
		info[1].As<Napi::Number>().Int32Value(),
		info[2].As<Napi::Number>().Int32Value(),
		info[3].As<Napi::Number>().Int32Value(),
		asc,
		dsc,
		per,
		aph,
		serr
	);
	Napi::Object obj = Napi::Object::New(env);
	Napi::Array asc1 = Napi::Array::New(env);
	Napi::Array dsc1 = Napi::Array::New(env);
	Napi::Array per1 = Napi::Array::New(env);
	Napi::Array aph1 = Napi::Array::New(env);
	for(int i = 0; i < 6; i++) {
		asc1[i] = Napi::Number::New(env, asc[i]);
	}
	for(int i = 0; i < 6; i++) {
		dsc1[i] = Napi::Number::New(env, dsc[i]);
	}
	for(int i = 0; i < 6; i++) {
		per1[i] = Napi::Number::New(env, per[i]);
	}
	for(int i = 0; i < 6; i++) {
		aph1[i] = Napi::Number::New(env, aph[i]);
	}
	obj.Set(Napi::String::New(env, "flag"), Napi::Number::New(env, flag));
	obj.Set(Napi::String::New(env, "error"), Napi::String::New(env, serr));
	obj.Set(Napi::String::New(env, "ascendingNode"), asc1);
	obj.Set(Napi::String::New(env, "descendingNode"), dsc1);
	obj.Set(Napi::String::New(env, "perihelion"), per1);
	obj.Set(Napi::String::New(env, "aphelion"), aph1);
	return obj;
}

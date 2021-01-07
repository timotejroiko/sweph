#include "sweph.h"

Napi::Value sweph_lun_occult_when_loc(const Napi::CallbackInfo& info) {
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
	if(!info[2].IsString() && !info[2].IsNull()) {
		Napi::TypeError::New(env, "Argument 3 should be a string or null").ThrowAsJavaScriptException();
		return env.Null();
	}
	if(!info[3].IsNumber()) {
		Napi::TypeError::New(env, "Argument 4 should be a number").ThrowAsJavaScriptException();
		return env.Null();
	}
	if(!info[4].IsNumber()) {
		Napi::TypeError::New(env, "Argument 5 should be an array of 3 numbers").ThrowAsJavaScriptException();
		return env.Null();
	}
	if(!info[5].IsBoolean()) {
		Napi::TypeError::New(env, "Argument 6 should be a boolean").ThrowAsJavaScriptException();
		return env.Null();
	}
	Napi::Array geo = info[4].As<Napi::Array>();
	double geopos [3];
	for(int i = 0; i < 3; i++) {
		if(!((Napi::Value)geo[i]).IsNumber()) {
			Napi::TypeError::New(env, "Argument 5 should be an array of 3 numbers").ThrowAsJavaScriptException();
			return env.Null();
		}
		geopos[i] = ((Napi::Value)geo[i]).As<Napi::Number>().DoubleValue();
	}
	double ret [10];
	double attr [20];
	char serr [SE_MAX_STNAME];
	int flag = swe_lun_occult_when_loc(
		info[0].As<Napi::Number>().DoubleValue(),
		info[1].As<Napi::Number>().Int32Value(),
		(info[2].IsString()) ? const_cast<char*>(info[2].As<Napi::String>().Utf8Value().c_str()) : NULL,
		info[3].As<Napi::Number>().Int32Value(),
		geopos,
		ret,
		attr,
		info[5].As<Napi::Boolean>(),
		serr
	);
	Napi::Object obj = Napi::Object::New(env);
	Napi::Array ret1 = Napi::Array::New(env);
	Napi::Array attr1 = Napi::Array::New(env);
	for(int i = 0; i < 7; i++) {
		ret1[i] = Napi::Number::New(env, ret[i]);
	}
	for(int i = 0; i < 8; i++) {
		attr1[i] = Napi::Number::New(env, attr[i]);
	}
	obj.Set(Napi::String::New(env, "time"), ret1);
	obj.Set(Napi::String::New(env, "attributes"), attr1);
	obj.Set(Napi::String::New(env, "flag"), Napi::Number::New(env, flag));
	obj.Set(Napi::String::New(env, "error"), Napi::String::New(env, serr));
	return obj;
}

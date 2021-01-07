#include "sweph.h"

Napi::Value sweph_lun_eclipse_when_loc(const Napi::CallbackInfo& info) {
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
	if(!info[3].IsBoolean()) {
		Napi::TypeError::New(env, "Argument 4 should be a boolean").ThrowAsJavaScriptException();
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
	double ret [10];
	double attr [20];
	char serr [SE_MAX_STNAME];
	int flag = swe_lun_eclipse_when_loc(
		info[0].As<Napi::Number>().DoubleValue(),
		info[1].As<Napi::Number>().Int32Value(),
		geopos,
		ret,
		attr,
		info[3].As<Napi::Boolean>(),
		serr
	);
	Napi::Object obj = Napi::Object::New(env);
	Napi::Array ret1 = Napi::Array::New(env);
	Napi::Array attr1 = Napi::Array::New(env);
	for(int i = 0; i < 10; i++) {
		ret1[i] = Napi::Number::New(env, ret[i]);
	}
	for(int i = 0; i < 11; i++) {
		attr1[i] = Napi::Number::New(env, attr[i]);
	}
	obj.Set(Napi::String::New(env, "time"), ret1);
	obj.Set(Napi::String::New(env, "attributes"), attr1);
	obj.Set(Napi::String::New(env, "flag"), Napi::Number::New(env, flag));
	obj.Set(Napi::String::New(env, "error"), Napi::String::New(env, serr));
	return obj;
}

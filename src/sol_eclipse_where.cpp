#include "sweph.h"

Napi::Value sweph_sol_eclipse_where(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(info.Length() < 2) {
		Napi::TypeError::New(env, "Expecting 2 arguments").ThrowAsJavaScriptException();
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
	double geopos [10];
	double attr [20];
	char serr [SE_MAX_STNAME];
	int flag = swe_sol_eclipse_where(
		info[0].As<Napi::Number>().DoubleValue(),
		info[1].As<Napi::Number>().Int32Value(),
		geopos,
		attr,
		serr
	);
	Napi::Object obj = Napi::Object::New(env);
	Napi::Array geopos1 = Napi::Array::New(env);
	Napi::Array attr1 = Napi::Array::New(env);
	for(int i = 0; i < 10; i++) {
		geopos1[i] = Napi::Number::New(env, geopos[i]);
	}
	for(int i = 0; i < 11; i++) {
		attr1[i] = Napi::Number::New(env, attr[i]);
	}
	obj.Set(Napi::String::New(env, "coordinates"), geopos1);
	obj.Set(Napi::String::New(env, "attributes"), attr1);
	obj.Set(Napi::String::New(env, "flag"), Napi::Number::New(env, flag));
	obj.Set(Napi::String::New(env, "error"), Napi::String::New(env, serr));
	return obj;
}

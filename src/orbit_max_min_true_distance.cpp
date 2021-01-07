#include "sweph.h"

Napi::Value sweph_orbit_max_min_true_distance(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(info.Length() < 3) {
		Napi::TypeError::New(env, "Expecting 3 arguments").ThrowAsJavaScriptException();
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
	double dmax;
	double dmin;
	double dtrue;
	char serr [SE_MAX_STNAME];
	int flag = swe_orbit_max_min_true_distance(
		info[0].As<Napi::Number>().DoubleValue(),
		info[1].As<Napi::Number>().Int32Value(),
		info[2].As<Napi::Number>().Int32Value(),
		&dmax,
		&dmin,
		&dtrue,
		serr
	);
	Napi::Object obj = Napi::Object::New(env);
	obj.Set(Napi::String::New(env, "max"), Napi::Number::New(env, dmax));
	obj.Set(Napi::String::New(env, "min"), Napi::Number::New(env, dmin));
	obj.Set(Napi::String::New(env, "true"), Napi::Number::New(env, dtrue));
	obj.Set(Napi::String::New(env, "flag"), Napi::Number::New(env, flag));
	obj.Set(Napi::String::New(env, "error"), Napi::String::New(env, serr));
	return obj;
}

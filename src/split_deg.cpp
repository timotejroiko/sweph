#include "sweph.h"

Napi::Value sweph_split_deg(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(info.Length() < 1) {
		Napi::TypeError::New(env, "Expecting 1 argument").ThrowAsJavaScriptException();
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
	int deg;
	int min;
	int sec;
	double fraction;
	int sign;
	swe_split_deg(
		info[0].As<Napi::Number>().DoubleValue(),
		info[1].As<Napi::Number>().Int32Value(),
		&deg,
		&min,
		&sec,
		&fraction,
		&sign
	);
	Napi::Object obj = Napi::Object::New(env);
	obj.Set(Napi::String::New(env, "degree"), Napi::Number::New(env, deg));
	obj.Set(Napi::String::New(env, "minute"), Napi::Number::New(env, min));
	obj.Set(Napi::String::New(env, "second"), Napi::Number::New(env, sec));
	obj.Set(Napi::String::New(env, "fraction"), Napi::Number::New(env, fraction));
	obj.Set(Napi::String::New(env, "sign"), Napi::Number::New(env, sign));
	return obj;
}

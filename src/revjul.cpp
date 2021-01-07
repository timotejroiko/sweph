#include "sweph.h"

Napi::Value sweph_revjul(const Napi::CallbackInfo& info) {
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
	int year;
	int month;
	int day;
	double time;
	swe_revjul(
		info[0].As<Napi::Number>().DoubleValue(),
		info[1].As<Napi::Number>().Int32Value(),
		&year,
		&month,
		&day,
		&time
	);
	Napi::Object obj = Napi::Object::New(env);
	obj.Set(Napi::String::New(env, "year"), Napi::Number::New(env, year));
	obj.Set(Napi::String::New(env, "month"), Napi::Number::New(env, month));
	obj.Set(Napi::String::New(env, "day"), Napi::Number::New(env, day));
	obj.Set(Napi::String::New(env, "hour"), Napi::Number::New(env, time));
	return obj;
}

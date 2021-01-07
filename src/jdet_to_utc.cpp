#include "sweph.h"

Napi::Value sweph_jdet_to_utc(const Napi::CallbackInfo& info) {
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
	int hour;
	int minute;
	double seconds;
	swe_jdet_to_utc(
		info[0].As<Napi::Number>().DoubleValue(),
		info[1].As<Napi::Number>().Int32Value(),
		&year,
		&month,
		&day,
		&hour,
		&minute,
		&seconds
	);
	Napi::Object obj = Napi::Object::New(env);
	obj.Set(Napi::String::New(env, "year"), Napi::Number::New(env, year));
	obj.Set(Napi::String::New(env, "month"), Napi::Number::New(env, month));
	obj.Set(Napi::String::New(env, "day"), Napi::Number::New(env, day));
	obj.Set(Napi::String::New(env, "hour"), Napi::Number::New(env, hour));
	obj.Set(Napi::String::New(env, "minute"), Napi::Number::New(env, minute));
	obj.Set(Napi::String::New(env, "seconds"), Napi::Number::New(env, seconds));
	return obj;
}

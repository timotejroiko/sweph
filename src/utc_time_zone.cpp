#include "sweph.h"

Napi::Value sweph_utc_time_zone(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(info.Length() < 7) {
		Napi::TypeError::New(env, "Expecting 7 arguments").ThrowAsJavaScriptException();
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
	if(!info[4].IsNumber()) {
		Napi::TypeError::New(env, "Argument 5 should be a number").ThrowAsJavaScriptException();
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
	int year;
	int month;
	int day;
	int hour;
	int minute;
	double seconds;
	swe_utc_time_zone(
		info[0].As<Napi::Number>().Int32Value(),
		info[1].As<Napi::Number>().Int32Value(),
		info[2].As<Napi::Number>().Int32Value(),
		info[3].As<Napi::Number>().Int32Value(),
		info[4].As<Napi::Number>().Int32Value(),
		info[5].As<Napi::Number>().DoubleValue(),
		info[6].As<Napi::Number>().DoubleValue(),
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

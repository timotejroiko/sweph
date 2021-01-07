#include "sweph.h"

Napi::Value sweph_rise_trans_true_hor(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(info.Length() < 9) {
		Napi::TypeError::New(env, "Expecting 9 arguments").ThrowAsJavaScriptException();
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
		Napi::TypeError::New(env, "Argument 5 should be a number").ThrowAsJavaScriptException();
		return env.Null();
	}
	if(!info[5].IsArray()) {
		Napi::TypeError::New(env, "Argument 6 should be an array of 3 numbers").ThrowAsJavaScriptException();
		return env.Null();
	}
	if(!info[6].IsNumber()) {
		Napi::TypeError::New(env, "Argument 7 should be a number").ThrowAsJavaScriptException();
		return env.Null();
	}
	if(!info[7].IsNumber()) {
		Napi::TypeError::New(env, "Argument 8 should be a number").ThrowAsJavaScriptException();
		return env.Null();
	}
	if(!info[8].IsNumber()) {
		Napi::TypeError::New(env, "Argument 9 should be a number").ThrowAsJavaScriptException();
		return env.Null();
	}
	Napi::Array geo = info[5].As<Napi::Array>();
	double geopos [3];
	for(int i = 0; i < 3; i++) {
		if(!((Napi::Value)geo[i]).IsNumber()) {
			Napi::TypeError::New(env, "Argument 6 should be an array of 3 numbers").ThrowAsJavaScriptException();
			return env.Null();
		}
		geopos[i] = ((Napi::Value)geo[i]).As<Napi::Number>().DoubleValue();
	}
	double ret;
	char serr [SE_MAX_STNAME];
	int flag = swe_rise_trans_true_hor(
		info[0].As<Napi::Number>().DoubleValue(),
		info[1].As<Napi::Number>().Int32Value(),
		(info[2].IsString()) ? const_cast<char*>(info[2].As<Napi::String>().Utf8Value().c_str()) : NULL,
		info[3].As<Napi::Number>().Int32Value(),
		info[4].As<Napi::Number>().Int32Value(),
		geopos,
		info[6].As<Napi::Number>().DoubleValue(),
		info[7].As<Napi::Number>().DoubleValue(),
		info[8].As<Napi::Number>().DoubleValue(),
		&ret,
		serr
	);
	Napi::Object obj = Napi::Object::New(env);
	obj.Set(Napi::String::New(env, "flag"), Napi::Number::New(env, flag));
	obj.Set(Napi::String::New(env, "error"), Napi::String::New(env, serr));
	obj.Set(Napi::String::New(env, "time"), Napi::Number::New(env, ret));
	return obj;
}

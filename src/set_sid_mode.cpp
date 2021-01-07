#include "sweph.h"

void sweph_set_sid_mode(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(info.Length() < 3) {
		Napi::TypeError::New(env, "Expecting 3 arguments").ThrowAsJavaScriptException();
		return;
	}
	if(!info[0].IsNumber()) {
		Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
		return;
	}
	if(!info[1].IsNumber()) {
		Napi::TypeError::New(env, "Argument 2 should be a number").ThrowAsJavaScriptException();
		return;
	}
	if(!info[2].IsNumber()) {
		Napi::TypeError::New(env, "Argument 3 should be a number").ThrowAsJavaScriptException();
		return;
	}
	swe_set_sid_mode(
		info[0].As<Napi::Number>().Int32Value(),
		info[1].As<Napi::Number>().DoubleValue(),
		info[2].As<Napi::Number>().DoubleValue()
	);
	return;
}

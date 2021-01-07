#include "sweph.h"

void sweph_set_delta_t_userdef(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(info.Length() < 1) {
		Napi::TypeError::New(env, "Expecting 1 argument").ThrowAsJavaScriptException();
		return;
	}
	if(!info[0].IsNumber()) {
		Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
		return;
	}
	swe_set_delta_t_userdef(info[0].As<Napi::Number>().DoubleValue());
	return;
}

#include <sweph.h>

Napi::Number sweph_get_tid_acc(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	double val = swe_get_tid_acc();
	return Napi::Number::New(env, val);
}

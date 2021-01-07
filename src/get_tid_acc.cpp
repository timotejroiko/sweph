#include "sweph.h"

Napi::Number sweph_get_tid_acc(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	return Napi::Number::New(env, swe_get_tid_acc());
}

#include <sweph.h>

Napi::Number sweph_get_denum(const Napi::CallbackInfo& info) {
	return Napi::Number::New(info.Env(), swe_get_denum());
}

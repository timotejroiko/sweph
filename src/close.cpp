#include "sweph.h"

void sweph_close(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    swe_close();
	return;
}

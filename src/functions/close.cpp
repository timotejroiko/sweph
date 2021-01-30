#include <sweph.h>

void sweph_close(const Napi::CallbackInfo& info) {
	swe_close();
	return;
}

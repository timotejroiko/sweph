#include <sweph.h>

constexpr std::pair<int, const char*> args[] = {
	{ 1, "Expecting 1 argument: do_interpolate" },
	{ TRUEFALSE, "Argument 1 should be a boolean - enable/disable nutation interpolation" }
};

void sweph_set_interpolate_nut(const Napi::CallbackInfo& info) {
	if(!sweph_type_check(args, info)) {
		return;
	}
	swe_set_interpolate_nut(info[0].As<Napi::Boolean>());
	return;
}

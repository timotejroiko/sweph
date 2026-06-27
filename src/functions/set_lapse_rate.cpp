#include <sweph.h>

constexpr std::pair<int, const char*> args[] = {
	{ 1, "Expecting 1 arguments: lapse_rate" },
	{ NUMBER, "Argument 1 should be a number - lapse rate [°K/m]" }
};

void sweph_set_lapse_rate(const Napi::CallbackInfo& info) {
	if(!sweph_type_check(args, info)) {
		return;
	}
	swe_set_lapse_rate(info[0].As<Napi::Number>().DoubleValue());
	return;
}

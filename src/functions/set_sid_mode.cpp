#include <sweph.h>

constexpr std::pair<int, const char*> args[] = {
	{ 3, "Expecting 3 arguments: sid_mode, t0, ayan_t0" },
	{ NUMBER, "Argument 1 should be a number - ayanamsa ID" },
	{ NUMBER, "Argument 2 should be a number - reference date in julian days universal time" },
	{ NUMBER, "Argument 3 should be a number - initial value in degrees" }
};

void sweph_set_sid_mode(const Napi::CallbackInfo& info) {
	if(!sweph_type_check(args, info)) {
		return;
	}
	swe_set_sid_mode(
		info[0].As<Napi::Number>().Int32Value(),
		info[1].As<Napi::Number>().DoubleValue(),
		info[2].As<Napi::Number>().DoubleValue()
	);
	return;
}

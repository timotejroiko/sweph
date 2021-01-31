#include <sweph.h>

constexpr std::pair<int, const char*> args[] = {
	{ 1, "Expecting 1 arguments: t_acc" },
	{ NUMBER, "Argument 1 should be a number - tidal acceleration value" }
};

void sweph_set_tid_acc(const Napi::CallbackInfo& info) {
	if(!sweph_type_check(args, info)) {
		return;
	}
	swe_set_tid_acc(info[0].As<Napi::Number>().DoubleValue());
	return;
}

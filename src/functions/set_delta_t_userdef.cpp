#include <sweph.h>

static std::vector<std::pair<int, std::string>> args = {
	{ 1, "Expecting 1 arguments: t_acc" },
	{ NUMBER, "Argument 1 should be a number - delta T value" }
};

void sweph_set_delta_t_userdef(const Napi::CallbackInfo& info) {
	if(!sweph_type_check(args, info)) {
		return;
	}
	swe_set_delta_t_userdef(info[0].As<Napi::Number>().DoubleValue());
	return;
}

#include <sweph.h>

constexpr std::pair<int, const char*> args[] = {
	{ 2, "Expecting 2 arguments: samod, iflag" },
	{ STRING, "Argument 1 should be a string - astronomical model string or SE version" },
	{ NUMBER, "Argument 2 should be a number - calculation flags" }
};

void sweph_set_astro_models(const Napi::CallbackInfo& info) {
	if(!sweph_type_check(args, info)) {
		return;
	}
	std::string samod = info[0].As<Napi::String>().Utf8Value();
	swe_set_astro_models(samod.data(), info[1].As<Napi::Number>().Int32Value());
	return;
}

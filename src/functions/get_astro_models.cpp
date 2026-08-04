#include <sweph.h>

constexpr std::pair<int, const char*> args[] = {
	{ 2, "Expecting 2 arguments: samod, iflag" },
	{ STRING, "Argument 1 should be a string - astronomical model string or SE version" },
	{ NUMBER, "Argument 2 should be a number - calculation flags" }
};

Napi::Value sweph_get_astro_models(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(!sweph_type_check(args, info)) {
		return env.Null();
	}
	std::string samod = info[0].As<Napi::String>().Utf8Value();
	char sdet [10000] = "";
	swe_get_astro_models(samod.data(), sdet, info[1].As<Napi::Number>().Int32Value());
	return Napi::String::New(env, sdet);
}

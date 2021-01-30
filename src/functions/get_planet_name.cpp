#include <sweph.h>

static std::vector<std::pair<int, std::string>> args = {
	{ 1, "Expecting 1 argument: ipl" },
	{ NUMBER, "Argument 1 should be a number - object ID" }
};

Napi::Value sweph_get_planet_name(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(!sweph_type_check(args, info)) {
		return env.Null();
	}
	char planet [SE_MAX_STNAME];
	swe_get_planet_name(
		info[0].As<Napi::Number>().Int32Value(),
		planet
	);
	return Napi::String::New(env, planet);
}

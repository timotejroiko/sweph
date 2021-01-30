#include <sweph.h>

static std::vector<std::pair<int, std::string>> args = {
	{ 1, "Expecting 1 argument: tjd" },
	{ NUMBER, "Argument 1 should be a number - julian day in universal time" }
};

Napi::Value sweph_deltat(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(!sweph_type_check(args, info)) {
		return env.Null();
	}
	double delta = swe_deltat(info[0].As<Napi::Number>().DoubleValue());
	return Napi::Number::New(env, delta);
}

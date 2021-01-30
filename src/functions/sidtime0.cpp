#include <sweph.h>

static std::vector<std::pair<int, std::string>> args = {
	{ 3, "Expecting 3 arguments: tjd_ut, eps, nut" },
	{ NUMBER, "Argument 1 should be a number - julian day in universal time" },
	{ NUMBER, "Argument 2 should be a number - obliquity of the ecliptic" },
	{ NUMBER, "Argument 3 should be a number - nutation" }
};

Napi::Value sweph_sidtime0(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(!sweph_type_check(args, info)) {
		return env.Null();
	}
	double time = swe_sidtime0(
		info[0].As<Napi::Number>().DoubleValue(),
		info[1].As<Napi::Number>().DoubleValue(),
		info[2].As<Napi::Number>().DoubleValue()
	);
	return Napi::Number::New(env, time);
}

#include <sweph.h>

constexpr std::pair<int, const char*> args[] = {
	{ 1, "Expecting 1 argument: tjd_et" },
	{ NUMBER, "Argument 1 should be a number - julian day in ephemeris/terrestrial time" }
};

Napi::Value sweph_get_ayanamsa(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(!sweph_type_check(args, info)) {
		return env.Null();
	}
	double val = swe_get_ayanamsa(info[0].As<Napi::Number>().DoubleValue());
	return Napi::Number::New(env, val);
}

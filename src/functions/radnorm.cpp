#include <sweph.h>

constexpr std::pair<int, const char*> args[] = {
	{ 1, "Expecting 1 arguments: drad" },
	{ NUMBER, "Argument 1 should be a number - degrees in radians" }
};

Napi::Value sweph_radnorm(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(!sweph_type_check(args, info)) {
		return env.Null();
	}
	double rad = swe_radnorm(info[0].As<Napi::Number>().DoubleValue());
	return Napi::Number::New(env, rad);
}

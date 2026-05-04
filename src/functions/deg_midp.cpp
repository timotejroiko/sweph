#include <sweph.h>

constexpr std::pair<int, const char*> args[] = {
	{ 2, "Expecting 2 arguments: deg1, deg2" },
	{ NUMBER, "Argument 1 should be a number - first point in degrees" },
	{ NUMBER, "Argument 2 should be a number - second point in degrees" }
};

Napi::Value sweph_deg_midp(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(!sweph_type_check(args, info)) {
		return env.Null();
	}
	double mid = swe_deg_midp(
		info[0].As<Napi::Number>().DoubleValue(),
		info[1].As<Napi::Number>().DoubleValue()
	);
	return Napi::Number::New(env, mid);
}

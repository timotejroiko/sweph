#include <sweph.h>

constexpr std::pair<int, const char*> args[] = {
	{ 2, "Expecting 2 arguments: rad, rad" },
	{ NUMBER, "Argument 1 should be a number - radians" },
	{ NUMBER, "Argument 2 should be a number - radians" }
};

Napi::Value sweph_difrad2n(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(!sweph_type_check(args, info)) {
		return env.Null();
	}
	double dif = swe_difrad2n(
		info[0].As<Napi::Number>().DoubleValue(),
		info[1].As<Napi::Number>().DoubleValue()
	);
	return Napi::Number::New(env, dif);
}

#include <sweph.h>

constexpr std::pair<int, const char*> args[] = {
	{ 2, "Expecting 2 arguments: deg, deg" },
	{ NUMBER, "Argument 1 should be a number - decimal degrees" },
	{ NUMBER, "Argument 2 should be a number - decimal degrees" }
};

Napi::Value sweph_difdeg2n(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(!sweph_type_check(args, info)) {
		return env.Null();
	}
	double dif = swe_difdeg2n(
		info[0].As<Napi::Number>().DoubleValue(),
		info[1].As<Napi::Number>().DoubleValue()
	);
	return Napi::Number::New(env, dif);
}

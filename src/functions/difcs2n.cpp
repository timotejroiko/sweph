#include <sweph.h>

constexpr std::pair<int, const char*> args[] = {
	{ 2, "Expecting 2 arguments: csec, csec" },
	{ NUMBER, "Argument 1 should be a number - degrees in centiseconds" },
	{ NUMBER, "Argument 2 should be a number - degrees in centiseconds" }
};

Napi::Value sweph_difcs2n(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(!sweph_type_check(args, info)) {
		return env.Null();
	}
	int32 dif = swe_difcs2n(
		info[0].As<Napi::Number>().Int32Value(),
		info[1].As<Napi::Number>().Int32Value()
	);
	return Napi::Number::New(env, dif);
}

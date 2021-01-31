#include <sweph.h>

constexpr std::pair<int, const char*> args[] = {
	{ 1, "Expecting 1 argument: double" },
	{ NUMBER, "Argument 1 should be a number - double value" }
};

Napi::Value sweph_d2l(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(!sweph_type_check(args, info)) {
		return env.Null();
	}
	long val = swe_d2l(info[0].As<Napi::Number>().DoubleValue());
	return Napi::Number::New(env, val);
}

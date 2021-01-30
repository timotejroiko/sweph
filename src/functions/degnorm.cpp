#include <sweph.h>

static std::vector<std::pair<int, std::string>> args = {
	{ 1, "Expecting 1 argument: deg" },
	{ NUMBER, "Argument 1 should be a number: decimal degrees" }
};

Napi::Value sweph_degnorm(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(!sweph_type_check(args, info)) {
		return env.Null();
	}
	double val = swe_degnorm(info[0].As<Napi::Number>().DoubleValue());
	return Napi::Number::New(env, val);
}

#include <sweph.h>

static std::vector<std::pair<int, std::string>> args = {
	{ 1, "Expecting 1 argument: jd" },
	{ NUMBER, "Argument 1 should be a number - julian day" }
};

Napi::Value sweph_day_of_week(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(!sweph_type_check(args, info)) {
		return env.Null();
	}
	int val = swe_day_of_week(info[0].As<Napi::Number>().DoubleValue());
	return Napi::Number::New(env, val);
}

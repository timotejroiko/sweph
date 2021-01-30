#include <sweph.h>

static std::vector<std::pair<int, std::string>> args = {
	{ 2, "Expecting 2 arguments: deg, deg" },
	{ NUMBER, "Argument 1 should be a number - decimal degrees" },
	{ NUMBER, "Argument 2 should be a number - decimal degrees" }
};

Napi::Value sweph_difdegn(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(!sweph_type_check(args, info)) {
		return env.Null();
	}
	double dif = swe_difdegn(
		info[0].As<Napi::Number>().DoubleValue(),
		info[1].As<Napi::Number>().DoubleValue()
	);
	return Napi::Number::New(env, dif);
}

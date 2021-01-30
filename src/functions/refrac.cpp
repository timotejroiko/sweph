#include <sweph.h>

static std::vector<std::pair<int, std::string>> args = {
	{ 4, "Expecting 4 arguments: inalt, atpress, attemp, calc_flag" },
	{ NUMBER, "Argument 1 should be a number - altitude above horizon in degrees" },
	{ NUMBER, "Argument 2 should be a number - atmospheric pressure in mbar/hpa" },
	{ NUMBER, "Argument 3 should be a number - atmospheric temperature in celsius" },
	{ NUMBER, "Argument 4 should be a number - calculation flag" }
};

Napi::Value sweph_refrac(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(!sweph_type_check(args, info)) {
		return env.Null();
	}
	double out = swe_refrac(
		info[0].As<Napi::Number>().DoubleValue(),
		info[1].As<Napi::Number>().DoubleValue(),
		info[2].As<Napi::Number>().DoubleValue(),
		info[3].As<Napi::Number>().Int32Value()
	);
	return Napi::Number::New(env, out);
}

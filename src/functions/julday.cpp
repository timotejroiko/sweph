#include <sweph.h>

static std::vector<std::pair<int, std::string>> args = {
	{ 5, "Expecting 5 arguments: year, month, day, hour, gregflag" },
	{ NUMBER, "Argument 1 should be a number - full year" },
	{ NUMBER, "Argument 2 should be a number - month 1-12" },
	{ NUMBER, "Argument 3 should be a number - day 1-31" },
	{ NUMBER, "Argument 4 should be a number - decimal hour 0-23.999" },
	{ NUMBER, "Argument 5 should be a number - calendar system, 1 for GREG_CAL, 0 for JUL_CAL" }
};

Napi::Value sweph_julday(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(!sweph_type_check(args, info)) {
		return env.Null();
	}
	double time = swe_julday(
		info[0].As<Napi::Number>().Int32Value(),
		info[1].As<Napi::Number>().Int32Value(),
		info[2].As<Napi::Number>().Int32Value(),
		info[3].As<Napi::Number>().DoubleValue(),
		info[4].As<Napi::Number>().Int32Value()
	);
	return Napi::Number::New(env, time);
}

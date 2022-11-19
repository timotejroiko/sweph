#include <sweph.h>

constexpr std::pair<int, const char*> args[] = {
	{ 7, "Expecting 7 arguments: iyear, imonth, iday, ihour, imin, dsec, gregflag" },
	{ NUMBER, "Argument 1 should be a number - full year" },
	{ NUMBER, "Argument 2 should be a number - month 1-12" },
	{ NUMBER, "Argument 3 should be a number - day 1-31" },
	{ NUMBER, "Argument 4 should be a number - hour 0-23" },
	{ NUMBER, "Argument 5 should be a number - minutes 0-59" },
	{ NUMBER, "Argument 6 should be a number - seconds 0-59.999" },
	{ NUMBER, "Argument 7 should be a number - calendar system, 1 for SE_GREG_CAL, 0 for SE_JUL_CAL" }
};

Napi::Value sweph_utc_to_jd(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(!sweph_type_check(args, info)) {
		return env.Null();
	}
	double ret [2];
	char serr [AS_MAXCH] = "";
	int32 flag = swe_utc_to_jd(
		info[0].As<Napi::Number>().Int32Value(),
		info[1].As<Napi::Number>().Int32Value(),
		info[2].As<Napi::Number>().Int32Value(),
		info[3].As<Napi::Number>().Int32Value(),
		info[4].As<Napi::Number>().Int32Value(),
		info[5].As<Napi::Number>().DoubleValue(),
		info[6].As<Napi::Number>().Int32Value(),
		ret,
		serr
	);
	Napi::Object obj = Napi::Object::New(env);
	obj["flag"] = flag;
	obj["error"] = serr;
	obj["data"] = sweph_js_array_converter(ret, 2, env);
	return obj;
}

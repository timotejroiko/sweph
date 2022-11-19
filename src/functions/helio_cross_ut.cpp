#include <sweph.h>

constexpr std::pair<int, const char*> args[] = {
	{ 5, "Expecting 5 arguments: ipl, x2cross, jd_ut, flag, dir" },
	{ NUMBER, "Argument 1 should be a number - object ID" },
	{ NUMBER, "Argument 2 should be a number - longitude position to search for" },
	{ NUMBER, "Argument 3 should be a number - start time in julian day in universal time" },
	{ NUMBER, "Argument 4 should be a number - calculation flag" },
	{ NUMBER, "Argument 5 should be a number - direction to search, 0 = forwards, -1 = backwards" }
};

Napi::Value sweph_helio_cross_ut(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(!sweph_type_check(args, info)) {
		return env.Null();
	}
	char serr [AS_MAXCH] = "";
	double jd_cross;
	int32 flag = swe_helio_cross_ut(
		info[0].As<Napi::Number>().Int32Value(),
		info[1].As<Napi::Number>().DoubleValue(),
		info[2].As<Napi::Number>().Int32Value(),
		info[3].As<Napi::Number>().Int32Value(),
		info[4].As<Napi::Number>().Int32Value(),
		&jd_cross,
		serr
	);
	Napi::Object obj = Napi::Object::New(env);
	obj["date"] = jd_cross;
	obj["flag"] = flag;
	obj["error"] = serr;
	return obj;
}

#include <sweph.h>

constexpr std::pair<int, const char*> args[] = {
	{ 3, "Expecting 3 arguments: x2cross, jd_ut, flag" },
	{ NUMBER, "Argument 1 should be a number - longitude position to search for" },
	{ NUMBER, "Argument 2 should be a number - start time in julian day in universal time" },
	{ NUMBER, "Argument 3 should be a number - calculation flag" }
};

Napi::Value sweph_solcross_ut(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(!sweph_type_check(args, info)) {
		return env.Null();
	}
	char serr [AS_MAXCH];
	double jd_ut = swe_solcross_ut(
		info[0].As<Napi::Number>().DoubleValue(),
		info[1].As<Napi::Number>().DoubleValue(),
		info[2].As<Napi::Number>().Int32Value(),
		serr
	);
	Napi::Object obj = Napi::Object::New(env);
	obj["date"] = jd_ut;
	obj["error"] = serr;
	return obj;
}

#include <sweph.h>

constexpr std::pair<int, const char*> args[] = {
	{ 3, "Expecting 3 arguments: x2cross, jd_et, flag" },
	{ NUMBER, "Argument 1 should be a number - longitude position to search for" },
	{ NUMBER, "Argument 2 should be a number - start time in julian day in ephemeris/terrestrial time" },
	{ NUMBER, "Argument 3 should be a number - calculation flag" }
};

Napi::Value sweph_mooncross(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(!sweph_type_check(args, info)) {
		return env.Null();
	}
	char serr [AS_MAXCH];
	double jd_et = swe_mooncross(
		info[0].As<Napi::Number>().DoubleValue(),
		info[1].As<Napi::Number>().DoubleValue(),
		info[2].As<Napi::Number>().Int32Value(),
		serr
	);
	Napi::Object obj = Napi::Object::New(env);
	obj["date"] = jd_et;
	obj["error"] = serr;
	return obj;
}

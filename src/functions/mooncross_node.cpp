#include <sweph.h>

constexpr std::pair<int, const char*> args[] = {
	{ 2, "Expecting 2 arguments: jd_et, flag" },
	{ NUMBER, "Argument 1 should be a number - start time in julian day in ephemeris/terrestrial time" },
	{ NUMBER, "Argument 2 should be a number - calculation flag" }
};

Napi::Value sweph_mooncross_node(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(!sweph_type_check(args, info)) {
		return env.Null();
	}
	char serr [AS_MAXCH] = "";
	double xlon;
	double xlat;
	double jd_et = swe_mooncross_node(
		info[0].As<Napi::Number>().DoubleValue(),
		info[1].As<Napi::Number>().Int32Value(),
		&xlon,
		&xlat,
		serr
	);
	Napi::Object obj = Napi::Object::New(env);
	obj["date"] = jd_et;
	obj["error"] = serr;
	obj["longitude"] = xlon;
	obj["latitude"] = xlat;
	return obj;
}

#include <sweph.h>

constexpr std::pair<int, const char*> args[] = {
	{ 3, "Expecting 3 arguments: tjd_et, ipl, iflag" },
	{ NUMBER, "Argument 1 should be a number - julian day in ephemeris/terrestrial time" },
	{ NUMBER, "Argument 2 should be a number - target object ID" },
	{ NUMBER, "Argument 3 should be a number - calculation flag" }
};

Napi::Value sweph_orbit_max_min_true_distance(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(!sweph_type_check(args, info)) {
		return env.Null();
	}
	double dmax;
	double dmin;
	double dtrue;
	char serr [AS_MAXCH];
	int32 flag = swe_orbit_max_min_true_distance(
		info[0].As<Napi::Number>().DoubleValue(),
		info[1].As<Napi::Number>().Int32Value(),
		info[2].As<Napi::Number>().Int32Value(),
		&dmax,
		&dmin,
		&dtrue,
		serr
	);
	Napi::Object data = Napi::Object::New(env);
	data["max"] = dmax;
	data["min"] = dmin;
	data["true"] = dtrue;
	Napi::Object obj = Napi::Object::New(env);
	obj["flag"] = flag;
	obj["error"] = serr;
	obj["data"] = data;
	return obj;
}

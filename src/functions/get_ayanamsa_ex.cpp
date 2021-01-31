#include <sweph.h>

constexpr std::pair<int, const char*> args[] = {
	{ 2, "Expecting 2 argument: tjd_et, ephe_flag" },
	{ NUMBER, "Argument 1 should be a number - julian day in ephemeris/terrestrial time" },
	{ NUMBER, "Argument 2 should be a number - ephemeris flag" }
};

Napi::Value sweph_get_ayanamsa_ex(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(!sweph_type_check(args, info)) {
		return env.Null();
	}
	double aya;
	char serr [SE_MAX_STNAME];
	int flag = swe_get_ayanamsa_ex(
		info[0].As<Napi::Number>().DoubleValue(),
		info[1].As<Napi::Number>().Int32Value(),
		&aya,
		serr
	);
	Napi::Object obj = Napi::Object::New(env);
	obj["flag"] = flag;
	obj["error"] = serr;
	obj["data"] = aya;
	return obj;
}

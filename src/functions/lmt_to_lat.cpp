#include <sweph.h>

constexpr std::pair<int, const char*> args[] = {
	{ 2, "Expecting 2 arguments: tjd_lmt, geolon" },
	{ NUMBER, "Argument 1 should be a number - julian day in local mean time" },
	{ NUMBER, "Argument 2 should be a number - geographic longitude" }
};

Napi::Value sweph_lmt_to_lat(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(!sweph_type_check(args, info)) {
		return env.Null();
	}
	double conv;
	char serr [SE_MAX_STNAME];
	int flag = swe_lmt_to_lat(
		info[0].As<Napi::Number>().DoubleValue(),
		info[1].As<Napi::Number>().DoubleValue(),
		&conv,
		serr
	);
	Napi::Object obj = Napi::Object::New(env);
	obj["flag"] = flag;
	obj["serr"] = serr;
	obj["data"] = conv;
	return obj;
}
#include <sweph.h>

constexpr std::pair<int, const char*> args[] = {
	{ 2, "Expecting 2 arguments: tjd_lat, geolon" },
	{ NUMBER, "Argument 1 should be a number - julian day in local apparent time" },
	{ NUMBER, "Argument 2 should be a number - geographic longitude" }
};

Napi::Value sweph_lat_to_lmt(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(!sweph_type_check(args, info)) {
		return env.Null();
	}
	double conv;
	char serr [AS_MAXCH] = "";
	int32 flag = swe_lat_to_lmt(
		info[0].As<Napi::Number>().DoubleValue(),
		info[1].As<Napi::Number>().DoubleValue(),
		&conv,
		serr
	);
	Napi::Object obj = Napi::Object::New(env);
	obj["flag"] = flag;
	obj["error"] = serr;
	obj["data"] = conv;
	return obj;
}

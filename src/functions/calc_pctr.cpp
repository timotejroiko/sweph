#include <sweph.h>

static std::vector<std::pair<int, std::string>> args = {
	{ 4, "Expecting 4 arguments: tjd, ipl, iplctr, iflag" },
	{ NUMBER, "Argument 1 should be a number - julian day in terrestrial/ephemeris time" },
	{ NUMBER, "Argument 2 should be a number - target object ID" },
	{ NUMBER, "Argument 3 should be a number - center object ID" },
	{ NUMBER, "Argument 4 should be a number - calculation flag" }
};

Napi::Value sweph_calc_pctr(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(!sweph_type_check(args, info)) {
		return env.Null();
	}
	double xx [6];
	char serr [SE_MAX_STNAME];
	int flag = swe_calc_pctr(
		info[0].As<Napi::Number>().DoubleValue(),
		info[1].As<Napi::Number>().Int32Value(),
		info[2].As<Napi::Number>().Int32Value(),
		info[3].As<Napi::Number>().Int32Value(),
		xx,
		serr
	);
	Napi::Object obj = Napi::Object::New(env);
	obj["flag"] = flag;
	obj["error"] = serr;
	obj["data"] = sweph_js_array_converter(xx, 6, env);
	return obj;
}

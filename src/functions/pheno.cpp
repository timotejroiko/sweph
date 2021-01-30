#include <sweph.h>

static std::vector<std::pair<int, std::string>> args = {
	{ 3, "Expecting 3 arguments: tjd_et, ipl, iflag" },
	{ NUMBER, "Argument 1 should be a number - julian day in ephemeris/terrestrial time" },
	{ NUMBER, "Argument 2 should be a number - target object ID" },
	{ NUMBER, "Argument 3 should be a number - calculation flag" }
};

Napi::Value sweph_pheno(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(!sweph_type_check(args, info)) {
		return env.Null();
	}
	double attr [20];
	char serr [SE_MAX_STNAME];
	int flag = swe_pheno(
		info[0].As<Napi::Number>().DoubleValue(),
		info[1].As<Napi::Number>().Int32Value(),
		info[2].As<Napi::Number>().Int32Value(),
		attr,
		serr
	);
	Napi::Object obj = Napi::Object::New(env);
	obj["data"] = sweph_js_array_converter(attr, 5, env);
	obj["flag"] = flag;
	obj["error"] = serr;
	return obj;
}

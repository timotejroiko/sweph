#include <sweph.h>

static std::vector<std::pair<int, std::string>> args = {
	{ 4, "Expecting 4 arguments: tjd_ut, ipl, iflag, method" },
	{ NUMBER, "Argument 1 should be a number - julian day in universal time" },
	{ NUMBER, "Argument 2 should be a number - target object ID" },
	{ NUMBER, "Argument 3 should be a number - calculation flag" },
	{ NUMBER, "Argument 4 should be a number - calculation method" }
};

Napi::Value sweph_nod_aps_ut(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(!sweph_type_check(args, info)) {
		return env.Null();
	}
	double asc [6];
	double dsc [6];
	double per [6];
	double aph [6];
	char serr [SE_MAX_STNAME];
	int flag = swe_nod_aps_ut(
		info[0].As<Napi::Number>().DoubleValue(),
		info[1].As<Napi::Number>().Int32Value(),
		info[2].As<Napi::Number>().Int32Value(),
		info[3].As<Napi::Number>().Int32Value(),
		asc,
		dsc,
		per,
		aph,
		serr
	);
	Napi::Object data = Napi::Object::New(env);
	data["ascending"] = sweph_js_array_converter(asc, 6, env);
	data["descending"] = sweph_js_array_converter(dsc, 6, env);
	data["perihelion"] = sweph_js_array_converter(per, 6, env);
	data["aphelion"] = sweph_js_array_converter(aph, 6, env);
	Napi::Object obj = Napi::Object::New(env);
	obj["flag"] = flag;
	obj["error"] = serr;
	obj["data"] = data;
	return obj;
}

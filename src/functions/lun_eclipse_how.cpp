#include <sweph.h>

constexpr std::pair<int, const char*> args[] = {
	{ 3, "Expecting 3 arguments: tjd_ut, ifl, geopos" },
	{ NUMBER, "Argument 1 should be a number - julian day in universal time" },
	{ NUMBER, "Argument 2 should be a number - ephemeris flag" },
	{ ARRAY, "Argument 3 should be an array of 3 numbers - geographic coordinates [longitude, latitude, elevation]" }
};

Napi::Value sweph_lun_eclipse_how(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(!sweph_type_check(args, info)) {
		return env.Null();
	}
	double geopos [3];
	if(!sweph_double_array_converter(geopos, 3, info[2])) {
		Napi::TypeError::New(env, args[3].second).ThrowAsJavaScriptException();
		return env.Null();
	}
	double attr [20];
	char serr [AS_MAXCH] = "";
	int32 flag = swe_lun_eclipse_how(
		info[0].As<Napi::Number>().DoubleValue(),
		info[1].As<Napi::Number>().Int32Value(),
		geopos,
		attr,
		serr
	);
	Napi::Object obj = Napi::Object::New(env);
	obj["flag"] = flag;
	obj["error"] = serr;
	obj["data"] = sweph_js_array_converter(attr, 11, env);
	return obj;
}

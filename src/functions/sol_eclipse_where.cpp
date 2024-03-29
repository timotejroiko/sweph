#include <sweph.h>

constexpr std::pair<int, const char*> args[] = {
	{ 2, "Expecting 2 arguments: tjd_ut, ifl" },
	{ NUMBER, "Argument 1 should be a number - julian day in universal time" },
	{ NUMBER, "Argument 2 should be a number - target object ID" }
};

Napi::Value sweph_sol_eclipse_where(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(!sweph_type_check(args, info)) {
		return env.Null();
	}
	double geopos [10];
	double attr [20];
	char serr [AS_MAXCH] = "";
	int32 flag = swe_sol_eclipse_where(
		info[0].As<Napi::Number>().DoubleValue(),
		info[1].As<Napi::Number>().Int32Value(),
		geopos,
		attr,
		serr
	);
	Napi::Object obj = Napi::Object::New(env);
	obj["flag"] = flag;
	obj["error"] = serr;
	obj["data"] = sweph_js_array_converter(geopos, 10, env);
	obj["attributes"] = sweph_js_array_converter(attr, 11, env);
	return obj;
}

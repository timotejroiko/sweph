#include <sweph.h>

static std::vector<std::pair<int, std::string>> args = {
	{ 4, "Expecting 4 arguments: tjd_start, ifl, geopos, backward" },
	{ NUMBER, "Argument 1 should be a number - julian day in universal time" },
	{ NUMBER, "Argument 2 should be a number - target object ID" },
	{ ARRAY, "Argument 3 should be an array of 3 numbers - geographic coordinates [longitude, latitude, elevation]" },
	{ TRUEFALSE, "Argument 4 should be a boolean - backwards search" }
};

Napi::Value sweph_sol_eclipse_when_loc(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(!sweph_type_check(args, info)) {
		return env.Null();
	}
	double geopos [3];
	if(!sweph_double_array_converter(geopos, info[2])) {
		Napi::TypeError::New(env, args[3].second).ThrowAsJavaScriptException();
		return env.Null();
	}
	double ret [10];
	double attr [20];
	char serr [SE_MAX_STNAME];
	int flag = swe_sol_eclipse_when_loc(
		info[0].As<Napi::Number>().DoubleValue(),
		info[1].As<Napi::Number>().Int32Value(),
		geopos,
		ret,
		attr,
		info[3].As<Napi::Boolean>(),
		serr
	);
	Napi::Object data = Napi::Object::New(env);
	data["time"] = sweph_js_array_converter(ret, 7, env);
	data["attributes"] = sweph_js_array_converter(attr, 11, env);
	Napi::Object obj = Napi::Object::New(env);
	obj["flag"] = flag;
	obj["error"] = serr;
	obj["data"] = data;
	return obj;
}

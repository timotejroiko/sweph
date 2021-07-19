#include <sweph.h>

constexpr std::pair<int, const char*> args[] = {
	{ 6, "Expecting 6 arguments: tjd_start, ipl, starname, ifl, geopos, backward" },
	{ NUMBER, "Argument 1 should be a number - julian day in universal time" },
	{ NUMBER, "Argument 2 should be a number - target object ID" },
	{ STRINGNULL, "Argument 3 should be a string or NULL - target star name" },
	{ NUMBER, "Argument 4 should be a number - ephemeris flag" },
	{ ARRAY, "Argument 5 should be an array of 3 numbers - geographic coordinates [longitude, latitude, elevation]" },
	{ TRUEFALSE, "Argument 6 should be a boolean - backwards search" }
};

Napi::Value sweph_lun_occult_when_loc(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(!sweph_type_check(args, info)) {
		return env.Null();
	}
	double geopos [3];
	if(!sweph_double_array_converter(geopos, 3, info[0])) {
		Napi::TypeError::New(env, args[1].second).ThrowAsJavaScriptException();
		return env.Null();
	}
	double ret [10];
	double attr [20];
	char serr [AS_MAXCH];
	int32 flag = swe_lun_occult_when_loc(
		info[0].As<Napi::Number>().DoubleValue(),
		info[1].As<Napi::Number>().Int32Value(),
		info[2].IsString() ? (char*)info[2].As<Napi::String>().Utf8Value().c_str() : NULL,
		info[3].As<Napi::Number>().Int32Value(),
		geopos,
		ret,
		attr,
		info[5].As<Napi::Boolean>(),
		serr
	);
	Napi::Object obj = Napi::Object::New(env);
	obj["flag"] = flag;
	obj["error"] = serr;
	obj["data"] = sweph_js_array_converter(ret, 7, env);
	obj["attributes"] = sweph_js_array_converter(attr, 8, env);
	return obj;
}

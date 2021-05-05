#include <sweph.h>

constexpr std::pair<int, const char*> args[] = {
	{ 4, "Expecting 4 arguments: tjd_ut, ipl, starname, ifl" },
	{ NUMBER, "Argument 1 should be a number - julian day in universal time" },
	{ NUMBER, "Argument 2 should be a number - target object ID" },
	{ STRINGNULL, "Argument 3 should be a string or NULL - target star name" },
	{ NUMBER, "Argument 4 should be a number - ephemeris flag" }
};

Napi::Value sweph_lun_occult_where(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(!sweph_type_check(args, info)) {
		return env.Null();
	}
	double geopos [10];
	double attr [20];
	char serr [AS_MAXCH];
	int32 flag = swe_lun_occult_where(
		info[0].As<Napi::Number>().DoubleValue(),
		info[1].As<Napi::Number>().Int32Value(),
		info[2].IsString() ? (char*)info[2].As<Napi::String>().Utf8Value().c_str() : NULL,
		info[3].As<Napi::Number>().Int32Value(),
		geopos,
		attr,
		serr
	);
	Napi::Object obj = Napi::Object::New(env);
	obj["flag"] = flag;
	obj["error"] = serr;
	obj["data"] = sweph_js_array_converter(geopos, 10, env);
	obj["attributes"] = sweph_js_array_converter(attr, 8, env);
	return obj;
}

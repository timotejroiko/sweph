#include <sweph.h>

constexpr std::pair<int, const char*> args[] = {
	{ 8, "Expecting 8 arguments: tjd_ut, ipl, starname, epheflag, rsmi, geopos, atpress, attemp" },
	{ NUMBER, "Argument 1 should be a number - julian day number" },
	{ NUMBER, "Argument 2 should be a number - target object ID" },
	{ STRINGNULL, "Argument 3 should be a string or NULL - target star name" },
	{ NUMBER, "Argument 4 should be a number - calculation flag" },
	{ NUMBER, "Argument 5 should be a number - transit type" },
	{ ARRAY, "Argument 6 should be an array - geographic coordinates [longitude, latitude, elevation]" },
	{ NUMBER, "Argument 7 should be a number - atmospheric pressure in mbar/hpa" },
	{ NUMBER, "Argument 8 should be a number - atmospheric temperature in celsius" }
};

Napi::Value sweph_rise_trans(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(!sweph_type_check(args, info)) {
		return env.Null();
	}
	double geopos [3];
	if(!sweph_double_array_converter(geopos, info[5])) {
		Napi::TypeError::New(env, args[6].second).ThrowAsJavaScriptException();
		return env.Null();
	}
	double ret;
	char serr [SE_MAX_STNAME];
	int flag = swe_rise_trans(
		info[0].As<Napi::Number>().DoubleValue(),
		info[1].As<Napi::Number>().Int32Value(),
		info[2].IsString() ? (char*)info[2].As<Napi::String>().Utf8Value().c_str() : NULL,
		info[3].As<Napi::Number>().Int32Value(),
		info[4].As<Napi::Number>().Int32Value(),
		geopos,
		info[6].As<Napi::Number>().DoubleValue(),
		info[7].As<Napi::Number>().DoubleValue(),
		&ret,
		serr
	);
	Napi::Object obj = Napi::Object::New(env);
	obj["flag"] = flag;
	obj["error"] = serr;
	obj["time"] = ret;
	return obj;
}

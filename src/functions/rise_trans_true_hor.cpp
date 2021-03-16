#include <sweph.h>

constexpr std::pair<int, const char*> args[] = {
	{ 9, "Expecting 9 arguments: tjd_ut, ipl, starname, epheflag, rsmi, geopos, atpress, attemp, horhgt" },
	{ NUMBER, "Argument 1 should be a number - julian day number" },
	{ NUMBER, "Argument 2 should be a number - target object ID" },
	{ STRINGNULL, "Argument 3 should be a string or NULL - target star name" },
	{ NUMBER, "Argument 4 should be a number - calculation flag" },
	{ NUMBER, "Argument 5 should be a number - transit type" },
	{ ARRAY, "Argument 6 should be an array - geographic coordinates [longitude, latitude, elevation]" },
	{ NUMBER, "Argument 7 should be a number - atmospheric pressure in mbar/hpa" },
	{ NUMBER, "Argument 8 should be a number - atmospheric temperature in celsius" },
	{ NUMBER, "Argument 9 should be a number - height of the local horizon in degrees" }
};

Napi::Value sweph_rise_trans_true_hor(const Napi::CallbackInfo& info) {
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
	char serr [AS_MAXCH];
	int32 flag = swe_rise_trans_true_hor(
		info[0].As<Napi::Number>().DoubleValue(),
		info[1].As<Napi::Number>().Int32Value(),
		info[2].IsString() ? (char*)info[2].As<Napi::String>().Utf8Value().c_str() : NULL,
		info[3].As<Napi::Number>().Int32Value(),
		info[4].As<Napi::Number>().Int32Value(),
		geopos,
		info[6].As<Napi::Number>().DoubleValue(),
		info[7].As<Napi::Number>().DoubleValue(),
		info[8].As<Napi::Number>().DoubleValue(),
		&ret,
		serr
	);
	Napi::Object obj = Napi::Object::New(env);
	obj["flag"] = flag;
	obj["error"] = serr;
	obj["data"] = ret;
	return obj;
}

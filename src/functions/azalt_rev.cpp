#include <sweph.h>

constexpr std::pair<int, const char*> args[] = {
	{ 4, "Expecting 4 arguments: tjd_ut, calc_flag, geopos, xin" },
	{ NUMBER, "Argument 1 should be a number - julian day in universal time" },
	{ NUMBER, "Argument 2 should be a number - calculation flag, 0 for SE_HOR2ECL, 1 for SE_HOR2EQU" },
	{ ARRAY, "Argument 3 should be an array of 3 numbers - geographic coordinates [longitude, latitude, elevation]" },
	{ ARRAY, "Argument 4 should be an array of 2 numbers - horizontal coordinates [azimuth, true altitude]" }
};

Napi::Value sweph_azalt_rev(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(!sweph_type_check(args, info)) {
		return env.Null();
	}
	double geopos [3];
	if(!sweph_double_array_converter(geopos, info[2])) {
		Napi::TypeError::New(env, args[3].second).ThrowAsJavaScriptException();
		return env.Null();
	}
	double xin [2];
	if(!sweph_double_array_converter(xin, info[3])) {
		Napi::TypeError::New(env, args[4].second).ThrowAsJavaScriptException();
		return env.Null();
	}
	double out [2];
	swe_azalt_rev(
		info[0].As<Napi::Number>().DoubleValue(),
		info[1].As<Napi::Number>().Int32Value(),
		geopos,
		xin,
		out
	);
	return sweph_js_array_converter(out, 2, env);
}

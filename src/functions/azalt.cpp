#include <sweph.h>

static std::vector<std::pair<int, std::string>> args = {
	{ 6, "Expecting 6 arguments: tjd_ut, calc_flag, geopos, atpress, attemp, xin" },
	{ NUMBER, "Argument 1 should be a number - julian day in universal time" },
	{ NUMBER, "Argument 2 should be a number - calculation flag, 0 for ECL2HOR, 1 for EQU2HOR" },
	{ ARRAY, "Argument 3 should be an array of 3 numbers - geographic coordinates [longitude, latitude, elevation]" },
	{ NUMBER, "Argument 4 should be a number - atmospheric pressure in mbar/hpa" },
	{ NUMBER, "Argument 5 should be a number - atmospheric temperature in celsius" },
	{ ARRAY, "Argument 6 should be an array of 3 numbers - ecliptic or equatorial coordinates depending on argument 2 [lon/ra, lat/dec, distance]" }
};

Napi::Value sweph_azalt(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(!sweph_type_check(args, info)) {
		return env.Null();
	}
	double geopos [3];
	if(!sweph_double_array_converter(geopos, info[2])) {
		Napi::TypeError::New(env, args[3].second).ThrowAsJavaScriptException();
		return env.Null();
	}
	double xin [3];
	if(!sweph_double_array_converter(xin, info[5])) {
		Napi::TypeError::New(env, args[6].second).ThrowAsJavaScriptException();
		return env.Null();
	}
	double out [3];
	swe_azalt(
		info[0].As<Napi::Number>().DoubleValue(),
		info[1].As<Napi::Number>().Int32Value(),
		geopos,
		info[3].As<Napi::Number>().DoubleValue(),
		info[4].As<Napi::Number>().DoubleValue(),
		xin,
		out
	);
	return sweph_js_array_converter(out, 3, env);
}

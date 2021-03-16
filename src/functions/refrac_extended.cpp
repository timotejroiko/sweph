#include <sweph.h>

constexpr std::pair<int, const char*> args[] = {
	{ 6, "Expecting 6 arguments: inalt, geoalt, atpress, lapse_rate, attemp, calc_flag" },
	{ NUMBER, "Argument 1 should be a number - altitude above horizon in degrees" },
	{ NUMBER, "Argument 2 should be a number - altitude of observer in meters" },
	{ NUMBER, "Argument 3 should be a number - atmospheric pressure in mbar/hpa" },
	{ NUMBER, "Argument 4 should be a number - lapse rate (dattemp/dgeoalt) = [°K/m]" },
	{ NUMBER, "Argument 5 should be a number - atmospheric temperature in celsius" },
	{ NUMBER, "Argument 6 should be a number - calculation flag" }
};

Napi::Value sweph_refrac_extended(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(!sweph_type_check(args, info)) {
		return env.Null();
	}
	double ret [20];
	double out = swe_refrac_extended(
		info[0].As<Napi::Number>().DoubleValue(),
		info[1].As<Napi::Number>().DoubleValue(),
		info[2].As<Napi::Number>().DoubleValue(),
		info[3].As<Napi::Number>().DoubleValue(),
		info[4].As<Napi::Number>().DoubleValue(),
		info[5].As<Napi::Number>().Int32Value(),
		ret
	);
	Napi::Object obj = Napi::Object::New(env);
	obj["data"] = out;
	obj["extended"] = sweph_js_array_converter(ret, 4, env);
	return obj;
}

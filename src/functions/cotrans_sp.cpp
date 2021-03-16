#include <sweph.h>

constexpr std::pair<int, const char*> args[] = {
	{ 2, "Expecting 2 arguments: xpo, eps" },
	{ ARRAY, "Argument 1 should be an array of 6 numbers - source coordinates [lon, lat, dist, lonspd, latspd, distspd]" },
	{ NUMBER, "Argument 2 should be a number - obliquity of the ecliptic in decimal degrees" }
};

Napi::Value sweph_cotrans_sp(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(!sweph_type_check(args, info)) {
		return env.Null();
	}
	double in [6];
	if(!sweph_double_array_converter(in, info[0])) {
		Napi::TypeError::New(env, args[1].second).ThrowAsJavaScriptException();
		return env.Null();
	}
	double out [6];
	swe_cotrans_sp(
		in,
		out,
		info[1].As<Napi::Number>().DoubleValue()
	);
	return sweph_js_array_converter(out, 6, env);
}

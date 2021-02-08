#include <sweph.h>

constexpr std::pair<int, const char*> args[] = {
	{ 4, "Expecting 4 arguments: armc, geolat, eps, hsys" },
	{ NUMBER, "Argument 1 should be a number - ARMC" },
	{ NUMBER, "Argument 2 should be a number - geographic latitude in degrees" },
	{ NUMBER, "Argument 3 should be a number - obliquity of the ecliptic in degrees" },
	{ STRING, "Argument 4 should be a string - house system ID" }
};

Napi::Value sweph_houses_armc_ex2(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(!sweph_type_check(args, info)) {
		return env.Null();
	}
	double cusps [37];
	double points [10];
	double cspeed [37];
	double pspeed [10];
	char serr [AS_MAXCH];
	char sys = info[3].As<Napi::String>().Utf8Value()[0];
	int g = sys == 'G' ? 37 : 13;
	int flag = swe_houses_armc_ex2(
		info[0].As<Napi::Number>().DoubleValue(),
		info[1].As<Napi::Number>().DoubleValue(),
		info[2].As<Napi::Number>().DoubleValue(),
		int(sys),
		cusps,
		points,
		cspeed,
		pspeed,
		serr
	);
	Napi::Object data = Napi::Object::New(env);
	data["houses"] = sweph_js_array_converter(cusps, g, env);
	data["points"] = sweph_js_array_converter(points, 8, env);
	data["housesSpeed"] = sweph_js_array_converter(cspeed, g, env);
	data["pointsSpeed"] = sweph_js_array_converter(pspeed, 8, env);
	Napi::Object obj = Napi::Object::New(env);
	obj["flag"] = flag;
	obj["error"] = serr;
	obj["data"] = data;
	return obj;
}

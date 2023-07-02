#include <sweph.h>

constexpr std::pair<int, const char*> args[] = {
	{ 4, "Expecting 4 arguments: tjd_ut, geolat, geolon, hsys" },
	{ NUMBER, "Argument 1 should be a number - julian day in universal time" },
	{ NUMBER, "Argument 2 should be a number - geographic latitude in degrees" },
	{ NUMBER, "Argument 3 should be a number - geographic longitude in degrees" },
	{ STRING, "Argument 4 should be a string - house system ID" }
};

Napi::Value sweph_houses(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(!sweph_type_check(args, info)) {
		return env.Null();
	}
	double cusps [37];
	double points [10];
	char sys = info[3].As<Napi::String>().Utf8Value()[0];
	int flag = swe_houses(
		info[0].As<Napi::Number>().DoubleValue(),
		info[1].As<Napi::Number>().DoubleValue(),
		info[2].As<Napi::Number>().DoubleValue(),
		int(sys),
		cusps,
		points
	);
	int g = sys == 'G' && flag == OK ? 37 : 13;
	Napi::Object data = Napi::Object::New(env);
	data["houses"] = sweph_js_array_converter(&cusps[1], g-1, env);
	data["points"] = sweph_js_array_converter(points, 8, env);
	Napi::Object obj = Napi::Object::New(env);
	obj["flag"] = flag;
	obj["data"] = data;
	return obj;
}

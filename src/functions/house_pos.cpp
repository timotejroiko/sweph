#include <sweph.h>

static std::vector<std::pair<int, std::string>> args = {
	{ 5, "Expecting 5 arguments: armc, geolat, eps, hsys, xpin" },
	{ NUMBER, "Argument 1 should be a number - ARMC" },
	{ NUMBER, "Argument 2 should be a number - geographic latitude in degrees" },
	{ NUMBER, "Argument 3 should be a number - obliquity of the ecliptic in degrees" },
	{ STRING, "Argument 4 should be a string - house system ID" },
	{ ARRAY, "Argument 5 should be an array of 2 numbers - ecliptic coordinates of the target [longitude, latitude]" }
};

Napi::Value sweph_house_pos(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(!sweph_type_check(args, info)) {
		return env.Null();
	}
	double planet [2];
	if(!sweph_double_array_converter(planet, info[4])) {
		Napi::TypeError::New(env, args[5].second).ThrowAsJavaScriptException();
		return env.Null();
	}
	char serr [SE_MAX_STNAME];
	char sys = info[3].As<Napi::String>().Utf8Value()[0];
	double house = swe_house_pos(
		info[0].As<Napi::Number>().DoubleValue(),
		info[1].As<Napi::Number>().DoubleValue(),
		info[2].As<Napi::Number>().DoubleValue(),
		int(sys),
		planet,
		serr
	);
	Napi::Object obj = Napi::Object::New(env);
	obj["data"] = house;
	obj["error"] = serr;
	return obj;
}

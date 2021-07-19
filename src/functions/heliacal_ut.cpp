#include <sweph.h>

constexpr std::pair<int, const char*> args[] = {
	{ 7, "Expecting 7 arguments: tjd_ut, dgeo, datm, dobs, object_name, event_type, hel_flag" },
	{ NUMBER, "Argument 1 should be a number - julian day in universal time" },
	{ ARRAY, "Argument 2 should be an array of 3 numbers - geographic coordinates [longitude, latitude, elevation]" },
	{ ARRAY, "Argument 3 should be an array of 4 numbers - atmospheric conditions [pressure, temperature, humidity, meteorological range]" },
	{ ARRAY, "Argument 4 should be an array of 6 numbers - observer description [age, sellen ratio, optical type, optical magnification, optical aperture, optical transmission]" },
	{ STRING, "Argument 5 should be a string - name of fixed star or planet" },
	{ NUMBER, "Argument 6 should be a number - event type" },
	{ NUMBER, "Argument 7 should be a number - calculation flag" }
};

Napi::Value sweph_heliacal_ut(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(!sweph_type_check(args, info)) {
		return env.Null();
	}
	double dgeo [3];
	if(!sweph_double_array_converter(dgeo, 3, info[1])) {
		Napi::TypeError::New(env, args[2].second).ThrowAsJavaScriptException();
		return env.Null();
	}
	double datm [4];
	if(!sweph_double_array_converter(datm, 4, info[2])) {
		Napi::TypeError::New(env, args[3].second).ThrowAsJavaScriptException();
		return env.Null();
	}
	double dobs [6];
	if(!sweph_double_array_converter(dobs, 6, info[3])) {
		Napi::TypeError::New(env, args[4].second).ThrowAsJavaScriptException();
		return env.Null();
	}
	char serr [AS_MAXCH];
	double ret [50];
	int32 flag = swe_heliacal_ut(
		info[0].As<Napi::Number>().DoubleValue(),
		dgeo,
		datm,
		dobs,
		(char*)info[4].As<Napi::String>().Utf8Value().c_str(),
		info[5].As<Napi::Number>().Int32Value(),
		info[6].As<Napi::Number>().Int32Value(),
		ret,
		serr
	);
	Napi::Object obj = Napi::Object::New(env);
	obj["flag"] = flag;
	obj["error"] = serr;
	obj["data"] = sweph_js_array_converter(ret, 3, env);
	return obj;
}

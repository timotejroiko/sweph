#include <sweph.h>

constexpr std::pair<int, const char*> args[] = {
	{ 3, "Expecting 3 arguments: star, tjd_ut, iflag" },
	{ STRING, "Argument 1 should be a string - star ID" },
	{ NUMBER, "Argument 2 should be a number - julian day in universal time" },
	{ NUMBER, "Argument 3 should be a number - calculation flag" }
};

Napi::Value sweph_fixstar2_ut(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(!sweph_type_check(args, info)) {
		return env.Null();
	}
	double xx [6];
	char serr [AS_MAXCH];
	int32 flag = swe_fixstar2_ut(
		(char*)info[0].As<Napi::String>().Utf8Value().c_str(),
		info[1].As<Napi::Number>().Int32Value(),
		info[2].As<Napi::Number>().Int32Value(),
		xx,
		serr
	);
	Napi::Object obj = Napi::Object::New(env);
	obj["flag"] = flag;
	obj["error"] = serr;
	obj["data"] = sweph_js_array_converter(xx, 6, env);
	return obj;
}

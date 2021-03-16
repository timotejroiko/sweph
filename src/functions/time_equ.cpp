#include <sweph.h>

constexpr std::pair<int, const char*> args[] = {
	{ 1, "Expecting 1 arguments: tjd_ut" },
	{ NUMBER, "Argument 1 should be a number - julian day in universal time" }
};

Napi::Value sweph_time_equ(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(!sweph_type_check(args, info)) {
		return env.Null();
	}
	double e;
	char serr [AS_MAXCH];
	int32 flag = swe_time_equ(
		info[0].As<Napi::Number>().DoubleValue(),
		&e,
		serr
	);
	Napi::Object obj = Napi::Object::New(env);
	obj["flag"] = flag;
	obj["error"] = serr;
	obj["data"] = e;
	return obj;
}

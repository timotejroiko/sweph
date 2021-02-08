#include <sweph.h>

constexpr std::pair<int, const char*> args[] = {
	{ 2, "Expecting 2 arguments: tjd, ephe" },
	{ NUMBER, "Argument 1 should be a number - julian day in universal time" },
	{ NUMBER, "Argument 2 should be a number - ephemeris flag" }
};

Napi::Value sweph_deltat_ex(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(!sweph_type_check(args, info)) {
		return env.Null();
	}
	char serr [AS_MAXCH];
	double delta = swe_deltat_ex(
		info[0].As<Napi::Number>().DoubleValue(),
		info[1].As<Napi::Number>().Int32Value(),
		serr
	);
	Napi::Object obj = Napi::Object::New(env);
	obj["error"] = serr;
	obj["data"] = delta;
	return obj;
}

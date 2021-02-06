#include <sweph.h>

constexpr std::pair<int, const char*> args[] = {
	{ 1, "Expecting 1 argument: star" },
	{ STRING, "Argument 1 should be a string - star ID" }
};

Napi::Value sweph_fixstar2_mag(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(!sweph_type_check(args, info)) {
		return env.Null();
	}
	double mag;
	char serr [SE_MAX_STNAME];
	long flag = swe_fixstar2_mag(
		(char*)info[0].As<Napi::String>().Utf8Value().c_str(),
		&mag,
		serr
	);
	Napi::Object obj = Napi::Object::New(env);
	obj["flag"] = flag;
	obj["error"] = serr;
	obj["data"] = mag;
	return obj;
}
#include <sweph.h>

constexpr std::pair<int, const char*> args[] = {
	{ 1, "Expecting 1 argument: star" },
	{ STRING, "Argument 1 should be a string - star ID" }
};

Napi::Value sweph_fixstar_mag(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(!sweph_type_check(args, info)) {
		return env.Null();
	}
	double mag;
	char serr [AS_MAXCH] = "";
	char star [AS_MAXCH];
	strcpy(star, info[0].As<Napi::String>().Utf8Value().c_str());
	int32 flag = swe_fixstar_mag(
		star,
		&mag,
		serr
	);
	Napi::Object obj = Napi::Object::New(env);
	obj["flag"] = flag;
	obj["error"] = serr;
	obj["name"] = star;
	obj["data"] = mag;
	return obj;
}

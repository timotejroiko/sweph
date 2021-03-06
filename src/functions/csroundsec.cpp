#include <sweph.h>

constexpr std::pair<int, const char*> args[] = {
	{ 1, "Expecting 1 argument: csec" },
	{ NUMBER, "Argument 1 should be a number - degrees in centiseconds" }
};

Napi::Value sweph_csroundsec(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(!sweph_type_check(args, info)) {
		return env.Null();
	}
	int32 val = swe_csroundsec(info[0].As<Napi::Number>().Int32Value());
	return Napi::Number::New(env, val);
}

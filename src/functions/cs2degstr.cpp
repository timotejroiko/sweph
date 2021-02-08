#include <sweph.h>

constexpr std::pair<int, const char*> args[] = {
	{ 1, "Expecting 1 argument: csec" },
	{ NUMBER, "Argument 1 should be a number - degrees in centiseconds" }
};

Napi::Value sweph_cs2degstr(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(!sweph_type_check(args, info)) {
		return env.Null();
	}
	char out [AS_MAXCH];
	swe_cs2degstr(
		info[0].As<Napi::Number>().Int32Value(),
		out
	);
	return Napi::String::New(env, out);
}

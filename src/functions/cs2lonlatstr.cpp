#include <sweph.h>

constexpr std::pair<int, const char*> args[] = {
	{ 3, "Expecting 3 arguments: csec, pchar, mchar" },
	{ NUMBER, "Argument 1 should be a number - degrees in centiseconds" },
	{ STRING, "Argument 2 should be a string - sign character for positive values" },
	{ STRING, "Argument 3 should be a string - sign character for negative values" }
};

Napi::Value sweph_cs2lonlatstr(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(!sweph_type_check(args, info)) {
		return env.Null();
	}
	char out [AS_MAXCH];
	swe_cs2lonlatstr(
		info[0].As<Napi::Number>().Int32Value(),
		info[1].As<Napi::String>().Utf8Value()[0],
		info[2].As<Napi::String>().Utf8Value()[0],
		out
	);
	return Napi::String::New(env, out);
}

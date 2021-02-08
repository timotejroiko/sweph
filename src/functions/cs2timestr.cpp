#include <sweph.h>

constexpr std::pair<int, const char*> args[] = {
	{ 3, "Expecting 3 arguments: csec, sep, supzero" },
	{ NUMBER, "Argument 1 should be a number - degrees in centiseconds" },
	{ STRING, "Argument 2 should be a string - separator" },
	{ TRUEFALSE, "Argument 3 should be a boolean - suppress zero" }
};

Napi::Value sweph_cs2timestr(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(!sweph_type_check(args, info)) {
		return env.Null();
	}
	char out [AS_MAXCH];
	swe_cs2timestr(
		info[0].As<Napi::Number>().Int32Value(),
		int(info[1].As<Napi::String>().Utf8Value()[0]),
		info[2].As<Napi::Boolean>(),
		out
	);
	return Napi::String::New(env, out);
}

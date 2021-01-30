#include <sweph.h>

static std::vector<std::pair<int, std::string>> args = {
	{ 3, "Expecting 3 arguments: csec, pchar, mchar" },
	{ NUMBER, "Argument 1 should be a number - degrees in centiseconds" },
	{ STRING, "Argument 2 should be a string - 1st delimiter character" },
	{ STRING, "Argument 3 should be a string - 2nd delimiter character" }
};

Napi::Value sweph_cs2lonlatstr(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(!sweph_type_check(args, info)) {
		return env.Null();
	}
	char out [SE_MAX_STNAME];
	swe_cs2lonlatstr(
		info[0].As<Napi::Number>().Int32Value(),
		info[1].As<Napi::String>().Utf8Value()[0],
		info[2].As<Napi::String>().Utf8Value()[0],
		out
	);
	return Napi::String::New(env, out);
}

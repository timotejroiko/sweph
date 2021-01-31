#include <sweph.h>

constexpr std::pair<int, const char*> args[] = {
	{ 1, "Expecting 1 argument: aya" },
	{ NUMBER, "Argument 1 should be a number - ayanamsa ID" }
};

Napi::Value sweph_get_ayanamsa_name(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(!sweph_type_check(args, info)) {
		return env.Null();
	}
	const char* name = swe_get_ayanamsa_name(info[0].As<Napi::Number>().Int32Value());
	if(name == NULL) {
		Napi::TypeError::New(env, "Invalid ayanamsa").ThrowAsJavaScriptException();
		return env.Null();
	}
	return Napi::String::New(env, name);
}

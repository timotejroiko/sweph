#include <sweph.h>

constexpr std::pair<int, const char*> args[] = {
	{ 1, "Expecting 1 argument: hsys" },
	{ STRING, "Argument 1 should be a string - house system ID" }
};

Napi::Value sweph_house_name(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(!sweph_type_check(args, info)) {
		return env.Null();
	}
	char sys = info[0].As<Napi::String>().Utf8Value()[0];
	const char* name = swe_house_name(int(sys));
	if(name == NULL) {
		Napi::TypeError::New(env, "Invalid house system").ThrowAsJavaScriptException();
		return env.Null();
	}
	return Napi::String::New(env, name);
}

#include <sweph.h>

static std::vector<std::pair<int, std::string>> args = {
	{ 1, "Expecting 1 argument: hsys" },
	{ NUMBER, "Argument 1 should be a number - house system ID" }
};

Napi::Value sweph_house_name(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(!sweph_type_check(args, info)) {
		return env.Null();
	}
	const char* name = swe_house_name(info[0].As<Napi::Number>().Int32Value());
	if(name == NULL) {
		Napi::TypeError::New(env, "Invalid house system").ThrowAsJavaScriptException();
		return env.Null();
	}
	return Napi::String::New(env, name);
}

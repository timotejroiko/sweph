#include <sweph.h>

static std::vector<std::pair<int, std::string>> args = {
	{ 1, "Expecting 1 argument: ifno" },
	{ NUMBER, "Argument 1 should be a number - file type" }
};

Napi::Value sweph_get_current_file_data(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(!sweph_type_check(args, info)) {
		return env.Null();
	}
	double tfstart;
	double tfend;
	int denum;
	const char *path = swe_get_current_file_data(
		info[0].As<Napi::Number>().Int32Value(),
		&tfstart,
		&tfend,
		&denum
	);
	Napi::Object obj = Napi::Object::New(env);
	obj["path"] = path;
	obj["start"] = tfstart;
	obj["end"] = tfend;
	obj["denum"] = denum;
	return obj;
}

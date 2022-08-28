#include <sweph.h>

constexpr std::pair<int, const char*> args[] = {
	{ 1, "Expecting 1 arguments: path" },
	{ STRINGNULL, "Argument 1 should be a string or NULL - path to ephemeris files" }
};

void sweph_set_ephe_path(const Napi::CallbackInfo& info) {
	if(!sweph_type_check(args, info)) {
		return;
	}
	swe_set_ephe_path(info[0].IsString() ? info[0].As<Napi::String>().Utf8Value().c_str() : NULL);
	return;
}

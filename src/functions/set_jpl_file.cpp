#include <sweph.h>

constexpr std::pair<int, const char*> args[] = {
	{ 1, "Expecting 1 arguments: fname" },
	{ STRING, "Argument 1 should be a string - JPL file name" }
};

void sweph_set_jpl_file(const Napi::CallbackInfo& info) {
	if(!sweph_type_check(args, info)) {
		return;
	}
	swe_set_jpl_file((char*)info[0].As<Napi::String>().Utf8Value().c_str());
	return;
}

#include <sweph.h>

static std::vector<std::pair<int, std::string>> args = {
	{ 3, "Expecting 3 arguments: geolon, geolat, elevation" },
	{ NUMBER, "Argument 1 should be a number - geographical longitude" },
	{ NUMBER, "Argument 2 should be a number - geographical latitude" },
	{ NUMBER, "Argument 3 should be a number - elevation" }
};

void sweph_set_topo(const Napi::CallbackInfo& info) {
	if(!sweph_type_check(args, info)) {
		return;
	}
	swe_set_topo(
		info[0].As<Napi::Number>().DoubleValue(),
		info[1].As<Napi::Number>().DoubleValue(),
		info[2].As<Napi::Number>().DoubleValue()
	);
	return;
}

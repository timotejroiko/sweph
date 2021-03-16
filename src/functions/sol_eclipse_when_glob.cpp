#include <sweph.h>

constexpr std::pair<int, const char*> args[] = {
	{ 4, "Expecting 4 arguments: tjd_start, ifl, ifltype, backward" },
	{ NUMBER, "Argument 1 should be a number - julian day in universal time" },
	{ NUMBER, "Argument 2 should be a number - target object ID" },
	{ NUMBER, "Argument 3 should be a number - eclipse type" },
	{ TRUEFALSE, "Argument 4 should be a boolean - backwards search" }
};

Napi::Value sweph_sol_eclipse_when_glob(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(!sweph_type_check(args, info)) {
		return env.Null();
	}
	double ret [10];
	char serr [AS_MAXCH];
	int32 flag = swe_sol_eclipse_when_glob(
		info[0].As<Napi::Number>().DoubleValue(),
		info[1].As<Napi::Number>().Int32Value(),
		info[2].As<Napi::Number>().Int32Value(),
		ret,
		info[3].As<Napi::Boolean>(),
		serr
	);
	Napi::Object obj = Napi::Object::New(env);
	obj["flag"] = flag;
	obj["error"] = serr;
	obj["data"] = sweph_js_array_converter(ret, 10, env);
	return obj;
}

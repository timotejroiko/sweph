#include <sweph.h>

static std::vector<std::pair<int, std::string>> args = {
	{ 6, "Expecting 6 arguments: tjd_start, ipl, starname, ifl, ifltype, backward" },
	{ NUMBER, "Argument 1 should be a number - julian day in universal time" },
	{ NUMBER, "Argument 2 should be a number - target object ID" },
	{ STRINGNULL, "Argument 3 should be a string or NULL - target star name" },
	{ NUMBER, "Argument 4 should be a number - ephemeris flag" },
	{ NUMBER, "Argument 5 should be a number - eclipse type" },
	{ TRUEFALSE, "Argument 6 should be a boolean - backwards search" }
};

Napi::Value sweph_lun_occult_when_glob(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(!sweph_type_check(args, info)) {
		return env.Null();
	}
	double ret [10];
	char serr [SE_MAX_STNAME];
	int flag = swe_lun_occult_when_glob(
		info[0].As<Napi::Number>().DoubleValue(),
		info[1].As<Napi::Number>().Int32Value(),
		info[2].IsString() ? (char*)info[2].As<Napi::String>().Utf8Value().c_str() : NULL,
		info[3].As<Napi::Number>().Int32Value(),
		info[4].As<Napi::Number>().Int32Value(),
		ret,
		info[5].As<Napi::Boolean>(),
		serr
	);
	Napi::Object obj = Napi::Object::New(env);
	obj["flag"] = flag;
	obj["error"] = serr;
	obj["data"] = sweph_js_array_converter(ret, 10, env);
	return obj;
}

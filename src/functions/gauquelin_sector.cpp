#include <sweph.h>

std::vector<std::pair<int, std::string>> args[] = {
	{ 8, "Expecting 8 arguments: tjd_ut, ipl, starname, iflag, imeth, geopos, atpress, attemp" },
	{ NUMBER, "Argument 1 should be a number - julian day in universal time" },
	{ NUMBER, "Argument 2 should be a number - planet ID" },
	{ STRINGNULL, "Argument 3 should be a string or null - star ID if any" },
	{ NUMBER, "Argument 4 should be a number - calculation flag" },
	{ NUMBER, "Argument 5 should be a number - calculation method" },
	{ ARRAY, "Argument 6 should be an array of 3 numbers - geographic coordinates [longitude, latitude, elevation]" },
	{ NUMBER, "Argument 7 should be a number - atmospheric pressure in mbar/hpa" },
	{ NUMBER, "Argument 8 should be a number - atmospheric temperature in celsius" }
};

Napi::Value sweph_gauquelin_sector(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(!sweph_type_check(args, info)) {
		return env.Null();
	}
	double geopos [3];
	if(!sweph_double_array_converter(geopos, info[5])) {
		Napi::TypeError::New(env, args[6].second).ThrowAsJavaScriptException();
		return env.Null();
	}
	double sect;
	char serr [SE_MAX_STNAME];
	int flag = swe_gauquelin_sector(
		info[0].As<Napi::Number>().DoubleValue(),
		info[1].As<Napi::Number>().Int32Value(),
		info[2].IsString() ? (char*)info[2].As<Napi::String>().Utf8Value().c_str() : NULL,
		info[3].As<Napi::Number>().Int32Value(),
		info[4].As<Napi::Number>().Int32Value(),
		geopos,
		info[6].As<Napi::Number>().DoubleValue(),
		info[7].As<Napi::Number>().DoubleValue(),
		&sect,
		serr
	);
	Napi::Object obj = Napi::Object::New(env);
	obj["flag"] = flag;
	obj["error"] = serr;
	obj["data"] = sect;
	return obj;
}

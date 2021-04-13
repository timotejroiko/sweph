#include <sweph.h>

constexpr std::pair<int, const char*> args[] = {
	{ 5, "Expecting 5 arguments: year, month, day, hour, calendar" },
	{ NUMBER, "Argument 1 should be a number - full year" },
	{ NUMBER, "Argument 2 should be a number - month 1-12" },
	{ NUMBER, "Argument 3 should be a number - day 1-31" },
	{ NUMBER, "Argument 4 should be a number - hour with decimal fraction 0-23.999" },
	{ STRING, "Argument 5 should be a string - calendar system, 'g' for gregorian calendar, 'j' for julian calendar" }
};

Napi::Value sweph_date_conversion(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(!sweph_type_check(args, info)) {
		return env.Null();
	}
	double ret;
	int flag = swe_date_conversion(
		info[0].As<Napi::Number>().Int32Value(),
		info[1].As<Napi::Number>().Int32Value(),
		info[2].As<Napi::Number>().Int32Value(),
		info[3].As<Napi::Number>().DoubleValue(),
		info[4].As<Napi::String>().Utf8Value()[0],
		&ret
	);
	Napi::Object obj = Napi::Object::New(env);
	obj["flag"] = flag;
	obj["data"] = ret;
	return obj;
}

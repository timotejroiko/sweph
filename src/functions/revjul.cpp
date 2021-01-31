#include <sweph.h>


constexpr std::pair<int, const char*> args[] = {
	{ 2, "Expecting 2 arguments: tjd, gregflag" },
	{ NUMBER, "Argument 1 should be a number - julian day number" },
	{ NUMBER, "Argument 2 should be a number - calendar system, 1 for GREG_CAL, 0 for JUL_CAL" }
};

Napi::Value sweph_revjul(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(!sweph_type_check(args, info)) {
		return env.Null();
	}
	int year;
	int month;
	int day;
	double time;
	swe_revjul(
		info[0].As<Napi::Number>().DoubleValue(),
		info[1].As<Napi::Number>().Int32Value(),
		&year,
		&month,
		&day,
		&time
	);
	Napi::Object obj = Napi::Object::New(env);
	obj["year"] = year;
	obj["month"] = month;
	obj["day"] = day;
	obj["hour"] = time;
	return obj;
}

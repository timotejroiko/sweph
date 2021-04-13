#include <sweph.h>

constexpr std::pair<int, const char*> args[] = {
	{ 2, "Expecting 2 arguments: tjd_et, gregflag" },
	{ NUMBER, "Argument 1 should be a number - julian day in ephemeris/terrestrial time" },
	{ NUMBER, "Argument 2 should be a number - calendar system, 1 for SE_GREG_CAL, 0 for SE_JUL_CAL" }
};

Napi::Value sweph_jdet_to_utc(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(!sweph_type_check(args, info)) {
		return env.Null();
	}
	int year;
	int month;
	int day;
	int hour;
	int minute;
	double second;
	swe_jdet_to_utc(
		info[0].As<Napi::Number>().DoubleValue(),
		info[1].As<Napi::Number>().Int32Value(),
		&year,
		&month,
		&day,
		&hour,
		&minute,
		&second
	);
	Napi::Object obj = Napi::Object::New(env);
	obj["year"] = year;
	obj["month"] = month;
	obj["day"] = day;
	obj["hour"] = hour;
	obj["minute"] = minute;
	obj["second"] = second;
	return obj;
}

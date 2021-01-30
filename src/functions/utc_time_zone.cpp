#include <sweph.h>

static std::vector<std::pair<int, std::string>> args = {
	{ 7, "Expecting 7 arguments: iyear, imonth, iday, ihour, imin, dsec, d_timezone" },
	{ NUMBER, "Argument 1 should be a number - full year" },
	{ NUMBER, "Argument 2 should be a number - month 1-12" },
	{ NUMBER, "Argument 3 should be a number - day 1-31" },
	{ NUMBER, "Argument 4 should be a number - hour 0-23" },
	{ NUMBER, "Argument 5 should be a number - minutes 0-59" },
	{ NUMBER, "Argument 6 should be a number - seconds 0-59.999" },
	{ NUMBER, "Argument 7 should be a number - timezone offset" }
};

Napi::Value sweph_utc_time_zone(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(!sweph_type_check(args, info)) {
		return env.Null();
	}
	int year;
	int month;
	int day;
	int hour;
	int minute;
	double seconds;
	swe_utc_time_zone(
		info[0].As<Napi::Number>().Int32Value(),
		info[1].As<Napi::Number>().Int32Value(),
		info[2].As<Napi::Number>().Int32Value(),
		info[3].As<Napi::Number>().Int32Value(),
		info[4].As<Napi::Number>().Int32Value(),
		info[5].As<Napi::Number>().DoubleValue(),
		info[6].As<Napi::Number>().DoubleValue(),
		&year,
		&month,
		&day,
		&hour,
		&minute,
		&seconds
	);
	Napi::Object obj = Napi::Object::New(env);
	obj["year"] = year;
	obj["month"] = month;
	obj["day"] = day;
	obj["hour"] = hour;
	obj["minute"] = minute;
	obj["second"] = seconds;
	return obj;
}

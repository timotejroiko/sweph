#include <sweph.h>

constexpr std::pair<int, const char*> args[] = {
	{ 2, "Expecting 2 arguments: ddeg, roundflag" },
	{ NUMBER, "Argument 1 should be a number - decimal degrees" },
	{ NUMBER, "Argument 2 should be a number - rounding flag" }
};

Napi::Value sweph_split_deg(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if(!sweph_type_check(args, info)) {
		return env.Null();
	}
	int deg;
	int min;
	int sec;
	double fraction;
	int sign;
	swe_split_deg(
		info[0].As<Napi::Number>().DoubleValue(),
		info[1].As<Napi::Number>().Int32Value(),
		&deg,
		&min,
		&sec,
		&fraction,
		&sign
	);
	Napi::Object obj = Napi::Object::New(env);
	obj["degree"] = deg;
	obj["minute"] = min;
	obj["second"] = sec;
	obj["fraction"] = fraction;
	obj["sign"] = sign;
	return obj;
}

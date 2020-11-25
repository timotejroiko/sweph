#include <napi.h>
#include "swephexp.h"

Napi::Object Init(Napi::Env env, Napi::Object exports) {

	exports.Set(Napi::String::New(env, "calc_elem"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 3) {
			Napi::TypeError::New(env, "Expecting 3 arguments").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[1].IsString()) {
			Napi::TypeError::New(env, "Argument 2 should be a string").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[2].IsNumber()) {
			Napi::TypeError::New(env, "Argument 3 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		double xx [6];
		char serr [SE_MAX_STNAME];
		int flag = swe_calc_elem(
			info[0].As<Napi::Number>().DoubleValue(),
			const_cast<char*>(info[1].As<Napi::String>().Utf8Value().c_str()),
			info[2].As<Napi::Number>().Int32Value(),
			xx,
			serr
		);
		Napi::Array array = Napi::Array::New(env);
		for(int i = 0; i < 6; i++) {
			array[i] = Napi::Number::New(env, xx[i]);
		}
		array.Set(Napi::String::New(env, "flag"), Napi::Number::New(env, flag));
		array.Set(Napi::String::New(env, "error"), Napi::String::New(env, serr));
		return array;
	}));

	exports.Set(Napi::String::New(env, "fixstar3"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 4) {
			Napi::TypeError::New(env, "Expecting 4 arguments").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsString()) {
			Napi::TypeError::New(env, "Argument 1 should be a string").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[1].IsString()) {
			Napi::TypeError::New(env, "Argument 2 should be a string").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[2].IsNumber()) {
			Napi::TypeError::New(env, "Argument 3 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[3].IsNumber()) {
			Napi::TypeError::New(env, "Argument 4 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		double xx [6];
		char serr [SE_MAX_STNAME];
		long flag = swe_fixstar3(
			const_cast<char*>(info[0].As<Napi::String>().Utf8Value().c_str()),
			const_cast<char*>(info[1].As<Napi::String>().Utf8Value().c_str()),
			info[2].As<Napi::Number>().Int32Value(),
			info[3].As<Napi::Number>().Int32Value(),
			xx,
			serr
		);
		Napi::Array array = Napi::Array::New(env);
		for(int i = 0; i < 6; i++) {
			array[i] = Napi::Number::New(env, xx[i]);
		}
		array.Set(Napi::String::New(env, "flag"), Napi::Number::New(env, flag));
		array.Set(Napi::String::New(env, "error"), Napi::String::New(env, serr));
		return array;
	}));

	exports.Set(Napi::String::New(env, "version"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::String {
		Napi::Env env = info.Env();
		char version [SE_MAX_STNAME];
		swe_version(version);
		return Napi::String::New(env, version);
	}));

	exports.Set(Napi::String::New(env, "get_library_path"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::String {
		Napi::Env env = info.Env();
		char path [SE_MAX_STNAME];
		swe_get_library_path(path);
		return Napi::String::New(env, path);
	}));

	exports.Set(Napi::String::New(env, "set_ephe_path"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> void {
		Napi::Env env = info.Env();
		if(info.Length() != 1) {
			Napi::TypeError::New(env, "Expecting 1 argument").ThrowAsJavaScriptException();
			return;
		}
		if(info[0].IsString()) {
			swe_set_ephe_path(const_cast<char*>(info[0].As<Napi::String>().Utf8Value().c_str()));
		} else if(info[0].IsNull()) {
			swe_set_ephe_path(NULL);
		} else {
			Napi::TypeError::New(env, "Argument 1 should be a string or null").ThrowAsJavaScriptException();
		}
		return;
	}));

	exports.Set(Napi::String::New(env, "set_jpl_file"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> void {
		Napi::Env env = info.Env();
		if(info.Length() != 1) {
			Napi::TypeError::New(env, "Expecting 1 argument").ThrowAsJavaScriptException();
			return;
		}
		if(!info[0].IsString()) {
			Napi::TypeError::New(env, "Argument 1 should be a string").ThrowAsJavaScriptException();
			return;
		}
		swe_set_jpl_file(const_cast<char*>(info[0].As<Napi::String>().Utf8Value().c_str()));
		return;
	}));

	exports.Set(Napi::String::New(env, "close"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> void {
		swe_close();
		return;
	}));

	exports.Set(Napi::String::New(env, "calc"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 3) {
			Napi::TypeError::New(env, "Expecting 3 arguments").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[1].IsNumber()) {
			Napi::TypeError::New(env, "Argument 2 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[2].IsNumber()) {
			Napi::TypeError::New(env, "Argument 3 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		double xx [6];
		char serr [SE_MAX_STNAME];
		int flag = swe_calc(
			info[0].As<Napi::Number>().DoubleValue(),
			info[1].As<Napi::Number>().Int32Value(),
			info[2].As<Napi::Number>().Int32Value(),
			xx,
			serr
		);
		Napi::Array array = Napi::Array::New(env);
		for(int i = 0; i < 6; i++) {
			array[i] = Napi::Number::New(env, xx[i]);
		}
		array.Set(Napi::String::New(env, "flag"), Napi::Number::New(env, flag));
		array.Set(Napi::String::New(env, "error"), Napi::String::New(env, serr));
		return array;
	}));

	exports.Set(Napi::String::New(env, "calc_ut"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 3) {
			Napi::TypeError::New(env, "Expecting 3 arguments").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[1].IsNumber()) {
			Napi::TypeError::New(env, "Argument 2 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[2].IsNumber()) {
			Napi::TypeError::New(env, "Argument 3 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		double xx [6];
		char serr [SE_MAX_STNAME];
		int flag = swe_calc_ut(
			info[0].As<Napi::Number>().DoubleValue(),
			info[1].As<Napi::Number>().Int32Value(),
			info[2].As<Napi::Number>().Int32Value(),
			xx,
			serr
		);
		Napi::Array array = Napi::Array::New(env);
		for(int i = 0; i < 6; i++) {
			array[i] = Napi::Number::New(env, xx[i]);
		}
		array.Set(Napi::String::New(env, "flag"), Napi::Number::New(env, flag));
		array.Set(Napi::String::New(env, "error"), Napi::String::New(env, serr));
		return array;
	}));

	exports.Set(Napi::String::New(env, "get_planet_name"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() != 1) {
			Napi::TypeError::New(env, "Expecting 1 argument").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		char planet [SE_MAX_STNAME];
		swe_get_planet_name(
			info[0].As<Napi::Number>().Int32Value(),
			planet
		);
		return Napi::String::New(env, planet);
	}));

	exports.Set(Napi::String::New(env, "fixstar"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 3) {
			Napi::TypeError::New(env, "Expecting 3 arguments").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsString()) {
			Napi::TypeError::New(env, "Argument 1 should be a string").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[1].IsNumber()) {
			Napi::TypeError::New(env, "Argument 2 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[2].IsNumber()) {
			Napi::TypeError::New(env, "Argument 3 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		double xx [6];
		char serr [SE_MAX_STNAME];
		long flag = swe_fixstar(
			const_cast<char*>(info[0].As<Napi::String>().Utf8Value().c_str()),
			info[1].As<Napi::Number>().Int32Value(),
			info[2].As<Napi::Number>().Int32Value(),
			xx,
			serr
		);
		Napi::Array array = Napi::Array::New(env);
		for(int i = 0; i < 6; i++) {
			array[i] = Napi::Number::New(env, xx[i]);
		}
		array.Set(Napi::String::New(env, "flag"), Napi::Number::New(env, flag));
		array.Set(Napi::String::New(env, "error"), Napi::String::New(env, serr));
		return array;
	}));

	exports.Set(Napi::String::New(env, "fixstar_ut"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 3) {
			Napi::TypeError::New(env, "Expecting 3 arguments").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsString()) {
			Napi::TypeError::New(env, "Argument 1 should be a string").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[1].IsNumber()) {
			Napi::TypeError::New(env, "Argument 2 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[2].IsNumber()) {
			Napi::TypeError::New(env, "Argument 3 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		double xx [6];
		char serr [SE_MAX_STNAME];
		long flag = swe_fixstar_ut(
			const_cast<char*>(info[0].As<Napi::String>().Utf8Value().c_str()),
			info[1].As<Napi::Number>().Int32Value(),
			info[2].As<Napi::Number>().Int32Value(),
			xx,
			serr
		);
		Napi::Array array = Napi::Array::New(env);
		for(int i = 0; i < 6; i++) {
			array[i] = Napi::Number::New(env, xx[i]);
		}
		array.Set(Napi::String::New(env, "flag"), Napi::Number::New(env, flag));
		array.Set(Napi::String::New(env, "error"), Napi::String::New(env, serr));
		return array;
	}));

	exports.Set(Napi::String::New(env, "fixstar2"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 3) {
			Napi::TypeError::New(env, "Expecting 3 arguments").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsString()) {
			Napi::TypeError::New(env, "Argument 1 should be a string").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[1].IsNumber()) {
			Napi::TypeError::New(env, "Argument 2 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[2].IsNumber()) {
			Napi::TypeError::New(env, "Argument 3 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		double xx [6];
		char serr [SE_MAX_STNAME];
		long flag = swe_fixstar2(
			const_cast<char*>(info[0].As<Napi::String>().Utf8Value().c_str()),
			info[1].As<Napi::Number>().Int32Value(),
			info[2].As<Napi::Number>().Int32Value(),
			xx,
			serr
		);
		Napi::Array array = Napi::Array::New(env);
		for(int i = 0; i < 6; i++) {
			array[i] = Napi::Number::New(env, xx[i]);
		}
		array.Set(Napi::String::New(env, "flag"), Napi::Number::New(env, flag));
		array.Set(Napi::String::New(env, "error"), Napi::String::New(env, serr));
		return array;
	}));

	exports.Set(Napi::String::New(env, "fixstar2_ut"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 3) {
			Napi::TypeError::New(env, "Expecting 3 arguments").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsString()) {
			Napi::TypeError::New(env, "Argument 1 should be a string").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[1].IsNumber()) {
			Napi::TypeError::New(env, "Argument 2 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[2].IsNumber()) {
			Napi::TypeError::New(env, "Argument 3 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		double xx [6];
		char serr [SE_MAX_STNAME];
		long flag = swe_fixstar2_ut(
			const_cast<char*>(info[0].As<Napi::String>().Utf8Value().c_str()),
			info[1].As<Napi::Number>().Int32Value(),
			info[2].As<Napi::Number>().Int32Value(),
			xx,
			serr
		);
		Napi::Array array = Napi::Array::New(env);
		for(int i = 0; i < 6; i++) {
			array[i] = Napi::Number::New(env, xx[i]);
		}
		array.Set(Napi::String::New(env, "flag"), Napi::Number::New(env, flag));
		array.Set(Napi::String::New(env, "error"), Napi::String::New(env, serr));
		return array;
	}));

	exports.Set(Napi::String::New(env, "fixstar_mag"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 1) {
			Napi::TypeError::New(env, "Expecting 1 argument").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsString()) {
			Napi::TypeError::New(env, "Argument 1 should be a string").ThrowAsJavaScriptException();
			return env.Null();
		}
		double mag;
		char serr [SE_MAX_STNAME];
		long flag = swe_fixstar_mag(
			const_cast<char*>(info[0].As<Napi::String>().Utf8Value().c_str()),
			&mag,
			serr
		);
		Napi::Object obj = Napi::Object::New(env);
		obj.Set(Napi::String::New(env, "flag"), Napi::Number::New(env, flag));
		obj.Set(Napi::String::New(env, "error"), Napi::String::New(env, serr));
		obj.Set(Napi::String::New(env, "magnitude"), Napi::Number::New(env, mag));
		return obj;
	}));

	exports.Set(Napi::String::New(env, "fixstar2_mag"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 1) {
			Napi::TypeError::New(env, "Expecting 1 argument").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsString()) {
			Napi::TypeError::New(env, "Argument 1 should be a string").ThrowAsJavaScriptException();
			return env.Null();
		}
		double mag;
		char serr [SE_MAX_STNAME];
		long flag = swe_fixstar2_mag(
			const_cast<char*>(info[0].As<Napi::String>().Utf8Value().c_str()),
			&mag,
			serr
		);
		Napi::Object obj = Napi::Object::New(env);
		obj.Set(Napi::String::New(env, "flag"), Napi::Number::New(env, flag));
		obj.Set(Napi::String::New(env, "error"), Napi::String::New(env, serr));
		obj.Set(Napi::String::New(env, "magnitude"), Napi::Number::New(env, mag));
		return obj;
	}));

	exports.Set(Napi::String::New(env, "nod_aps_ut"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 4) {
			Napi::TypeError::New(env, "Expecting 4 arguments").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[1].IsNumber()) {
			Napi::TypeError::New(env, "Argument 2 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[2].IsNumber()) {
			Napi::TypeError::New(env, "Argument 3 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[3].IsNumber()) {
			Napi::TypeError::New(env, "Argument 4 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		double asc [6];
		double dsc [6];
		double per [6];
		double aph [6];
		char serr [SE_MAX_STNAME];
		int flag = swe_nod_aps_ut(
			info[0].As<Napi::Number>().DoubleValue(),
			info[1].As<Napi::Number>().Int32Value(),
			info[2].As<Napi::Number>().Int32Value(),
			info[3].As<Napi::Number>().Int32Value(),
			asc,
			dsc,
			per,
			aph,
			serr
		);
		Napi::Object obj = Napi::Object::New(env);
		Napi::Array asc1 = Napi::Array::New(env);
		Napi::Array dsc1 = Napi::Array::New(env);
		Napi::Array per1 = Napi::Array::New(env);
		Napi::Array aph1 = Napi::Array::New(env);
		for(int i = 0; i < 6; i++) {
			asc1[i] = Napi::Number::New(env, asc[i]);
		}
		for(int i = 0; i < 6; i++) {
			dsc1[i] = Napi::Number::New(env, dsc[i]);
		}
		for(int i = 0; i < 6; i++) {
			per1[i] = Napi::Number::New(env, per[i]);
		}
		for(int i = 0; i < 6; i++) {
			aph1[i] = Napi::Number::New(env, aph[i]);
		}
		obj.Set(Napi::String::New(env, "flag"), Napi::Number::New(env, flag));
		obj.Set(Napi::String::New(env, "error"), Napi::String::New(env, serr));
		obj.Set(Napi::String::New(env, "ascendingNode"), asc1);
		obj.Set(Napi::String::New(env, "descendingNode"), dsc1);
		obj.Set(Napi::String::New(env, "perihelion"), per1);
		obj.Set(Napi::String::New(env, "aphelion"), aph1);
		return obj;
	}));

	exports.Set(Napi::String::New(env, "nod_aps"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 4) {
			Napi::TypeError::New(env, "Expecting 4 arguments").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[1].IsNumber()) {
			Napi::TypeError::New(env, "Argument 2 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[2].IsNumber()) {
			Napi::TypeError::New(env, "Argument 3 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[3].IsNumber()) {
			Napi::TypeError::New(env, "Argument 4 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		double asc [6];
		double dsc [6];
		double per [6];
		double aph [6];
		char serr [SE_MAX_STNAME];
		int flag = swe_nod_aps(
			info[0].As<Napi::Number>().DoubleValue(),
			info[1].As<Napi::Number>().Int32Value(),
			info[2].As<Napi::Number>().Int32Value(),
			info[3].As<Napi::Number>().Int32Value(),
			asc,
			dsc,
			per,
			aph,
			serr
		);
		Napi::Object obj = Napi::Object::New(env);
		Napi::Array asc1 = Napi::Array::New(env);
		Napi::Array dsc1 = Napi::Array::New(env);
		Napi::Array per1 = Napi::Array::New(env);
		Napi::Array aph1 = Napi::Array::New(env);
		for(int i = 0; i < 6; i++) {
			asc1[i] = Napi::Number::New(env, asc[i]);
		}
		for(int i = 0; i < 6; i++) {
			dsc1[i] = Napi::Number::New(env, dsc[i]);
		}
		for(int i = 0; i < 6; i++) {
			per1[i] = Napi::Number::New(env, per[i]);
		}
		for(int i = 0; i < 6; i++) {
			aph1[i] = Napi::Number::New(env, aph[i]);
		}
		obj.Set(Napi::String::New(env, "flag"), Napi::Number::New(env, flag));
		obj.Set(Napi::String::New(env, "error"), Napi::String::New(env, serr));
		obj.Set(Napi::String::New(env, "ascendingNode"), asc1);
		obj.Set(Napi::String::New(env, "descendingNode"), dsc1);
		obj.Set(Napi::String::New(env, "perihelion"), per1);
		obj.Set(Napi::String::New(env, "aphelion"), aph1);
		return obj;
	}));

	exports.Set(Napi::String::New(env, "get_orbital_elements"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 3) {
			Napi::TypeError::New(env, "Expecting 3 arguments").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[1].IsNumber()) {
			Napi::TypeError::New(env, "Argument 2 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[2].IsNumber()) {
			Napi::TypeError::New(env, "Argument 3 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		double ret [50];
		char serr [SE_MAX_STNAME];
		int flag = swe_get_orbital_elements(
			info[0].As<Napi::Number>().DoubleValue(),
			info[1].As<Napi::Number>().Int32Value(),
			info[2].As<Napi::Number>().Int32Value(),
			ret,
			serr
		);
		Napi::Array array = Napi::Array::New(env);
		for(int i = 0; i < 17; i++) {
			array[i] = Napi::Number::New(env, ret[i]);
		}
		array.Set(Napi::String::New(env, "flag"), Napi::Number::New(env, flag));
		array.Set(Napi::String::New(env, "error"), Napi::String::New(env, serr));
		return array;
	}));

	exports.Set(Napi::String::New(env, "orbit_max_min_true_distance"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 3) {
			Napi::TypeError::New(env, "Expecting 3 arguments").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[1].IsNumber()) {
			Napi::TypeError::New(env, "Argument 2 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[2].IsNumber()) {
			Napi::TypeError::New(env, "Argument 3 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		double dmax;
		double dmin;
		double dtrue;
		char serr [SE_MAX_STNAME];
		int flag = swe_orbit_max_min_true_distance(
			info[0].As<Napi::Number>().DoubleValue(),
			info[1].As<Napi::Number>().Int32Value(),
			info[2].As<Napi::Number>().Int32Value(),
			&dmax,
			&dmin,
			&dtrue,
			serr
		);
		Napi::Object obj = Napi::Object::New(env);
		obj.Set(Napi::String::New(env, "max"), Napi::Number::New(env, dmax));
		obj.Set(Napi::String::New(env, "min"), Napi::Number::New(env, dmin));
		obj.Set(Napi::String::New(env, "true"), Napi::Number::New(env, dtrue));
		obj.Set(Napi::String::New(env, "flag"), Napi::Number::New(env, flag));
		obj.Set(Napi::String::New(env, "error"), Napi::String::New(env, serr));
		return obj;
	}));

	exports.Set(Napi::String::New(env, "sol_eclipse_when_loc"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 4) {
			Napi::TypeError::New(env, "Expecting 4 arguments").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[1].IsNumber()) {
			Napi::TypeError::New(env, "Argument 2 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[2].IsArray()) {
			Napi::TypeError::New(env, "Argument 3 should be an array of 3 numbers").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[3].IsBoolean()) {
			Napi::TypeError::New(env, "Argument 4 should be a boolean").ThrowAsJavaScriptException();
			return env.Null();
		}
		Napi::Array geo = info[2].As<Napi::Array>();
		double geopos [3];
		for(int i = 0; i < 3; i++) {
			if(!((Napi::Value)geo[i]).IsNumber()) {
				Napi::TypeError::New(env, "Argument 3 should be an array of 3 numbers").ThrowAsJavaScriptException();
				return env.Null();
			}
			geopos[i] = ((Napi::Value)geo[i]).As<Napi::Number>().DoubleValue();
		}
		double ret [10];
		double attr [20];
		char serr [SE_MAX_STNAME];
		int flag = swe_sol_eclipse_when_loc(
			info[0].As<Napi::Number>().DoubleValue(),
			info[1].As<Napi::Number>().Int32Value(),
			geopos,
			ret,
			attr,
			info[3].As<Napi::Boolean>(),
			serr
		);
		Napi::Object obj = Napi::Object::New(env);
		Napi::Array ret1 = Napi::Array::New(env);
		Napi::Array attr1 = Napi::Array::New(env);
		for(int i = 0; i < 7; i++) {
			ret1[i] = Napi::Number::New(env, ret[i]);
		}
		for(int i = 0; i < 11; i++) {
			attr1[i] = Napi::Number::New(env, attr[i]);
		}
		obj.Set(Napi::String::New(env, "time"), ret1);
		obj.Set(Napi::String::New(env, "attributes"), attr1);
		obj.Set(Napi::String::New(env, "flag"), Napi::Number::New(env, flag));
		obj.Set(Napi::String::New(env, "error"), Napi::String::New(env, serr));
		return obj;
	}));

	exports.Set(Napi::String::New(env, "sol_eclipse_when_glob"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 4) {
			Napi::TypeError::New(env, "Expecting 4 arguments").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[1].IsNumber()) {
			Napi::TypeError::New(env, "Argument 2 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[2].IsNumber()) {
			Napi::TypeError::New(env, "Argument 3 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[3].IsBoolean()) {
			Napi::TypeError::New(env, "Argument 4 should be a boolean").ThrowAsJavaScriptException();
			return env.Null();
		}
		double ret [10];
		char serr [SE_MAX_STNAME];
		int flag = swe_sol_eclipse_when_glob(
			info[0].As<Napi::Number>().DoubleValue(),
			info[1].As<Napi::Number>().Int32Value(),
			info[2].As<Napi::Number>().Int32Value(),
			ret,
			info[3].As<Napi::Boolean>(),
			serr
		);
		Napi::Array ret1 = Napi::Array::New(env);
		for(int i = 0; i < 10; i++) {
			ret1[i] = Napi::Number::New(env, ret[i]);
		}
		ret1.Set(Napi::String::New(env, "flag"), Napi::Number::New(env, flag));
		ret1.Set(Napi::String::New(env, "error"), Napi::String::New(env, serr));
		return ret1;
	}));

	exports.Set(Napi::String::New(env, "sol_eclipse_how"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 3) {
			Napi::TypeError::New(env, "Expecting 3 arguments").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[1].IsNumber()) {
			Napi::TypeError::New(env, "Argument 2 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[2].IsArray()) {
			Napi::TypeError::New(env, "Argument 3 should be an array of 3 numbers").ThrowAsJavaScriptException();
			return env.Null();
		}
		Napi::Array geo = info[2].As<Napi::Array>();
		double geopos [3];
		for(int i = 0; i < 3; i++) {
			if(!((Napi::Value)geo[i]).IsNumber()) {
				Napi::TypeError::New(env, "Argument 3 should be an array of 3 numbers").ThrowAsJavaScriptException();
				return env.Null();
			}
			geopos[i] = ((Napi::Value)geo[i]).As<Napi::Number>().DoubleValue();
		}
		double attr [20];
		char serr [SE_MAX_STNAME];
		int flag = swe_sol_eclipse_how(
			info[0].As<Napi::Number>().DoubleValue(),
			info[1].As<Napi::Number>().Int32Value(),
			geopos,
			attr,
			serr
		);
		Napi::Array attr1 = Napi::Array::New(env);
		for(int i = 0; i < 11; i++) {
			attr1[i] = Napi::Number::New(env, attr[i]);
		}
		attr1.Set(Napi::String::New(env, "flag"), Napi::Number::New(env, flag));
		attr1.Set(Napi::String::New(env, "error"), Napi::String::New(env, serr));
		return attr1;
	}));

	exports.Set(Napi::String::New(env, "sol_eclipse_where"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 2) {
			Napi::TypeError::New(env, "Expecting 2 arguments").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[1].IsNumber()) {
			Napi::TypeError::New(env, "Argument 2 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		double geopos [10];
		double attr [20];
		char serr [SE_MAX_STNAME];
		int flag = swe_sol_eclipse_where(
			info[0].As<Napi::Number>().DoubleValue(),
			info[1].As<Napi::Number>().Int32Value(),
			geopos,
			attr,
			serr
		);
		Napi::Object obj = Napi::Object::New(env);
		Napi::Array geopos1 = Napi::Array::New(env);
		Napi::Array attr1 = Napi::Array::New(env);
		for(int i = 0; i < 10; i++) {
			geopos1[i] = Napi::Number::New(env, geopos[i]);
		}
		for(int i = 0; i < 11; i++) {
			attr1[i] = Napi::Number::New(env, attr[i]);
		}
		obj.Set(Napi::String::New(env, "coordinates"), geopos1);
		obj.Set(Napi::String::New(env, "attributes"), attr1);
		obj.Set(Napi::String::New(env, "flag"), Napi::Number::New(env, flag));
		obj.Set(Napi::String::New(env, "error"), Napi::String::New(env, serr));
		return obj;
	}));

	exports.Set(Napi::String::New(env, "lun_occult_when_loc"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 6) {
			Napi::TypeError::New(env, "Expecting 6 arguments").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[1].IsNumber()) {
			Napi::TypeError::New(env, "Argument 2 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[2].IsString() && !info[2].IsNull()) {
			Napi::TypeError::New(env, "Argument 3 should be a string or null").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[3].IsNumber()) {
			Napi::TypeError::New(env, "Argument 4 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[4].IsNumber()) {
			Napi::TypeError::New(env, "Argument 5 should be an array of 3 numbers").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[5].IsBoolean()) {
			Napi::TypeError::New(env, "Argument 6 should be a boolean").ThrowAsJavaScriptException();
			return env.Null();
		}
		Napi::Array geo = info[4].As<Napi::Array>();
		double geopos [3];
		for(int i = 0; i < 3; i++) {
			if(!((Napi::Value)geo[i]).IsNumber()) {
				Napi::TypeError::New(env, "Argument 5 should be an array of 3 numbers").ThrowAsJavaScriptException();
				return env.Null();
			}
			geopos[i] = ((Napi::Value)geo[i]).As<Napi::Number>().DoubleValue();
		}
		double ret [10];
		double attr [20];
		char serr [SE_MAX_STNAME];
		int flag = swe_lun_occult_when_loc(
			info[0].As<Napi::Number>().DoubleValue(),
			info[1].As<Napi::Number>().Int32Value(),
			(info[2].IsString()) ? const_cast<char*>(info[2].As<Napi::String>().Utf8Value().c_str()) : NULL,
			info[3].As<Napi::Number>().Int32Value(),
			geopos,
			ret,
			attr,
			info[5].As<Napi::Boolean>(),
			serr
		);
		Napi::Object obj = Napi::Object::New(env);
		Napi::Array ret1 = Napi::Array::New(env);
		Napi::Array attr1 = Napi::Array::New(env);
		for(int i = 0; i < 7; i++) {
			ret1[i] = Napi::Number::New(env, ret[i]);
		}
		for(int i = 0; i < 8; i++) {
			attr1[i] = Napi::Number::New(env, attr[i]);
		}
		obj.Set(Napi::String::New(env, "time"), ret1);
		obj.Set(Napi::String::New(env, "attributes"), attr1);
		obj.Set(Napi::String::New(env, "flag"), Napi::Number::New(env, flag));
		obj.Set(Napi::String::New(env, "error"), Napi::String::New(env, serr));
		return obj;
	}));

	exports.Set(Napi::String::New(env, "lun_occult_when_glob"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 6) {
			Napi::TypeError::New(env, "Expecting 6 arguments").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[1].IsNumber()) {
			Napi::TypeError::New(env, "Argument 2 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[2].IsString() && !info[2].IsNull()) {
			Napi::TypeError::New(env, "Argument 3 should be a string or null").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[3].IsNumber()) {
			Napi::TypeError::New(env, "Argument 4 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[4].IsNumber()) {
			Napi::TypeError::New(env, "Argument 5 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[5].IsBoolean()) {
			Napi::TypeError::New(env, "Argument 6 should be a boolean").ThrowAsJavaScriptException();
			return env.Null();
		}
		double ret [10];
		char serr [SE_MAX_STNAME];
		int flag = swe_lun_occult_when_glob(
			info[0].As<Napi::Number>().DoubleValue(),
			info[1].As<Napi::Number>().Int32Value(),
			(info[2].IsString()) ? const_cast<char*>(info[2].As<Napi::String>().Utf8Value().c_str()) : NULL,
			info[3].As<Napi::Number>().Int32Value(),
			info[4].As<Napi::Number>().Int32Value(),
			ret,
			info[5].As<Napi::Boolean>(),
			serr
		);
		Napi::Array ret1 = Napi::Array::New(env);
		for(int i = 0; i < 10; i++) {
			ret1[i] = Napi::Number::New(env, ret[i]);
		}
		ret1.Set(Napi::String::New(env, "flag"), Napi::Number::New(env, flag));
		ret1.Set(Napi::String::New(env, "error"), Napi::String::New(env, serr));
		return ret1;
	}));

	exports.Set(Napi::String::New(env, "lun_occult_where"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 4) {
			Napi::TypeError::New(env, "Expecting 4 arguments").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[1].IsNumber()) {
			Napi::TypeError::New(env, "Argument 2 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[2].IsString() && !info[2].IsNull()) {
			Napi::TypeError::New(env, "Argument 3 should be a string or null").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[3].IsNumber()) {
			Napi::TypeError::New(env, "Argument 4 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		double geopos [10];
		double attr [20];
		char serr [SE_MAX_STNAME];
		int flag = swe_lun_occult_where(
			info[0].As<Napi::Number>().DoubleValue(),
			info[1].As<Napi::Number>().Int32Value(),
			(info[2].IsString()) ? const_cast<char*>(info[2].As<Napi::String>().Utf8Value().c_str()) : NULL,
			info[3].As<Napi::Number>().Int32Value(),
			geopos,
			attr,
			serr
		);
		Napi::Object obj = Napi::Object::New(env);
		Napi::Array geopos1 = Napi::Array::New(env);
		Napi::Array attr1 = Napi::Array::New(env);
		for(int i = 0; i < 10; i++) {
			geopos1[i] = Napi::Number::New(env, geopos[i]);
		}
		for(int i = 0; i < 8; i++) {
			attr1[i] = Napi::Number::New(env, attr[i]);
		}
		obj.Set(Napi::String::New(env, "coordinates"), geopos1);
		obj.Set(Napi::String::New(env, "attributes"), attr1);
		obj.Set(Napi::String::New(env, "flag"), Napi::Number::New(env, flag));
		obj.Set(Napi::String::New(env, "error"), Napi::String::New(env, serr));
		return obj;
	}));

	exports.Set(Napi::String::New(env, "lun_eclipse_when_loc"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 4) {
			Napi::TypeError::New(env, "Expecting 4 arguments").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[1].IsNumber()) {
			Napi::TypeError::New(env, "Argument 2 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[2].IsArray()) {
			Napi::TypeError::New(env, "Argument 3 should be an array of 3 numbers").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[3].IsBoolean()) {
			Napi::TypeError::New(env, "Argument 4 should be a boolean").ThrowAsJavaScriptException();
			return env.Null();
		}
		Napi::Array geo = info[2].As<Napi::Array>();
		double geopos [3];
		for(int i = 0; i < 3; i++) {
			if(!((Napi::Value)geo[i]).IsNumber()) {
				Napi::TypeError::New(env, "Argument 3 should be an array of 3 numbers").ThrowAsJavaScriptException();
				return env.Null();
			}
			geopos[i] = ((Napi::Value)geo[i]).As<Napi::Number>().DoubleValue();
		}
		double ret [10];
		double attr [20];
		char serr [SE_MAX_STNAME];
		int flag = swe_lun_eclipse_when_loc(
			info[0].As<Napi::Number>().DoubleValue(),
			info[1].As<Napi::Number>().Int32Value(),
			geopos,
			ret,
			attr,
			info[3].As<Napi::Boolean>(),
			serr
		);
		Napi::Object obj = Napi::Object::New(env);
		Napi::Array ret1 = Napi::Array::New(env);
		Napi::Array attr1 = Napi::Array::New(env);
		for(int i = 0; i < 10; i++) {
			ret1[i] = Napi::Number::New(env, ret[i]);
		}
		for(int i = 0; i < 11; i++) {
			attr1[i] = Napi::Number::New(env, attr[i]);
		}
		obj.Set(Napi::String::New(env, "time"), ret1);
		obj.Set(Napi::String::New(env, "attributes"), attr1);
		obj.Set(Napi::String::New(env, "flag"), Napi::Number::New(env, flag));
		obj.Set(Napi::String::New(env, "error"), Napi::String::New(env, serr));
		return obj;
	}));

	exports.Set(Napi::String::New(env, "lun_eclipse_when"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 4) {
			Napi::TypeError::New(env, "Expecting 4 arguments").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[1].IsNumber()) {
			Napi::TypeError::New(env, "Argument 2 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[2].IsNumber()) {
			Napi::TypeError::New(env, "Argument 3 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[3].IsBoolean()) {
			Napi::TypeError::New(env, "Argument 4 should be a boolean").ThrowAsJavaScriptException();
			return env.Null();
		}
		double ret [10];
		char serr [SE_MAX_STNAME];
		int flag = swe_lun_eclipse_when(
			info[0].As<Napi::Number>().DoubleValue(),
			info[1].As<Napi::Number>().Int32Value(),
			info[2].As<Napi::Number>().Int32Value(),
			ret,
			info[3].As<Napi::Boolean>(),
			serr
		);
		Napi::Array ret1 = Napi::Array::New(env);
		for(int i = 0; i < 8; i++) {
			ret1[i] = Napi::Number::New(env, ret[i]);
		}
		ret1.Set(Napi::String::New(env, "flag"), Napi::Number::New(env, flag));
		ret1.Set(Napi::String::New(env, "error"), Napi::String::New(env, serr));
		return ret1;
	}));

	exports.Set(Napi::String::New(env, "lun_eclipse_how"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 3) {
			Napi::TypeError::New(env, "Expecting 3 arguments").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[1].IsNumber()) {
			Napi::TypeError::New(env, "Argument 2 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[2].IsArray()) {
			Napi::TypeError::New(env, "Argument 3 should be an array of 3 numbers").ThrowAsJavaScriptException();
			return env.Null();
		}
		Napi::Array geo = info[2].As<Napi::Array>();
		double geopos [3];
		for(int i = 0; i < 3; i++) {
			if(!((Napi::Value)geo[i]).IsNumber()) {
				Napi::TypeError::New(env, "Argument 3 should be an array of 3 numbers").ThrowAsJavaScriptException();
				return env.Null();
			}
			geopos[i] = ((Napi::Value)geo[i]).As<Napi::Number>().DoubleValue();
		}
		double attr [20];
		char serr [SE_MAX_STNAME];
		int flag = swe_lun_eclipse_how(
			info[0].As<Napi::Number>().DoubleValue(),
			info[1].As<Napi::Number>().Int32Value(),
			geopos,
			attr,
			serr
		);
		Napi::Array attr1 = Napi::Array::New(env);
		for(int i = 0; i < 11; i++) {
			attr1[i] = Napi::Number::New(env, attr[i]);
		}
		attr1.Set(Napi::String::New(env, "flag"), Napi::Number::New(env, flag));
		attr1.Set(Napi::String::New(env, "error"), Napi::String::New(env, serr));
		return attr1;
	}));

	exports.Set(Napi::String::New(env, "rise_trans"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 8) {
			Napi::TypeError::New(env, "Expecting 8 arguments").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[1].IsNumber()) {
			Napi::TypeError::New(env, "Argument 2 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[2].IsString() && !info[2].IsNull()) {
			Napi::TypeError::New(env, "Argument 3 should be a string or null").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[3].IsNumber()) {
			Napi::TypeError::New(env, "Argument 4 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[4].IsNumber()) {
			Napi::TypeError::New(env, "Argument 5 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[5].IsArray()) {
			Napi::TypeError::New(env, "Argument 6 should be an array of 3 numbers").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[6].IsNumber()) {
			Napi::TypeError::New(env, "Argument 7 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[7].IsNumber()) {
			Napi::TypeError::New(env, "Argument 8 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		Napi::Array geo = info[5].As<Napi::Array>();
		double geopos [3];
		for(int i = 0; i < 3; i++) {
			if(!((Napi::Value)geo[i]).IsNumber()) {
				Napi::TypeError::New(env, "Argument 6 should be an array of 3 numbers").ThrowAsJavaScriptException();
				return env.Null();
			}
			geopos[i] = ((Napi::Value)geo[i]).As<Napi::Number>().DoubleValue();
		}
		double ret;
		char serr [SE_MAX_STNAME];
		int flag = swe_rise_trans(
			info[0].As<Napi::Number>().DoubleValue(),
			info[1].As<Napi::Number>().Int32Value(),
			(info[2].IsString()) ? const_cast<char*>(info[2].As<Napi::String>().Utf8Value().c_str()) : NULL,
			info[3].As<Napi::Number>().Int32Value(),
			info[4].As<Napi::Number>().Int32Value(),
			geopos,
			info[6].As<Napi::Number>().DoubleValue(),
			info[7].As<Napi::Number>().DoubleValue(),
			&ret,
			serr
		);
		Napi::Object obj = Napi::Object::New(env);
		obj.Set(Napi::String::New(env, "flag"), Napi::Number::New(env, flag));
		obj.Set(Napi::String::New(env, "error"), Napi::String::New(env, serr));
		obj.Set(Napi::String::New(env, "time"), Napi::Number::New(env, ret));
		return obj;
	}));

	exports.Set(Napi::String::New(env, "rise_trans_true_hor"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 9) {
			Napi::TypeError::New(env, "Expecting 9 arguments").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[1].IsNumber()) {
			Napi::TypeError::New(env, "Argument 2 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[2].IsString() && !info[2].IsNull()) {
			Napi::TypeError::New(env, "Argument 3 should be a string or null").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[3].IsNumber()) {
			Napi::TypeError::New(env, "Argument 4 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[4].IsNumber()) {
			Napi::TypeError::New(env, "Argument 5 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[5].IsArray()) {
			Napi::TypeError::New(env, "Argument 6 should be an array of 3 numbers").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[6].IsNumber()) {
			Napi::TypeError::New(env, "Argument 7 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[7].IsNumber()) {
			Napi::TypeError::New(env, "Argument 8 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[8].IsNumber()) {
			Napi::TypeError::New(env, "Argument 9 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		Napi::Array geo = info[5].As<Napi::Array>();
		double geopos [3];
		for(int i = 0; i < 3; i++) {
			if(!((Napi::Value)geo[i]).IsNumber()) {
				Napi::TypeError::New(env, "Argument 6 should be an array of 3 numbers").ThrowAsJavaScriptException();
				return env.Null();
			}
			geopos[i] = ((Napi::Value)geo[i]).As<Napi::Number>().DoubleValue();
		}
		double ret;
		char serr [SE_MAX_STNAME];
		int flag = swe_rise_trans_true_hor(
			info[0].As<Napi::Number>().DoubleValue(),
			info[1].As<Napi::Number>().Int32Value(),
			(info[2].IsString()) ? const_cast<char*>(info[2].As<Napi::String>().Utf8Value().c_str()) : NULL,
			info[3].As<Napi::Number>().Int32Value(),
			info[4].As<Napi::Number>().Int32Value(),
			geopos,
			info[6].As<Napi::Number>().DoubleValue(),
			info[7].As<Napi::Number>().DoubleValue(),
			info[8].As<Napi::Number>().DoubleValue(),
			&ret,
			serr
		);
		Napi::Object obj = Napi::Object::New(env);
		obj.Set(Napi::String::New(env, "flag"), Napi::Number::New(env, flag));
		obj.Set(Napi::String::New(env, "error"), Napi::String::New(env, serr));
		obj.Set(Napi::String::New(env, "time"), Napi::Number::New(env, ret));
		return obj;
	}));

	exports.Set(Napi::String::New(env, "pheno_ut"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 3) {
			Napi::TypeError::New(env, "Expecting 3 arguments").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[1].IsNumber()) {
			Napi::TypeError::New(env, "Argument 2 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[2].IsNumber()) {
			Napi::TypeError::New(env, "Argument 3 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		double attr [20];
		char serr [SE_MAX_STNAME];
		int flag = swe_pheno_ut(
			info[0].As<Napi::Number>().DoubleValue(),
			info[1].As<Napi::Number>().Int32Value(),
			info[2].As<Napi::Number>().Int32Value(),
			attr,
			serr
		);
		Napi::Array attr1 = Napi::Array::New(env);
		for(int i = 0; i < 5; i++) {
			attr1[i] = Napi::Number::New(env, attr[i]);
		}
		attr1.Set(Napi::String::New(env, "flag"), Napi::Number::New(env, flag));
		attr1.Set(Napi::String::New(env, "error"), Napi::String::New(env, serr));
		return attr1;
	}));

	exports.Set(Napi::String::New(env, "pheno"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 3) {
			Napi::TypeError::New(env, "Expecting 3 arguments").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[1].IsNumber()) {
			Napi::TypeError::New(env, "Argument 2 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[2].IsNumber()) {
			Napi::TypeError::New(env, "Argument 3 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		double attr [20];
		char serr [SE_MAX_STNAME];
		int flag = swe_pheno(
			info[0].As<Napi::Number>().DoubleValue(),
			info[1].As<Napi::Number>().Int32Value(),
			info[2].As<Napi::Number>().Int32Value(),
			attr,
			serr
		);
		Napi::Array attr1 = Napi::Array::New(env);
		for(int i = 0; i < 5; i++) {
			attr1[i] = Napi::Number::New(env, attr[i]);
		}
		attr1.Set(Napi::String::New(env, "flag"), Napi::Number::New(env, flag));
		attr1.Set(Napi::String::New(env, "error"), Napi::String::New(env, serr));
		return attr1;
	}));

	exports.Set(Napi::String::New(env, "azalt"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 6) {
			Napi::TypeError::New(env, "Expecting 6 arguments").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[1].IsNumber()) {
			Napi::TypeError::New(env, "Argument 2 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[2].IsArray()) {
			Napi::TypeError::New(env, "Argument 3 should be an array of 3 numbers").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[3].IsNumber()) {
			Napi::TypeError::New(env, "Argument 4 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[4].IsNumber()) {
			Napi::TypeError::New(env, "Argument 5 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[5].IsArray()) {
			Napi::TypeError::New(env, "Argument 6 should be an array of 3 numbers").ThrowAsJavaScriptException();
			return env.Null();
		}
		Napi::Array geo = info[2].As<Napi::Array>();
		double geopos [3];
		for(int i = 0; i < 3; i++) {
			if(!((Napi::Value)geo[i]).IsNumber()) {
				Napi::TypeError::New(env, "Argument 3 should be an array of 3 numbers").ThrowAsJavaScriptException();
				return env.Null();
			}
			geopos[i] = ((Napi::Value)geo[i]).As<Napi::Number>().DoubleValue();
		}
		Napi::Array pos = info[5].As<Napi::Array>();
		double xin [3];
		for(int i = 0; i < 3; i++) {
			if(!((Napi::Value)pos[i]).IsNumber()) {
				Napi::TypeError::New(env, "Argument 6 should be an array of 3 numbers").ThrowAsJavaScriptException();
				return env.Null();
			}
			xin[i] = ((Napi::Value)pos[i]).As<Napi::Number>().DoubleValue();
		}
		double out [3];
		swe_azalt(
			info[0].As<Napi::Number>().DoubleValue(),
			info[1].As<Napi::Number>().Int32Value(),
			geopos,
			info[3].As<Napi::Number>().DoubleValue(),
			info[4].As<Napi::Number>().DoubleValue(),
			xin,
			out
		);
		Napi::Array out1 = Napi::Array::New(env);
		for(int i = 0; i < 3; i++) {
			out1[i] = Napi::Number::New(env, out[i]);
		}
		return out1;
	}));

	exports.Set(Napi::String::New(env, "azalt_rev"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 4) {
			Napi::TypeError::New(env, "Expecting 4 arguments").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[1].IsNumber()) {
			Napi::TypeError::New(env, "Argument 2 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[2].IsArray()) {
			Napi::TypeError::New(env, "Argument 3 should be an array of 3 numbers").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[3].IsArray()) {
			Napi::TypeError::New(env, "Argument 4 should be an array of 2 numbers").ThrowAsJavaScriptException();
			return env.Null();
		}
		Napi::Array geo = info[2].As<Napi::Array>();
		double geopos [3];
		for(int i = 0; i < 3; i++) {
			if(!((Napi::Value)geo[i]).IsNumber()) {
				Napi::TypeError::New(env, "Argument 3 should be an array of 3 numbers").ThrowAsJavaScriptException();
				return env.Null();
			}
			geopos[i] = ((Napi::Value)geo[i]).As<Napi::Number>().DoubleValue();
		}
		Napi::Array pos = info[3].As<Napi::Array>();
		double xin [2];
		for(int i = 0; i < 2; i++) {
			if(!((Napi::Value)pos[i]).IsNumber()) {
				Napi::TypeError::New(env, "Argument 4 should be an array of 2 numbers").ThrowAsJavaScriptException();
				return env.Null();
			}
			xin[i] = ((Napi::Value)pos[i]).As<Napi::Number>().DoubleValue();
		}
		double out [2];
		swe_azalt_rev(
			info[0].As<Napi::Number>().DoubleValue(),
			info[1].As<Napi::Number>().Int32Value(),
			geopos,
			xin,
			out
		);
		Napi::Array out1 = Napi::Array::New(env);
		for(int i = 0; i < 2; i++) {
			out1[i] = Napi::Number::New(env, out[i]);
		}
		return out1;
	}));

	exports.Set(Napi::String::New(env, "refrac"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 4) {
			Napi::TypeError::New(env, "Expecting 4 arguments").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[1].IsNumber()) {
			Napi::TypeError::New(env, "Argument 2 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[2].IsNumber()) {
			Napi::TypeError::New(env, "Argument 3 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[3].IsNumber()) {
			Napi::TypeError::New(env, "Argument 4 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		double out = swe_refrac(
			info[0].As<Napi::Number>().DoubleValue(),
			info[1].As<Napi::Number>().DoubleValue(),
			info[2].As<Napi::Number>().DoubleValue(),
			info[3].As<Napi::Number>().Int32Value()
		);
		return Napi::Number::New(env, out);
	}));

	exports.Set(Napi::String::New(env, "refrac_extended"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 6) {
			Napi::TypeError::New(env, "Expecting 6 arguments").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[1].IsNumber()) {
			Napi::TypeError::New(env, "Argument 2 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[2].IsNumber()) {
			Napi::TypeError::New(env, "Argument 3 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[3].IsNumber()) {
			Napi::TypeError::New(env, "Argument 4 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[4].IsNumber()) {
			Napi::TypeError::New(env, "Argument 5 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[5].IsNumber()) {
			Napi::TypeError::New(env, "Argument 6 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		double ret [20];
		double out = swe_refrac_extended(
			info[0].As<Napi::Number>().DoubleValue(),
			info[1].As<Napi::Number>().DoubleValue(),
			info[2].As<Napi::Number>().DoubleValue(),
			info[3].As<Napi::Number>().DoubleValue(),
			info[4].As<Napi::Number>().DoubleValue(),
			info[5].As<Napi::Number>().Int32Value(),
			ret
		);
		Napi::Array out1 = Napi::Array::New(env);
		for(int i = 0; i < 4; i++) {
			out1[i] = Napi::Number::New(env, ret[i]);
		}
		out1.Set(Napi::String::New(env, "altitude"), Napi::Number::New(env, out));
		return out1;
	}));

	exports.Set(Napi::String::New(env, "heliacal_ut"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 7) {
			Napi::TypeError::New(env, "Expecting 7 arguments").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[1].IsArray()) {
			Napi::TypeError::New(env, "Argument 2 should be an array of 3 numbers").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[2].IsArray()) {
			Napi::TypeError::New(env, "Argument 3 should be an array of 4 numbers").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[3].IsArray()) {
			Napi::TypeError::New(env, "Argument 4 should be an array of 6 numbers").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[4].IsString()) {
			Napi::TypeError::New(env, "Argument 5 should be a string").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[5].IsNumber()) {
			Napi::TypeError::New(env, "Argument 6 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[6].IsNumber()) {
			Napi::TypeError::New(env, "Argument 7 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		Napi::Array geo = info[1].As<Napi::Array>();
		double dgeo [3];
		for(int i = 0; i < 3; i++) {
			if(!((Napi::Value)geo[i]).IsNumber()) {
				Napi::TypeError::New(env, "Argument 1 should be an array of 3 numbers").ThrowAsJavaScriptException();
				return env.Null();
			}
			dgeo[i] = ((Napi::Value)geo[i]).As<Napi::Number>().DoubleValue();
		}
		Napi::Array atm = info[2].As<Napi::Array>();
		double datm [4];
		for(int i = 0; i < 4; i++) {
			if(!((Napi::Value)atm[i]).IsNumber()) {
				Napi::TypeError::New(env, "Argument 2 should be an array of 4 numbers").ThrowAsJavaScriptException();
				return env.Null();
			}
			datm[i] = ((Napi::Value)atm[i]).As<Napi::Number>().DoubleValue();
		}
		Napi::Array obs = info[3].As<Napi::Array>();
		double dobs [6];
		char serr [SE_MAX_STNAME];
		for(int i = 0; i < 6; i++) {
			if(!((Napi::Value)obs[i]).IsNumber()) {
				Napi::TypeError::New(env, "Argument 3 should be an array of 6 numbers").ThrowAsJavaScriptException();
				return env.Null();
			}
			dobs[i] = ((Napi::Value)obs[i]).As<Napi::Number>().DoubleValue();
		}
		double ret [50];
		int flag = swe_heliacal_ut(
			info[0].As<Napi::Number>().DoubleValue(),
			dgeo,
			datm,
			dobs,
			const_cast<char*>(info[4].As<Napi::String>().Utf8Value().c_str()),
			info[5].As<Napi::Number>().Int32Value(),
			info[6].As<Napi::Number>().Int32Value(),
			ret,
			serr
		);
		Napi::Array dret = Napi::Array::New(env);
		for(int i = 0; i < 3; i++) {
			dret[i] = Napi::Number::New(env, ret[i]);
		}
		dret.Set(Napi::String::New(env, "flag"), Napi::Number::New(env, flag));
		dret.Set(Napi::String::New(env, "error"), Napi::String::New(env, serr));
		return dret;
	}));

	exports.Set(Napi::String::New(env, "vis_limit_mag"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 6) {
			Napi::TypeError::New(env, "Expecting 6 arguments").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[1].IsArray()) {
			Napi::TypeError::New(env, "Argument 2 should be an array of 3 numbers").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[2].IsArray()) {
			Napi::TypeError::New(env, "Argument 3 should be an array of 4 numbers").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[3].IsArray()) {
			Napi::TypeError::New(env, "Argument 4 should be an array of 6 numbers").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[4].IsString()) {
			Napi::TypeError::New(env, "Argument 5 should be a string").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[5].IsNumber()) {
			Napi::TypeError::New(env, "Argument 6 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		Napi::Array geo = info[1].As<Napi::Array>();
		double dgeo [3];
		for(int i = 0; i < 3; i++) {
			if(!((Napi::Value)geo[i]).IsNumber()) {
				Napi::TypeError::New(env, "Argument 1 should be an array of 3 numbers").ThrowAsJavaScriptException();
				return env.Null();
			}
			dgeo[i] = ((Napi::Value)geo[i]).As<Napi::Number>().DoubleValue();
		}
		Napi::Array atm = info[2].As<Napi::Array>();
		double datm [4];
		for(int i = 0; i < 4; i++) {
			if(!((Napi::Value)atm[i]).IsNumber()) {
				Napi::TypeError::New(env, "Argument 2 should be an array of 4 numbers").ThrowAsJavaScriptException();
				return env.Null();
			}
			datm[i] = ((Napi::Value)atm[i]).As<Napi::Number>().DoubleValue();
		}
		Napi::Array obs = info[3].As<Napi::Array>();
		double dobs [6];
		char serr [SE_MAX_STNAME];
		for(int i = 0; i < 6; i++) {
			if(!((Napi::Value)obs[i]).IsNumber()) {
				Napi::TypeError::New(env, "Argument 3 should be an array of 6 numbers").ThrowAsJavaScriptException();
				return env.Null();
			}
			dobs[i] = ((Napi::Value)obs[i]).As<Napi::Number>().DoubleValue();
		}
		double ret [8];
		int flag = swe_vis_limit_mag(
			info[0].As<Napi::Number>().DoubleValue(),
			dgeo,
			datm,
			dobs,
			const_cast<char*>(info[4].As<Napi::String>().Utf8Value().c_str()),
			info[5].As<Napi::Number>().Int32Value(),
			ret,
			serr
		);
		Napi::Array dret = Napi::Array::New(env);
		for(int i = 0; i < 8; i++) {
			dret[i] = Napi::Number::New(env, ret[i]);
		}
		dret.Set(Napi::String::New(env, "flag"), Napi::Number::New(env, flag));
		dret.Set(Napi::String::New(env, "error"), Napi::String::New(env, serr));
		return dret;
	}));

	exports.Set(Napi::String::New(env, "heliacal_pheno_ut"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 6) {
			Napi::TypeError::New(env, "Expecting 6 arguments").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[1].IsArray()) {
			Napi::TypeError::New(env, "Argument 2 should be an array of 3 numbers").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[2].IsArray()) {
			Napi::TypeError::New(env, "Argument 3 should be an array of 4 numbers").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[3].IsArray()) {
			Napi::TypeError::New(env, "Argument 4 should be an array of 6 numbers").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[4].IsString()) {
			Napi::TypeError::New(env, "Argument 5 should be a string").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[5].IsNumber()) {
			Napi::TypeError::New(env, "Argument 6 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[6].IsNumber()) {
			Napi::TypeError::New(env, "Argument 7 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		Napi::Array geo = info[1].As<Napi::Array>();
		double dgeo [3];
		for(int i = 0; i < 3; i++) {
			if(!((Napi::Value)geo[i]).IsNumber()) {
				Napi::TypeError::New(env, "Argument 1 should be an array of 3 numbers").ThrowAsJavaScriptException();
				return env.Null();
			}
			dgeo[i] = ((Napi::Value)geo[i]).As<Napi::Number>().DoubleValue();
		}
		Napi::Array atm = info[2].As<Napi::Array>();
		double datm [4];
		for(int i = 0; i < 4; i++) {
			if(!((Napi::Value)atm[i]).IsNumber()) {
				Napi::TypeError::New(env, "Argument 2 should be an array of 4 numbers").ThrowAsJavaScriptException();
				return env.Null();
			}
			datm[i] = ((Napi::Value)atm[i]).As<Napi::Number>().DoubleValue();
		}
		Napi::Array obs = info[3].As<Napi::Array>();
		double dobs [6];
		char serr [SE_MAX_STNAME];
		for(int i = 0; i < 6; i++) {
			if(!((Napi::Value)obs[i]).IsNumber()) {
				Napi::TypeError::New(env, "Argument 3 should be an array of 6 numbers").ThrowAsJavaScriptException();
				return env.Null();
			}
			dobs[i] = ((Napi::Value)obs[i]).As<Napi::Number>().DoubleValue();
		}
		double ret [50];
		int flag = swe_heliacal_pheno_ut(
			info[0].As<Napi::Number>().DoubleValue(),
			dgeo,
			datm,
			dobs,
			const_cast<char*>(info[4].As<Napi::String>().Utf8Value().c_str()),
			info[5].As<Napi::Number>().Int32Value(),
			info[6].As<Napi::Number>().Int32Value(),
			ret,
			serr
		);
		Napi::Array dret = Napi::Array::New(env);
		for(int i = 0; i < 30; i++) {
			dret[i] = Napi::Number::New(env, ret[i]);
		}
		dret.Set(Napi::String::New(env, "flag"), Napi::Number::New(env, flag));
		dret.Set(Napi::String::New(env, "error"), Napi::String::New(env, serr));
		return dret;
	}));

	exports.Set(Napi::String::New(env, "julday"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 5) {
			Napi::TypeError::New(env, "Expecting 5 arguments").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[1].IsNumber()) {
			Napi::TypeError::New(env, "Argument 2 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[2].IsNumber()) {
			Napi::TypeError::New(env, "Argument 3 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[3].IsNumber()) {
			Napi::TypeError::New(env, "Argument 4 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[4].IsNumber()) {
			Napi::TypeError::New(env, "Argument 5 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		double time = swe_julday(
			info[0].As<Napi::Number>().Int32Value(),
			info[1].As<Napi::Number>().Int32Value(),
			info[2].As<Napi::Number>().Int32Value(),
			info[3].As<Napi::Number>().DoubleValue(),
			info[4].As<Napi::Number>().Int32Value()
		);
		return Napi::Number::New(env, time);
	}));

	exports.Set(Napi::String::New(env, "date_conversion"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 5) {
			Napi::TypeError::New(env, "Expecting 5 arguments").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[1].IsNumber()) {
			Napi::TypeError::New(env, "Argument 2 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[2].IsNumber()) {
			Napi::TypeError::New(env, "Argument 3 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[3].IsNumber()) {
			Napi::TypeError::New(env, "Argument 4 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[4].IsString()) {
			Napi::TypeError::New(env, "Argument 5 should be a string").ThrowAsJavaScriptException();
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
		obj.Set(Napi::String::New(env, "flag"), Napi::Number::New(env, flag));
		obj.Set(Napi::String::New(env, "jd"), Napi::Number::New(env, ret));
		return obj;
	}));

	exports.Set(Napi::String::New(env, "revjul"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 2) {
			Napi::TypeError::New(env, "Expecting 2 arguments").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[1].IsNumber()) {
			Napi::TypeError::New(env, "Argument 2 should be a number").ThrowAsJavaScriptException();
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
		obj.Set(Napi::String::New(env, "year"), Napi::Number::New(env, year));
		obj.Set(Napi::String::New(env, "month"), Napi::Number::New(env, month));
		obj.Set(Napi::String::New(env, "day"), Napi::Number::New(env, day));
		obj.Set(Napi::String::New(env, "hour"), Napi::Number::New(env, time));
		return obj;
	}));

	exports.Set(Napi::String::New(env, "utc_time_zone"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 7) {
			Napi::TypeError::New(env, "Expecting 7 arguments").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[1].IsNumber()) {
			Napi::TypeError::New(env, "Argument 2 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[2].IsNumber()) {
			Napi::TypeError::New(env, "Argument 3 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[3].IsNumber()) {
			Napi::TypeError::New(env, "Argument 4 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[4].IsNumber()) {
			Napi::TypeError::New(env, "Argument 5 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[5].IsNumber()) {
			Napi::TypeError::New(env, "Argument 6 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[6].IsNumber()) {
			Napi::TypeError::New(env, "Argument 7 should be a number").ThrowAsJavaScriptException();
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
		obj.Set(Napi::String::New(env, "year"), Napi::Number::New(env, year));
		obj.Set(Napi::String::New(env, "month"), Napi::Number::New(env, month));
		obj.Set(Napi::String::New(env, "day"), Napi::Number::New(env, day));
		obj.Set(Napi::String::New(env, "hour"), Napi::Number::New(env, hour));
		obj.Set(Napi::String::New(env, "minute"), Napi::Number::New(env, minute));
		obj.Set(Napi::String::New(env, "seconds"), Napi::Number::New(env, seconds));
		return obj;
	}));

	exports.Set(Napi::String::New(env, "utc_to_jd"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 7) {
			Napi::TypeError::New(env, "Expecting 7 arguments").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[1].IsNumber()) {
			Napi::TypeError::New(env, "Argument 2 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[2].IsNumber()) {
			Napi::TypeError::New(env, "Argument 3 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[3].IsNumber()) {
			Napi::TypeError::New(env, "Argument 4 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[4].IsNumber()) {
			Napi::TypeError::New(env, "Argument 5 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[5].IsNumber()) {
			Napi::TypeError::New(env, "Argument 6 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[6].IsNumber()) {
			Napi::TypeError::New(env, "Argument 7 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		double ret [2];
		char serr [SE_MAX_STNAME];
		int flag = swe_utc_to_jd(
			info[0].As<Napi::Number>().Int32Value(),
			info[1].As<Napi::Number>().Int32Value(),
			info[2].As<Napi::Number>().Int32Value(),
			info[3].As<Napi::Number>().Int32Value(),
			info[4].As<Napi::Number>().Int32Value(),
			info[5].As<Napi::Number>().DoubleValue(),
			info[6].As<Napi::Number>().Int32Value(),
			ret,
			serr
		);
		Napi::Array array = Napi::Array::New(env);
		for(int i = 0; i < 2; i++) {
			array[i] = Napi::Number::New(env, ret[i]);
		}
		array.Set(Napi::String::New(env, "flag"), Napi::Number::New(env, flag));
		array.Set(Napi::String::New(env, "error"), Napi::String::New(env, serr));
		return array;
	}));

	exports.Set(Napi::String::New(env, "jdet_to_utc"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 2) {
			Napi::TypeError::New(env, "Expecting 2 arguments").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[1].IsNumber()) {
			Napi::TypeError::New(env, "Argument 2 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		int year;
		int month;
		int day;
		int hour;
		int minute;
		double seconds;
		swe_jdet_to_utc(
			info[0].As<Napi::Number>().DoubleValue(),
			info[1].As<Napi::Number>().Int32Value(),
			&year,
			&month,
			&day,
			&hour,
			&minute,
			&seconds
		);
		Napi::Object obj = Napi::Object::New(env);
		obj.Set(Napi::String::New(env, "year"), Napi::Number::New(env, year));
		obj.Set(Napi::String::New(env, "month"), Napi::Number::New(env, month));
		obj.Set(Napi::String::New(env, "day"), Napi::Number::New(env, day));
		obj.Set(Napi::String::New(env, "hour"), Napi::Number::New(env, hour));
		obj.Set(Napi::String::New(env, "minute"), Napi::Number::New(env, minute));
		obj.Set(Napi::String::New(env, "seconds"), Napi::Number::New(env, seconds));
		return obj;
	}));

	exports.Set(Napi::String::New(env, "jdut1_to_utc"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 2) {
			Napi::TypeError::New(env, "Expecting 2 arguments").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[1].IsNumber()) {
			Napi::TypeError::New(env, "Argument 2 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		int year;
		int month;
		int day;
		int hour;
		int minute;
		double seconds;
		swe_jdut1_to_utc(
			info[0].As<Napi::Number>().DoubleValue(),
			info[1].As<Napi::Number>().Int32Value(),
			&year,
			&month,
			&day,
			&hour,
			&minute,
			&seconds
		);
		Napi::Object obj = Napi::Object::New(env);
		obj.Set(Napi::String::New(env, "year"), Napi::Number::New(env, year));
		obj.Set(Napi::String::New(env, "month"), Napi::Number::New(env, month));
		obj.Set(Napi::String::New(env, "day"), Napi::Number::New(env, day));
		obj.Set(Napi::String::New(env, "hour"), Napi::Number::New(env, hour));
		obj.Set(Napi::String::New(env, "minute"), Napi::Number::New(env, minute));
		obj.Set(Napi::String::New(env, "seconds"), Napi::Number::New(env, seconds));
		return obj;
	}));

	exports.Set(Napi::String::New(env, "time_equ"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 1) {
			Napi::TypeError::New(env, "Expecting 1 argument").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		double e;
		char serr [SE_MAX_STNAME];
		int flag = swe_time_equ(
			info[0].As<Napi::Number>().DoubleValue(),
			&e,
			serr
		);
		Napi::Object obj = Napi::Object::New(env);
		obj.Set(Napi::String::New(env, "flag"), Napi::Number::New(env, flag));
		obj.Set(Napi::String::New(env, "serr"), Napi::String::New(env, serr));
		obj.Set(Napi::String::New(env, "e"), Napi::Number::New(env, e));
		return obj;
	}));

	exports.Set(Napi::String::New(env, "lmt_to_lat"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 2) {
			Napi::TypeError::New(env, "Expecting 2 arguments").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[1].IsNumber()) {
			Napi::TypeError::New(env, "Argument 2 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		double conv;
		char serr [SE_MAX_STNAME];
		int flag = swe_lmt_to_lat(
			info[0].As<Napi::Number>().DoubleValue(),
			info[1].As<Napi::Number>().DoubleValue(),
			&conv,
			serr
		);
		Napi::Object obj = Napi::Object::New(env);
		obj.Set(Napi::String::New(env, "flag"), Napi::Number::New(env, flag));
		obj.Set(Napi::String::New(env, "serr"), Napi::String::New(env, serr));
		obj.Set(Napi::String::New(env, "lat"), Napi::Number::New(env, conv));
		return obj;
	}));

	exports.Set(Napi::String::New(env, "lat_to_lmt"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 2) {
			Napi::TypeError::New(env, "Expecting 2 arguments").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[1].IsNumber()) {
			Napi::TypeError::New(env, "Argument 2 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		double conv;
		char serr [SE_MAX_STNAME];
		int flag = swe_lat_to_lmt(
			info[0].As<Napi::Number>().DoubleValue(),
			info[1].As<Napi::Number>().DoubleValue(),
			&conv,
			serr
		);
		Napi::Object obj = Napi::Object::New(env);
		obj.Set(Napi::String::New(env, "flag"), Napi::Number::New(env, flag));
		obj.Set(Napi::String::New(env, "serr"), Napi::String::New(env, serr));
		obj.Set(Napi::String::New(env, "lmt"), Napi::Number::New(env, conv));
		return obj;
	}));

	exports.Set(Napi::String::New(env, "deltat_ex"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 2) {
			Napi::TypeError::New(env, "Expecting 2 arguments").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[1].IsNumber()) {
			Napi::TypeError::New(env, "Argument 2 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		char serr [SE_MAX_STNAME];
		double delta = swe_deltat_ex(
			info[0].As<Napi::Number>().DoubleValue(),
			info[1].As<Napi::Number>().Int32Value(),
			serr
		);
		Napi::Object obj = Napi::Object::New(env);
		obj.Set(Napi::String::New(env, "serr"), Napi::String::New(env, serr));
		obj.Set(Napi::String::New(env, "deltat"), Napi::Number::New(env, delta));
		return obj;
	}));

	exports.Set(Napi::String::New(env, "deltat"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 1) {
			Napi::TypeError::New(env, "Expecting 1 argument").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		double delta = swe_deltat(info[0].As<Napi::Number>().DoubleValue());
		return Napi::Number::New(env, delta);
	}));

	exports.Set(Napi::String::New(env, "get_tid_acc"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		return Napi::Number::New(env, swe_get_tid_acc());
	}));

	exports.Set(Napi::String::New(env, "set_tid_acc"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> void {
		Napi::Env env = info.Env();
		if(info.Length() < 1) {
			Napi::TypeError::New(env, "Expecting 1 argument").ThrowAsJavaScriptException();
			return;
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return;
		}
		swe_set_tid_acc(info[0].As<Napi::Number>().DoubleValue());
		return;
	}));

	exports.Set(Napi::String::New(env, "set_delta_t_userdef"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> void {
		Napi::Env env = info.Env();
		if(info.Length() < 1) {
			Napi::TypeError::New(env, "Expecting 1 argument").ThrowAsJavaScriptException();
			return;
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return;
		}
		swe_set_delta_t_userdef(info[0].As<Napi::Number>().DoubleValue());
		return;
	}));

	exports.Set(Napi::String::New(env, "set_topo"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> void {
		Napi::Env env = info.Env();
		if(info.Length() < 3) {
			Napi::TypeError::New(env, "Expecting 3 arguments").ThrowAsJavaScriptException();
			return;
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return;
		}
		if(!info[1].IsNumber()) {
			Napi::TypeError::New(env, "Argument 2 should be a number").ThrowAsJavaScriptException();
			return;
		}
		if(!info[2].IsNumber()) {
			Napi::TypeError::New(env, "Argument 3 should be a number").ThrowAsJavaScriptException();
			return;
		}
		swe_set_topo(
			info[0].As<Napi::Number>().DoubleValue(),
			info[1].As<Napi::Number>().DoubleValue(),
			info[2].As<Napi::Number>().DoubleValue()
		);
		return;
	}));

	exports.Set(Napi::String::New(env, "set_sid_mode"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> void {
		Napi::Env env = info.Env();
		if(info.Length() < 3) {
			Napi::TypeError::New(env, "Expecting 3 arguments").ThrowAsJavaScriptException();
			return;
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return;
		}
		if(!info[1].IsNumber()) {
			Napi::TypeError::New(env, "Argument 2 should be a number").ThrowAsJavaScriptException();
			return;
		}
		if(!info[2].IsNumber()) {
			Napi::TypeError::New(env, "Argument 3 should be a number").ThrowAsJavaScriptException();
			return;
		}
		swe_set_sid_mode(
			info[0].As<Napi::Number>().Int32Value(),
			info[1].As<Napi::Number>().DoubleValue(),
			info[2].As<Napi::Number>().DoubleValue()
		);
		return;
	}));

	exports.Set(Napi::String::New(env, "get_ayanamsa_name"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 1) {
			Napi::TypeError::New(env, "Expecting 1 argument").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		const char* name = swe_get_ayanamsa_name(info[0].As<Napi::Number>().Int32Value());
		if(name == NULL) {
			Napi::TypeError::New(env, "Invalid ayanamsa").ThrowAsJavaScriptException();
			return env.Null();
		}
		return Napi::String::New(env, name);
	}));

	exports.Set(Napi::String::New(env, "get_ayanamsa_ex_ut"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 2) {
			Napi::TypeError::New(env, "Expecting 2 arguments").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[1].IsNumber()) {
			Napi::TypeError::New(env, "Argument 2 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		double aya;
		char serr [SE_MAX_STNAME];
		int flag = swe_get_ayanamsa_ex_ut(
			info[0].As<Napi::Number>().DoubleValue(),
			info[1].As<Napi::Number>().Int32Value(),
			&aya,
			serr
		);
		Napi::Object obj = Napi::Object::New(env);
		obj.Set(Napi::String::New(env, "flag"), Napi::Number::New(env, flag));
		obj.Set(Napi::String::New(env, "serr"), Napi::String::New(env, serr));
		obj.Set(Napi::String::New(env, "ayanamsa"), Napi::Number::New(env, aya));
		return obj;
	}));

	exports.Set(Napi::String::New(env, "get_ayanamsa_ex"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 2) {
			Napi::TypeError::New(env, "Expecting 2 arguments").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[1].IsNumber()) {
			Napi::TypeError::New(env, "Argument 2 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		double aya;
		char serr [SE_MAX_STNAME];
		int flag = swe_get_ayanamsa_ex(
			info[0].As<Napi::Number>().DoubleValue(),
			info[1].As<Napi::Number>().Int32Value(),
			&aya,
			serr
		);
		Napi::Object obj = Napi::Object::New(env);
		obj.Set(Napi::String::New(env, "flag"), Napi::Number::New(env, flag));
		obj.Set(Napi::String::New(env, "serr"), Napi::String::New(env, serr));
		obj.Set(Napi::String::New(env, "ayanamsa"), Napi::Number::New(env, aya));
		return obj;
	}));

	exports.Set(Napi::String::New(env, "get_ayanamsa_ut"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 1) {
			Napi::TypeError::New(env, "Expecting 1 argument").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		return Napi::Number::New(env, swe_get_ayanamsa_ut(info[0].As<Napi::Number>().DoubleValue()));
	}));

	exports.Set(Napi::String::New(env, "get_ayanamsa"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 1) {
			Napi::TypeError::New(env, "Expecting 1 argument").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		return Napi::Number::New(env, swe_get_ayanamsa(info[0].As<Napi::Number>().DoubleValue()));
	}));

	exports.Set(Napi::String::New(env, "house_name"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 1) {
			Napi::TypeError::New(env, "Expecting 1 argument").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		const char* name = swe_house_name(info[0].As<Napi::Number>().Int32Value());
		if(name == NULL) {
			Napi::TypeError::New(env, "Invalid house system").ThrowAsJavaScriptException();
			return env.Null();
		}
		return Napi::String::New(env, name);
	}));

	exports.Set(Napi::String::New(env, "houses"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 4) {
			Napi::TypeError::New(env, "Expecting 4 arguments").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[1].IsNumber()) {
			Napi::TypeError::New(env, "Argument 2 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[2].IsNumber()) {
			Napi::TypeError::New(env, "Argument 3 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[3].IsString()) {
			Napi::TypeError::New(env, "Argument 4 should be a string").ThrowAsJavaScriptException();
			return env.Null();
		}
		double cusps [37];
		double points [10];
		char sys = info[3].As<Napi::String>().Utf8Value()[0];
		int flag = swe_houses(
			info[0].As<Napi::Number>().DoubleValue(),
			info[1].As<Napi::Number>().DoubleValue(),
			info[2].As<Napi::Number>().DoubleValue(),
			int(sys),
			cusps,
			points
		);
		Napi::Object obj = Napi::Object::New(env);
		Napi::Array c1 = Napi::Array::New(env);
		Napi::Array p1 = Napi::Array::New(env);
		for(int i = 1; i < (sys == 'G' ? 37 : 13); i++) {
			c1[i] = Napi::Number::New(env, cusps[i]);
		}
		for(int i = 0; i < 8; i++) {
			p1[i] = Napi::Number::New(env, points[i]);
		}
		obj.Set(Napi::String::New(env, "houses"), c1);
		obj.Set(Napi::String::New(env, "points"), p1);
		obj.Set(Napi::String::New(env, "flag"), Napi::Number::New(env, flag));
		return obj;
	}));

	exports.Set(Napi::String::New(env, "houses_armc"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 4) {
			Napi::TypeError::New(env, "Expecting 4 arguments").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[1].IsNumber()) {
			Napi::TypeError::New(env, "Argument 2 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[2].IsNumber()) {
			Napi::TypeError::New(env, "Argument 3 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[3].IsString()) {
			Napi::TypeError::New(env, "Argument 4 should be a string").ThrowAsJavaScriptException();
			return env.Null();
		}
		double cusps [37];
		double points [10];
		char sys = info[3].As<Napi::String>().Utf8Value()[0];
		int flag = swe_houses_armc(
			info[0].As<Napi::Number>().DoubleValue(),
			info[1].As<Napi::Number>().DoubleValue(),
			info[2].As<Napi::Number>().DoubleValue(),
			int(sys),
			cusps,
			points
		);
		Napi::Object obj = Napi::Object::New(env);
		Napi::Array c1 = Napi::Array::New(env);
		Napi::Array p1 = Napi::Array::New(env);
		for(int i = 1; i < (sys == 'G' ? 37 : 13); i++) {
			c1[i] = Napi::Number::New(env, cusps[i]);
		}
		for(int i = 0; i < 8; i++) {
			p1[i] = Napi::Number::New(env, points[i]);
		}
		obj.Set(Napi::String::New(env, "houses"), c1);
		obj.Set(Napi::String::New(env, "points"), p1);
		obj.Set(Napi::String::New(env, "flag"), Napi::Number::New(env, flag));
		return obj;
	}));

	exports.Set(Napi::String::New(env, "houses_armc_ex2"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 4) {
			Napi::TypeError::New(env, "Expecting 4 arguments").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[1].IsNumber()) {
			Napi::TypeError::New(env, "Argument 2 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[2].IsNumber()) {
			Napi::TypeError::New(env, "Argument 3 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[3].IsString()) {
			Napi::TypeError::New(env, "Argument 4 should be a string").ThrowAsJavaScriptException();
			return env.Null();
		}
		double cusps [37];
		double points [10];
		double cspeed [37];
		double pspeed [10];
		char serr [SE_MAX_STNAME];
		char sys = info[3].As<Napi::String>().Utf8Value()[0];
		int flag = swe_houses_armc_ex2(
			info[0].As<Napi::Number>().DoubleValue(),
			info[1].As<Napi::Number>().DoubleValue(),
			info[2].As<Napi::Number>().DoubleValue(),
			int(sys),
			cusps,
			points,
			cspeed,
			pspeed,
			serr
		);
		Napi::Object obj = Napi::Object::New(env);
		Napi::Array c1 = Napi::Array::New(env);
		Napi::Array p1 = Napi::Array::New(env);
		Napi::Array cs1 = Napi::Array::New(env);
		Napi::Array ps1 = Napi::Array::New(env);
		for(int i = 1; i < (sys == 'G' ? 37 : 13); i++) {
			c1[i] = Napi::Number::New(env, cusps[i]);
		}
		for(int i = 0; i < 8; i++) {
			p1[i] = Napi::Number::New(env, points[i]);
		}
		for(int i = 1; i < (sys == 'G' ? 37 : 13); i++) {
			cs1[i] = Napi::Number::New(env, cspeed[i]);
		}
		for(int i = 0; i < 8; i++) {
			ps1[i] = Napi::Number::New(env, pspeed[i]);
		}
		obj.Set(Napi::String::New(env, "houses"), c1);
		obj.Set(Napi::String::New(env, "points"), p1);
		obj.Set(Napi::String::New(env, "housesSpeed"), cs1);
		obj.Set(Napi::String::New(env, "pointsSpeed"), ps1);
		obj.Set(Napi::String::New(env, "flag"), Napi::Number::New(env, flag));
		obj.Set(Napi::String::New(env, "error"), Napi::String::New(env, serr));
		return obj;
	}));

	exports.Set(Napi::String::New(env, "houses_ex"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 5) {
			Napi::TypeError::New(env, "Expecting 5 arguments").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[1].IsNumber()) {
			Napi::TypeError::New(env, "Argument 2 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[2].IsNumber()) {
			Napi::TypeError::New(env, "Argument 3 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[3].IsNumber()) {
			Napi::TypeError::New(env, "Argument 4 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[4].IsString()) {
			Napi::TypeError::New(env, "Argument 5 should be a string").ThrowAsJavaScriptException();
			return env.Null();
		}
		double cusps [37];
		double points [10];
		char sys = info[4].As<Napi::String>().Utf8Value()[0];
		int flag = swe_houses_ex(
			info[0].As<Napi::Number>().DoubleValue(),
			info[1].As<Napi::Number>().Int32Value(),
			info[2].As<Napi::Number>().DoubleValue(),
			info[3].As<Napi::Number>().DoubleValue(),
			int(sys),
			cusps,
			points
		);
		Napi::Object obj = Napi::Object::New(env);
		Napi::Array c1 = Napi::Array::New(env);
		Napi::Array p1 = Napi::Array::New(env);
		for(int i = 1; i < (sys == 'G' ? 37 : 13); i++) {
			c1[i] = Napi::Number::New(env, cusps[i]);
		}
		for(int i = 0; i < 8; i++) {
			p1[i] = Napi::Number::New(env, points[i]);
		}
		obj.Set(Napi::String::New(env, "houses"), c1);
		obj.Set(Napi::String::New(env, "points"), p1);
		obj.Set(Napi::String::New(env, "flag"), Napi::Number::New(env, flag));
		return obj;
	}));

	exports.Set(Napi::String::New(env, "houses_ex2"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 5) {
			Napi::TypeError::New(env, "Expecting 5 arguments").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[1].IsNumber()) {
			Napi::TypeError::New(env, "Argument 2 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[2].IsNumber()) {
			Napi::TypeError::New(env, "Argument 3 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[3].IsNumber()) {
			Napi::TypeError::New(env, "Argument 4 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[4].IsString()) {
			Napi::TypeError::New(env, "Argument 5 should be a string").ThrowAsJavaScriptException();
			return env.Null();
		}
		double cusps [37];
		double points [10];
		double cspeed [37];
		double pspeed [10];
		char serr [SE_MAX_STNAME];
		char sys = info[4].As<Napi::String>().Utf8Value()[0];
		int flag = swe_houses_ex2(
			info[0].As<Napi::Number>().DoubleValue(),
			info[1].As<Napi::Number>().Int32Value(),
			info[2].As<Napi::Number>().DoubleValue(),
			info[3].As<Napi::Number>().DoubleValue(),
			int(sys),
			cusps,
			points,
			cspeed,
			pspeed,
			serr
		);
		Napi::Object obj = Napi::Object::New(env);
		Napi::Array c1 = Napi::Array::New(env);
		Napi::Array p1 = Napi::Array::New(env);
		Napi::Array cs1 = Napi::Array::New(env);
		Napi::Array ps1 = Napi::Array::New(env);
		for(int i = 1; i < (sys == 'G' ? 37 : 13); i++) {
			c1[i] = Napi::Number::New(env, cusps[i]);
		}
		for(int i = 0; i < 8; i++) {
			p1[i] = Napi::Number::New(env, points[i]);
		}
		for(int i = 1; i < (sys == 'G' ? 37 : 13); i++) {
			cs1[i] = Napi::Number::New(env, cspeed[i]);
		}
		for(int i = 0; i < 8; i++) {
			ps1[i] = Napi::Number::New(env, pspeed[i]);
		}
		obj.Set(Napi::String::New(env, "houses"), c1);
		obj.Set(Napi::String::New(env, "points"), p1);
		obj.Set(Napi::String::New(env, "housesSpeed"), cs1);
		obj.Set(Napi::String::New(env, "pointsSpeed"), ps1);
		obj.Set(Napi::String::New(env, "flag"), Napi::Number::New(env, flag));
		obj.Set(Napi::String::New(env, "error"), Napi::String::New(env, serr));
		return obj;
	}));

	exports.Set(Napi::String::New(env, "house_pos"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 5) {
			Napi::TypeError::New(env, "Expecting 5 arguments").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[1].IsNumber()) {
			Napi::TypeError::New(env, "Argument 2 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[2].IsNumber()) {
			Napi::TypeError::New(env, "Argument 3 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[3].IsString()) {
			Napi::TypeError::New(env, "Argument 4 should be a string").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[4].IsArray()) {
			Napi::TypeError::New(env, "Argument 5 should be an array of 2 numbers").ThrowAsJavaScriptException();
			return env.Null();
		}
		Napi::Array pos = info[4].As<Napi::Array>();
		double planet [2];
		for(int i = 0; i < 2; i++) {
			if(!((Napi::Value)pos[i]).IsNumber()) {
				Napi::TypeError::New(env, "Argument 5 should be an array of 2 numbers").ThrowAsJavaScriptException();
				return env.Null();
			}
			planet[i] = ((Napi::Value)pos[i]).As<Napi::Number>().DoubleValue();
		}
		char serr [SE_MAX_STNAME];
		char sys = info[3].As<Napi::String>().Utf8Value()[0];
		double house = swe_house_pos(
			info[0].As<Napi::Number>().DoubleValue(),
			info[1].As<Napi::Number>().DoubleValue(),
			info[2].As<Napi::Number>().DoubleValue(),
			int(sys),
			planet,
			serr
		);
		Napi::Object obj = Napi::Object::New(env);
		obj.Set(Napi::String::New(env, "house"), house);
		obj.Set(Napi::String::New(env, "error"), Napi::String::New(env, serr));
		return obj;
	}));

	exports.Set(Napi::String::New(env, "gauquelin_sector"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 8) {
			Napi::TypeError::New(env, "Expecting 8 arguments").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[1].IsNumber()) {
			Napi::TypeError::New(env, "Argument 2 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[2].IsString() && !info[2].IsNull()) {
			Napi::TypeError::New(env, "Argument 3 should be a string or null").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[3].IsNumber()) {
			Napi::TypeError::New(env, "Argument 4 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[4].IsNumber()) {
			Napi::TypeError::New(env, "Argument 5 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[5].IsArray()) {
			Napi::TypeError::New(env, "Argument 6 should be an array of 3 numbers").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[6].IsNumber()) {
			Napi::TypeError::New(env, "Argument 7 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[7].IsNumber()) {
			Napi::TypeError::New(env, "Argument 8 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		Napi::Array geo = info[5].As<Napi::Array>();
		double geopos [3];
		for(int i = 0; i < 3; i++) {
			if(!((Napi::Value)geo[i]).IsNumber()) {
				Napi::TypeError::New(env, "Argument 6 should be an array of 3 numbers").ThrowAsJavaScriptException();
				return env.Null();
			}
			geopos[i] = ((Napi::Value)geo[i]).As<Napi::Number>().DoubleValue();
		}
		double sect;
		char serr [SE_MAX_STNAME];
		int flag = swe_gauquelin_sector(
			info[0].As<Napi::Number>().DoubleValue(),
			info[1].As<Napi::Number>().Int32Value(),
			(info[2].IsString()) ? const_cast<char*>(info[2].As<Napi::String>().Utf8Value().c_str()) : NULL,
			info[3].As<Napi::Number>().Int32Value(),
			info[4].As<Napi::Number>().Int32Value(),
			geopos,
			info[6].As<Napi::Number>().DoubleValue(),
			info[7].As<Napi::Number>().DoubleValue(),
			&sect,
			serr
		);
		Napi::Object obj = Napi::Object::New(env);
		obj.Set(Napi::String::New(env, "sector"), Napi::Number::New(env, sect));
		obj.Set(Napi::String::New(env, "flag"), Napi::Number::New(env, flag));
		obj.Set(Napi::String::New(env, "error"), Napi::String::New(env, serr));
		return obj;
	}));

	exports.Set(Napi::String::New(env, "sidtime"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 1) {
			Napi::TypeError::New(env, "Expecting 1 argument").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		return Napi::Number::New(env, swe_sidtime(info[0].As<Napi::Number>().DoubleValue()));
	}));

	exports.Set(Napi::String::New(env, "sidtime0"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 3) {
			Napi::TypeError::New(env, "Expecting 3 arguments").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[1].IsNumber()) {
			Napi::TypeError::New(env, "Argument 2 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[2].IsNumber()) {
			Napi::TypeError::New(env, "Argument 3 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		double time = swe_sidtime0(
			info[0].As<Napi::Number>().DoubleValue(),
			info[1].As<Napi::Number>().DoubleValue(),
			info[2].As<Napi::Number>().DoubleValue()
		);
		return Napi::Number::New(env, time);
	}));

	exports.Set(Napi::String::New(env, "cotrans"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 2) {
			Napi::TypeError::New(env, "Expecting 3 arguments").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsArray()) {
			Napi::TypeError::New(env, "Argument 1 should be an array of 3 numbers").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[1].IsNumber()) {
			Napi::TypeError::New(env, "Argument 2 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		Napi::Array coords = info[0].As<Napi::Array>();
		double in [3];
		for(int i = 0; i < 3; i++) {
			if(!((Napi::Value)coords[i]).IsNumber()) {
				Napi::TypeError::New(env, "Argument 1 should be an array of 3 numbers").ThrowAsJavaScriptException();
				return env.Null();
			}
			in[i] = ((Napi::Value)coords[i]).As<Napi::Number>().DoubleValue();
		}
		double out [3];
		swe_cotrans(
			in,
			out,
			info[1].As<Napi::Number>().DoubleValue()
		);
		Napi::Array array = Napi::Array::New(env);
		for(int i = 1; i < 3; i++) {
			array[i] = Napi::Number::New(env, out[i]);
		}
		return array;
	}));

	exports.Set(Napi::String::New(env, "cotrans_sp"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 2) {
			Napi::TypeError::New(env, "Expecting 3 arguments").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsArray()) {
			Napi::TypeError::New(env, "Argument 1 should be an array of 6 numbers").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[1].IsNumber()) {
			Napi::TypeError::New(env, "Argument 2 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		Napi::Array coords = info[0].As<Napi::Array>();
		double in [6];
		for(int i = 0; i < 6; i++) {
			if(!((Napi::Value)coords[i]).IsNumber()) {
				Napi::TypeError::New(env, "Argument 1 should be an array of 6 numbers").ThrowAsJavaScriptException();
				return env.Null();
			}
			in[i] = ((Napi::Value)coords[i]).As<Napi::Number>().DoubleValue();
		}
		double out [6];
		swe_cotrans_sp(
			in,
			out,
			info[1].As<Napi::Number>().DoubleValue()
		);
		Napi::Array array = Napi::Array::New(env);
		for(int i = 1; i < 6; i++) {
			array[i] = Napi::Number::New(env, out[i]);
		}
		return array;
	}));

	exports.Set(Napi::String::New(env, "degnorm"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 1) {
			Napi::TypeError::New(env, "Expecting 1 argument").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		return Napi::Number::New(env, swe_degnorm(info[0].As<Napi::Number>().DoubleValue()));
	}));

	exports.Set(Napi::String::New(env, "radnorm"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 1) {
			Napi::TypeError::New(env, "Expecting 1 argument").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		return Napi::Number::New(env, swe_radnorm(info[0].As<Napi::Number>().DoubleValue()));
	}));

	exports.Set(Napi::String::New(env, "split_deg"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 1) {
			Napi::TypeError::New(env, "Expecting 1 argument").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[1].IsNumber()) {
			Napi::TypeError::New(env, "Argument 2 should be a number").ThrowAsJavaScriptException();
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
		obj.Set(Napi::String::New(env, "degree"), Napi::Number::New(env, deg));
		obj.Set(Napi::String::New(env, "minute"), Napi::Number::New(env, min));
		obj.Set(Napi::String::New(env, "second"), Napi::Number::New(env, sec));
		obj.Set(Napi::String::New(env, "fraction"), Napi::Number::New(env, fraction));
		obj.Set(Napi::String::New(env, "sign"), Napi::Number::New(env, sign));
		return obj;
	}));

	exports.Set(Napi::String::New(env, "csnorm"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 1) {
			Napi::TypeError::New(env, "Expecting 1 argument").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		return Napi::Number::New(env, swe_csnorm(info[0].As<Napi::Number>().Int32Value()));
	}));

	exports.Set(Napi::String::New(env, "difcsn"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 2) {
			Napi::TypeError::New(env, "Expecting 2 arguments").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[1].IsNumber()) {
			Napi::TypeError::New(env, "Argument 2 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		int dif = swe_difcsn(
			info[0].As<Napi::Number>().Int32Value(),
			info[1].As<Napi::Number>().Int32Value()
		);
		return Napi::Number::New(env, dif);
	}));

	exports.Set(Napi::String::New(env, "difdegn"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 2) {
			Napi::TypeError::New(env, "Expecting 2 arguments").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[1].IsNumber()) {
			Napi::TypeError::New(env, "Argument 2 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		double dif = swe_difdegn(
			info[0].As<Napi::Number>().DoubleValue(),
			info[1].As<Napi::Number>().DoubleValue()
		);
		return Napi::Number::New(env, dif);
	}));

	exports.Set(Napi::String::New(env, "difcs2n"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 2) {
			Napi::TypeError::New(env, "Expecting 2 arguments").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[1].IsNumber()) {
			Napi::TypeError::New(env, "Argument 2 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		int dif = swe_difcs2n(
			info[0].As<Napi::Number>().Int32Value(),
			info[1].As<Napi::Number>().Int32Value()
		);
		return Napi::Number::New(env, dif);
	}));

	exports.Set(Napi::String::New(env, "difdeg2n"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 2) {
			Napi::TypeError::New(env, "Expecting 2 arguments").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[1].IsNumber()) {
			Napi::TypeError::New(env, "Argument 2 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		double dif = swe_difdeg2n(
			info[0].As<Napi::Number>().DoubleValue(),
			info[1].As<Napi::Number>().DoubleValue()
		);
		return Napi::Number::New(env, dif);
	}));

	exports.Set(Napi::String::New(env, "csroundsec"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 1) {
			Napi::TypeError::New(env, "Expecting 1 argument").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		return Napi::Number::New(env, swe_csroundsec(info[0].As<Napi::Number>().Int32Value()));
	}));

	exports.Set(Napi::String::New(env, "d2l"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 1) {
			Napi::TypeError::New(env, "Expecting 1 argument").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		return Napi::Number::New(env, swe_d2l(info[0].As<Napi::Number>().DoubleValue()));
	}));

	exports.Set(Napi::String::New(env, "day_of_week"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 1) {
			Napi::TypeError::New(env, "Expecting 1 argument").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		return Napi::Number::New(env, swe_day_of_week(info[0].As<Napi::Number>().DoubleValue()));
	}));

	exports.Set(Napi::String::New(env, "cs2timestr"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 3) {
			Napi::TypeError::New(env, "Expecting 3 arguments").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[1].IsString()) {
			Napi::TypeError::New(env, "Argument 2 should be a string").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[2].IsBoolean()) {
			Napi::TypeError::New(env, "Argument 3 should be a boolean").ThrowAsJavaScriptException();
			return env.Null();
		}
		char out [SE_MAX_STNAME];
		swe_cs2timestr(
			info[0].As<Napi::Number>().Int32Value(),
			int(info[1].As<Napi::String>().Utf8Value()[0]),
			info[2].As<Napi::Boolean>(),
			out
		);
		return Napi::String::New(env, out);
	}));

	exports.Set(Napi::String::New(env, "cs2lonlatstr"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 3) {
			Napi::TypeError::New(env, "Expecting 3 arguments").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[1].IsString()) {
			Napi::TypeError::New(env, "Argument 2 should be a string").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[2].IsString()) {
			Napi::TypeError::New(env, "Argument 3 should be a string").ThrowAsJavaScriptException();
			return env.Null();
		}
		char out [SE_MAX_STNAME];
		swe_cs2lonlatstr(
			info[0].As<Napi::Number>().Int32Value(),
			info[1].As<Napi::String>().Utf8Value()[0],
			info[2].As<Napi::String>().Utf8Value()[0],
			out
		);
		return Napi::String::New(env, out);
	}));

	exports.Set(Napi::String::New(env, "cs2degstr"), Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
		Napi::Env env = info.Env();
		if(info.Length() < 1) {
			Napi::TypeError::New(env, "Expecting 1 argument").ThrowAsJavaScriptException();
			return env.Null();
		}
		if(!info[0].IsNumber()) {
			Napi::TypeError::New(env, "Argument 1 should be a number").ThrowAsJavaScriptException();
			return env.Null();
		}
		char out [SE_MAX_STNAME];
		swe_cs2degstr(
			info[0].As<Napi::Number>().Int32Value(),
			out
		);
		return Napi::String::New(env, out);
	}));

	return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init);

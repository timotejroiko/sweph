#include "sweph.h"

Napi::Value sweph_calc_pctr(const Napi::CallbackInfo& info) {
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
    if(!info[3].IsNumber()) {
        Napi::TypeError::New(env, "Argument 3 should be a number").ThrowAsJavaScriptException();
        return env.Null();
    }
    double xx [6];
    char serr [SE_MAX_STNAME];
    int flag = swe_calc_pctr(
        info[0].As<Napi::Number>().DoubleValue(),
        info[1].As<Napi::Number>().Int32Value(),
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
}

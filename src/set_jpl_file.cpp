#include "sweph.h"

void sweph_set_jpl_file(const Napi::CallbackInfo& info) {
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
}

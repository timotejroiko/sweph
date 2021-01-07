#include "sweph.h"

void sweph_set_ephe_path(const Napi::CallbackInfo& info) {
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
}

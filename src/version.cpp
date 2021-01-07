#include "sweph.h"

Napi::String sweph_version(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    char version [SE_MAX_STNAME];
    swe_version(version);
    return Napi::String::New(env, version);
}

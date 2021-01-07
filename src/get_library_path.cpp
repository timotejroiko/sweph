#include "sweph.h"

Napi::String sweph_get_library_path(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    char path [SE_MAX_STNAME];
    swe_get_library_path(path);
    return Napi::String::New(env, path);
}

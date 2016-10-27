// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from application.djinni

#pragma once

#include "djinni_support.hpp"
#include "intention.hpp"

namespace djinni_generated {

class NativeIntention final : ::djinni::JniEnum {
public:
    using CppType = ::naomi_gen::intention;
    using JniType = jobject;

    using Boxed = NativeIntention;

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return static_cast<CppType>(::djinni::JniClass<NativeIntention>::get().ordinal(jniEnv, j)); }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, CppType c) { return ::djinni::JniClass<NativeIntention>::get().create(jniEnv, static_cast<jint>(c)); }

private:
    NativeIntention() : JniEnum("com/siliconbear/kitchen/Intention") {}
    friend ::djinni::JniClass<NativeIntention>;
};

}  // namespace djinni_generated
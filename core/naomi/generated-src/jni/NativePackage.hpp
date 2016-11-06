// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from application.djinni

#pragma once

#include "djinni_support.hpp"
#include "package.hpp"

namespace djinni_generated {

class NativePackage final : ::djinni::JniEnum {
public:
    using CppType = ::naomi_gen::package;
    using JniType = jobject;

    using Boxed = NativePackage;

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return static_cast<CppType>(::djinni::JniClass<NativePackage>::get().ordinal(jniEnv, j)); }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, CppType c) { return ::djinni::JniClass<NativePackage>::get().create(jniEnv, static_cast<jint>(c)); }

private:
    NativePackage() : JniEnum("com/siliconbear/kitchen/Package") {}
    friend ::djinni::JniClass<NativePackage>;
};

}  // namespace djinni_generated

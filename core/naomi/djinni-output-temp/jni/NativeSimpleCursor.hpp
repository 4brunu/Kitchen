// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from chef.djinni

#pragma once

#include "djinni_support.hpp"
#include "simple_cursor.hpp"

namespace djinni_generated {

class NativeSimpleCursor final : ::djinni::JniInterface<::naomi_gen::SimpleCursor, NativeSimpleCursor> {
public:
    using CppType = std::shared_ptr<::naomi_gen::SimpleCursor>;
    using CppOptType = std::shared_ptr<::naomi_gen::SimpleCursor>;
    using JniType = jobject;

    using Boxed = NativeSimpleCursor;

    ~NativeSimpleCursor();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<NativeSimpleCursor>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<NativeSimpleCursor>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    NativeSimpleCursor();
    friend ::djinni::JniClass<NativeSimpleCursor>;
    friend ::djinni::JniInterface<::naomi_gen::SimpleCursor, NativeSimpleCursor>;

};

}  // namespace djinni_generated

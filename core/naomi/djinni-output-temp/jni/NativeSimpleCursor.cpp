// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from chef.djinni

#include "NativeSimpleCursor.hpp"  // my header

namespace djinni_generated {

NativeSimpleCursor::NativeSimpleCursor() : ::djinni::JniInterface<::naomi_gen::SimpleCursor, NativeSimpleCursor>("com/siliconbear/kitchen/SimpleCursor$CppProxy") {}

NativeSimpleCursor::~NativeSimpleCursor() = default;


CJNIEXPORT void JNICALL Java_com_siliconbear_kitchen_SimpleCursor_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<::djinni::CppProxyHandle<::naomi_gen::SimpleCursor>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

}  // namespace djinni_generated
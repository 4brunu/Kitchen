// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from chef.djinni

#include "NativeApi.hpp"  // my header
#include "Marshal.hpp"
#include "NativeApi.hpp"
#include "NativeHandler.hpp"
#include "NativeSandwich.hpp"
#include "NativeService.hpp"

namespace djinni_generated {

NativeApi::NativeApi() : ::djinni::JniInterface<::naomi_gen::Api, NativeApi>("com/siliconbear/kitchen/Api$CppProxy") {}

NativeApi::~NativeApi() = default;


CJNIEXPORT void JNICALL Java_com_siliconbear_kitchen_Api_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<::djinni::CppProxyHandle<::naomi_gen::Api>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jobject JNICALL Java_com_siliconbear_kitchen_Api_00024CppProxy_native_1getApplication(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::naomi_gen::Api>(nativeRef);
        auto r = ref->get_application();
        return ::djinni::release(::djinni_generated::NativeSandwich::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_com_siliconbear_kitchen_Api_getInstance(JNIEnv* jniEnv, jobject /*this*/, jstring j_root, jobject j_handler, jobject j_service)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::naomi_gen::Api::get_instance(::djinni::String::toCpp(jniEnv, j_root),
                                                ::djinni_generated::NativeHandler::toCpp(jniEnv, j_handler),
                                                ::djinni_generated::NativeService::toCpp(jniEnv, j_service));
        return ::djinni::release(::djinni_generated::NativeApi::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

}  // namespace djinni_generated
// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from sandwich.djinni

#include "NativeSandwich.hpp"  // my header
#include "NativeRecipe.hpp"
#include "NativeSandwich.hpp"

namespace djinni_generated {

NativeSandwich::NativeSandwich() : ::djinni::JniInterface<::naomi_gen::Sandwich, NativeSandwich>("com/siliconbear/kitchen/Sandwich$CppProxy") {}

NativeSandwich::~NativeSandwich() = default;


CJNIEXPORT void JNICALL Java_com_siliconbear_kitchen_Sandwich_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<::djinni::CppProxyHandle<::naomi_gen::Sandwich>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jobject JNICALL Java_com_siliconbear_kitchen_Sandwich_00024CppProxy_native_1getRecipe(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::naomi_gen::Sandwich>(nativeRef);
        auto r = ref->get_recipe();
        return ::djinni::release(::djinni_generated::NativeRecipe::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_com_siliconbear_kitchen_Sandwich_getInstance(JNIEnv* jniEnv, jobject /*this*/)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::naomi_gen::Sandwich::get_instance();
        return ::djinni::release(::djinni_generated::NativeSandwich::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

}  // namespace djinni_generated

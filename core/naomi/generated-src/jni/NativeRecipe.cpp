// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from chef.djinni

#include "NativeRecipe.hpp"  // my header
#include "NativeDish.hpp"
#include "NativeModule.hpp"

namespace djinni_generated {

NativeRecipe::NativeRecipe() : ::djinni::JniInterface<::naomi_gen::Recipe, NativeRecipe>("com/siliconbear/kitchen/Recipe$CppProxy") {}

NativeRecipe::~NativeRecipe() = default;


CJNIEXPORT void JNICALL Java_com_siliconbear_kitchen_Recipe_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<::djinni::CppProxyHandle<::naomi_gen::Recipe>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jobject JNICALL Java_com_siliconbear_kitchen_Recipe_00024CppProxy_native_1getDish(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::naomi_gen::Recipe>(nativeRef);
        auto r = ref->get_dish();
        return ::djinni::release(::djinni_generated::NativeDish::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_com_siliconbear_kitchen_Recipe_00024CppProxy_native_1getModule(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::naomi_gen::Recipe>(nativeRef);
        auto r = ref->get_module();
        return ::djinni::release(::djinni_generated::NativeModule::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

}  // namespace djinni_generated

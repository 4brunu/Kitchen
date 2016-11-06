// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from chef.djinni

#include "NativeChef.hpp"  // my header
#include "Marshal.hpp"
#include "NativeDish.hpp"
#include "NativeMenu.hpp"
#include "NativeRecipe.hpp"

namespace djinni_generated {

NativeChef::NativeChef() : ::djinni::JniInterface<::naomi_gen::Chef, NativeChef>("com/siliconbear/kitchen/Chef$CppProxy") {}

NativeChef::~NativeChef() = default;


CJNIEXPORT void JNICALL Java_com_siliconbear_kitchen_Chef_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<::djinni::CppProxyHandle<::naomi_gen::Chef>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jstring JNICALL Java_com_siliconbear_kitchen_Chef_00024CppProxy_native_1getVersion(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::naomi_gen::Chef>(nativeRef);
        auto r = ref->get_version();
        return ::djinni::release(::djinni::String::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_com_siliconbear_kitchen_Chef_00024CppProxy_native_1grab(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jobject j_menu)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::naomi_gen::Chef>(nativeRef);
        auto r = ref->grab(::djinni_generated::NativeMenu::toCpp(jniEnv, j_menu));
        return ::djinni::release(::djinni_generated::NativeDish::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT void JNICALL Java_com_siliconbear_kitchen_Chef_00024CppProxy_native_1addRecipe(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jobject j_recipe)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::naomi_gen::Chef>(nativeRef);
        ref->add_recipe(::djinni_generated::NativeRecipe::toCpp(jniEnv, j_recipe));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

}  // namespace djinni_generated

// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from chef.djinni

#include "NativeHandler.hpp"  // my header
#include "NativeRunnable.hpp"

namespace djinni_generated {

NativeHandler::NativeHandler() : ::djinni::JniInterface<::naomi_gen::Handler, NativeHandler>() {}

NativeHandler::~NativeHandler() = default;

NativeHandler::JavaProxy::JavaProxy(JniType j) : Handle(::djinni::jniGetThreadEnv(), j) { }

NativeHandler::JavaProxy::~JavaProxy() = default;

void NativeHandler::JavaProxy::post(const std::shared_ptr<::naomi_gen::Runnable> & c_runnable) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::djinni_generated::NativeHandler>::get();
    jniEnv->CallVoidMethod(Handle::get().get(), data.method_post,
                           ::djinni::get(::djinni_generated::NativeRunnable::fromCpp(jniEnv, c_runnable)));
    ::djinni::jniExceptionCheck(jniEnv);
}

}  // namespace djinni_generated

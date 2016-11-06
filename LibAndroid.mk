LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE:= libleveldb
LOCAL_SRC_FILES := core/deps/prebuilt/android/$(PLATFORM_TARGET_ARCH)/libleveldb.a
LOCAL_EXPORT_C_INCLUDES := core/deps/include
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE:= libcurl
LOCAL_SRC_FILES := core/deps/prebuilt/android/$(PLATFORM_TARGET_ARCH)/libcurl.a
LOCAL_EXPORT_C_INCLUDES := core/deps/include
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE:= iconv
LOCAL_SRC_FILES := core/deps/prebuilt/android/$(PLATFORM_TARGET_ARCH)/libiconv.a
LOCAL_EXPORT_C_INCLUDES := core/deps/include
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE:= curlcpp
LOCAL_SRC_FILES := core/deps/prebuilt/android/$(PLATFORM_TARGET_ARCH)/libcurlcpp.a
LOCAL_EXPORT_C_INCLUDES := core/deps/include
LOCAL_STATIC_LIBRARIES := libcurl
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE:= yajl
LOCAL_SRC_FILES := core/deps/prebuilt/android/$(PLATFORM_TARGET_ARCH)/libyajl.a
LOCAL_EXPORT_C_INCLUDES := core/deps/include
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE:= restful
LOCAL_SRC_FILES := core/deps/prebuilt/android/$(PLATFORM_TARGET_ARCH)/librestful.a
LOCAL_EXPORT_C_INCLUDES := core/deps/include
LOCAL_STATIC_LIBRARIES := libcurl yajl iconv
include $(PREBUILT_STATIC_LIBRARY)

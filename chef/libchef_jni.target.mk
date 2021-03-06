# This file is generated by gyp; do not edit.

include $(CLEAR_VARS)

LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_MODULE := libchef_jni
LOCAL_MODULE_SUFFIX := .so
LOCAL_MODULE_TARGET_ARCH := $(TARGET_$(GYP_VAR_PREFIX)ARCH)
LOCAL_SDK_VERSION := 19
gyp_intermediate_dir := $(call local-intermediates-dir,,$(GYP_VAR_PREFIX))
gyp_shared_intermediate_dir := $(call intermediates-dir-for,GYP,shared,,,$(GYP_VAR_PREFIX))

# Make sure our deps are built first.
GYP_TARGET_DEPENDENCIES := \
	$(call intermediates-dir-for,STATIC_LIBRARIES,sqlite3,,,$(GYP_VAR_PREFIX))/sqlite3.a \
	$(call intermediates-dir-for,STATIC_LIBRARIES,djinni_jni,,,$(GYP_VAR_PREFIX))/djinni_jni.a

GYP_GENERATED_OUTPUTS :=

# Make sure our deps and generated files are built first.
LOCAL_ADDITIONAL_DEPENDENCIES := $(GYP_TARGET_DEPENDENCIES) $(GYP_GENERATED_OUTPUTS)

LOCAL_GENERATED_SOURCES :=

GYP_COPIED_SOURCE_ORIGIN_DIRS :=

LOCAL_SRC_FILES := \
	chef/handwritten-src/cpp/master-chef/MasterChefApi.cpp \
	chef/handwritten-src/cpp/master-chef/MasterChef.cpp \
	chef/handwritten-src/cpp/master-chef/MasterChefHandler.cpp \
	chef/handwritten-src/cpp/master-chef/MasterChefMenu.cpp \
	chef/handwritten-src/cpp/master-chef/MasterChefService.cpp


# Flags passed to both C and C++ files.
MY_CFLAGS_Debug := \
	-gdwarf-2 \
	-Werror \
	-Wall \
	-Wextra \
	-Wno-missing-field-initializers \
	-g \
	-O0 \
	-DDEBUG=1

MY_DEFS_Debug := \
	'-DDEBUG=1'


# Include paths placed before CFLAGS/CPPFLAGS
LOCAL_C_INCLUDES_Debug := \
	$(LOCAL_PATH)/core/deps/include \
	$(LOCAL_PATH)/core/naomi/generated-src/jni \
	$(LOCAL_PATH)/core/naomi/generated-src/cpp \
	$(LOCAL_PATH)/chef/handwritten-src/jni \
	$(LOCAL_PATH)/chef/handwritten-src/cpp \
	$(LOCAL_PATH)/chef/handwritten-src/cpp/oak \
	$(LOCAL_PATH)/core/deps \
	$(LOCAL_PATH)/core/deps/sqlite3 \
	$(LOCAL_PATH)/core/support-lib/jni


# Flags passed to only C++ (and not C) files.
LOCAL_CPPFLAGS_Debug := \
	-std=c++11 \
	-frtti \
	-fexceptions \
	-Wno-literal-suffix


# Flags passed to both C and C++ files.
MY_CFLAGS_Release := \
	-gdwarf-2 \
	-Werror \
	-Wall \
	-Wextra \
	-Wno-missing-field-initializers \
	-Os \
	-fomit-frame-pointer \
	-fdata-sections \
	-ffunction-sections \
	-DNDEBUG=1

MY_DEFS_Release := \
	'-DNDEBUG=1'


# Include paths placed before CFLAGS/CPPFLAGS
LOCAL_C_INCLUDES_Release := \
	$(LOCAL_PATH)/core/deps/include \
	$(LOCAL_PATH)/core/naomi/generated-src/jni \
	$(LOCAL_PATH)/core/naomi/generated-src/cpp \
	$(LOCAL_PATH)/chef/handwritten-src/jni \
	$(LOCAL_PATH)/chef/handwritten-src/cpp \
	$(LOCAL_PATH)/chef/handwritten-src/cpp/oak \
	$(LOCAL_PATH)/core/deps \
	$(LOCAL_PATH)/core/deps/sqlite3 \
	$(LOCAL_PATH)/core/support-lib/jni


# Flags passed to only C++ (and not C) files.
LOCAL_CPPFLAGS_Release := \
	-std=c++11 \
	-frtti \
	-fexceptions \
	-Wno-literal-suffix


LOCAL_CFLAGS := $(MY_CFLAGS_$(GYP_CONFIGURATION)) $(MY_DEFS_$(GYP_CONFIGURATION))
LOCAL_C_INCLUDES := $(GYP_COPIED_SOURCE_ORIGIN_DIRS) $(LOCAL_C_INCLUDES_$(GYP_CONFIGURATION))
LOCAL_CPPFLAGS := $(LOCAL_CPPFLAGS_$(GYP_CONFIGURATION))
LOCAL_ASFLAGS := $(LOCAL_CFLAGS)
### Rules for final target.

LOCAL_LDFLAGS_Debug := \
	-llog \
	-lz \
	-latomic \
	-Wl,--build-id,--gc-sections,--exclude-libs,ALL


LOCAL_LDFLAGS_Release := \
	-llog \
	-lz \
	-latomic \
	-Wl,--build-id,--gc-sections,--exclude-libs,ALL

LOCAL_GYP_LIBS :=

LOCAL_LDFLAGS := $(LOCAL_LDFLAGS_$(GYP_CONFIGURATION)) $(LOCAL_GYP_LIBS)

LOCAL_STATIC_LIBRARIES := \
	libcurl \
	librestful \
	libiconv \
	libyajl \
	libcurlcpp \
	libleveldb \
	sqlite3 \
	djinni_jni

# Enable grouping to fix circular references
LOCAL_GROUP_STATIC_LIBRARIES := true
# Add target alias to "gyp_all_modules" target.
.PHONY: gyp_all_modules
gyp_all_modules: libchef_jni

LOCAL_PRELINK_MODULE := false
include $(BUILD_SHARED_LIBRARY)

{
    "targets": [
        {
            "target_name": "lib{PROJECT_NAME}_jni",
            "type": "shared_library",
            "dependencies": [
              "../deps/sqlite3.gyp:sqlite3",
              "../support-lib/support_lib.gyp:djinni_jni",
	      {ANDROID_DEPENDENCIES}
            ],
	    "libraries": ["libcurl.a", "librestful.a", "libiconv.a", "libyajl.a", "libcurlcpp.a",],
            "ldflags": [ "-llog", "-lz", "-Wl,--build-id,--gc-sections,--exclude-libs,ALL" ],
            "sources": [
              "../support-lib/jni/djinni_main.cpp",
              "<!@(python glob.py generated-src/jni   '*.cpp')",
	      "<!@(python glob.py handwritten-src/cpp '*.cpp')",
            ],
            "include_dirs": [
              "../deps/include",
              "generated-src/jni",
              "generated-src/cpp",
	      "handwritten-src/jni",
              "handwritten-src/cpp",
            ],
        },
        {
            "target_name": "lib{PROJECT_NAME}_objc",
            "type": 'static_library',
            "dependencies": [
              "../deps/sqlite3.gyp:sqlite3",
              "../support-lib/support_lib.gyp:djinni_objc",
	      {OBJC_DEPENDENCIES}
            ],
            "sources": [
              "<!@(python glob.py generated-src/objc   '*.cpp' '*.mm' '*.m')",
	      "<!@(python glob.py handwritten-src/cpp '*.cpp')",
            ],
            "include_dirs": [
              "../deps/include",
              "generated-src/objc",
              "generated-src/cpp",
	      "handwritten-src/objc",
              "handwritten-src/cpp",
            ],
        },
    ],
}

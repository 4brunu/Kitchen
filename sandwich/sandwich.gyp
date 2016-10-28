{
    "targets": [
        {
            "target_name": "libsandwich_jni",
            "type": "shared_library",
            "dependencies": [
	      "../core/naomi/../deps/sqlite3.gyp:sqlite3",
              "../core/naomi/../support-lib/support_lib.gyp:djinni_jni",
              "../chef/chef.gyp:libchef_jni",
            ],
	    "libraries": ["libcurl.a", "librestful.a", "libiconv.a", "libyajl.a", "libcurlcpp.a"],
            "ldflags": [ "-llog", "-lz", "-latomic", "-Wl,--build-id,--gc-sections,--exclude-libs,ALL" ],
            "sources": [
		"<!@(python ../core/naomi/glob.py handwritten-src/cpp '*.cpp')",
            ],
            "include_dirs": [
	      "../core/deps/include",
              "../core/naomi/generated-src/jni",
              "../core/naomi/generated-src/cpp",
              "../chef/handwritten-src/cpp/master-chef/include",
	      "handwritten-src/jni",
              "handwritten-src/cpp",
              "handwritten-src/cpp/oak",
            ],
        },
        {
            "target_name": "libsandwich_objc",
            "type": 'static_library',
            "dependencies": [
              "../core/support-lib/support_lib.gyp:djinni_objc",
            ],
            "sources": [
		"<!@(python ../core/naomi/glob.py handwritten-src/cpp '*.cpp')",
            ],
            "include_dirs": [
	      "../core/deps/include",
              "../core/naomi/generated-src/objc",
              "../core/naomi/generated-src/cpp",
	      "handwritten-src/jni",
              "handwritten-src/cpp",
              "handwritten-src/cpp/oak",
            ],
        },
    ],
}

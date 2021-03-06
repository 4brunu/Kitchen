# rule to lazily clone gyp
./deps/gyp:
	git clone --depth 1 https://chromium.googlesource.com/external/gyp.git ./deps/gyp

clean:
	rm -rf ../GypAndroid.mk
	rm -rf {PROJECT_NAME}/djinni-output-temp
	rm -rf {PROJECT_NAME}/generated-src
	rm -rf {PROJECT_NAME}/lib{PROJECT_NAME}_jni.target.mk
	rm -rf ../{PROJECT_ROOT}/app/obj
	@echo "{PROJECT_NAME} cleaned up..."

# we specify a root target for android to prevent all of the targets from spidering out
GypAndroid.mk: ./deps/gyp {PROJECT_NAME}/lib{PROJECT_NAME}.gyp support-lib/support_lib.gyp {PROJECT_NAME}/{PROJECT_NAME}.djinni
	./{PROJECT_NAME}/run_djinni.sh
	ANDROID_BUILD_TOP=dirname $(which ndk-build) deps/gyp/gyp --depth=../ -f "extension/android.py" -DOS=android -I common.gypi {PROJECT_NAME}/lib{PROJECT_NAME}.gyp --root-target=lib{PROJECT_NAME}_jni

# this target implicitly depends on GypAndroid.mk since gradle will try to make it
android: clean GypAndroid.mk
	cd ../android && ./gradlew {PROJECT_MODULE}:assembleDebug && cd ../core
	@echo "Apks produced at:"
	@python {PROJECT_NAME}/glob.py {PROJECT_NAME}/ '*.apk'

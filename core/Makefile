# rule to lazily clone gyp
./deps/gyp:
	git clone --depth 1 https://chromium.googlesource.com/external/gyp.git ./deps/gyp

clean:
	rm -rf ../GypAndroid.mk
	rm -rf naomi/djinni-output-temp
	rm -rf naomi/generated-src
	rm -rf naomi/libnaomi_jni.target.mk
	rm -rf ../app/app/obj
	@echo "naomi cleaned up..."

# we specify a root target for android to prevent all of the targets from spidering out
GypAndroid.mk: ./deps/gyp naomi/libnaomi.gyp support-lib/support_lib.gyp naomi/naomi.djinni
	./naomi/run_djinni.sh
	ANDROID_BUILD_TOP=dirname $(which ndk-build) deps/gyp/gyp --depth=../ -f "extension/android.py" -DOS=android -I common.gypi naomi/libnaomi.gyp --root-target=libnaomi_jni

# this target implicitly depends on GypAndroid.mk since gradle will try to make it
android: clean GypAndroid.mk
	cd ../android && ./gradlew app:assembleDebug && cd ../core
	@echo "Apks produced at:"
	@python naomi/glob.py naomi/ '*.apk'

// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from chef.djinni

package com.siliconbear.kitchen;

import java.util.concurrent.atomic.AtomicBoolean;

public abstract class Api {
    public abstract Chef getChef();

    public static native Api getInstance(String root, Handler handler, Service service);

    private static final class CppProxy extends Api
    {
        private final long nativeRef;
        private final AtomicBoolean destroyed = new AtomicBoolean(false);

        private CppProxy(long nativeRef)
        {
            if (nativeRef == 0) throw new RuntimeException("nativeRef is zero");
            this.nativeRef = nativeRef;
        }

        private native void nativeDestroy(long nativeRef);
        public void destroy()
        {
            boolean destroyed = this.destroyed.getAndSet(true);
            if (!destroyed) nativeDestroy(this.nativeRef);
        }
        protected void finalize() throws java.lang.Throwable
        {
            destroy();
            super.finalize();
        }

        @Override
        public Chef getChef()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getChef(this.nativeRef);
        }
        private native Chef native_getChef(long _nativeRef);
    }
}

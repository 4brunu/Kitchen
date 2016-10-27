// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from chef.djinni

package com.siliconbear.kitchen;

import java.util.concurrent.atomic.AtomicBoolean;

public abstract class Dish {
    public abstract void serve(Intention intent, Response callback);

    private static final class CppProxy extends Dish
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
        public void serve(Intention intent, Response callback)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_serve(this.nativeRef, intent, callback);
        }
        private native void native_serve(long _nativeRef, Intention intent, Response callback);
    }
}

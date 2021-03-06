// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from chef.djinni

package com.siliconbear.kitchen;

import java.util.concurrent.atomic.AtomicBoolean;

public abstract class Recipe {
    public abstract Dish getDish();

    public abstract Menu getMenu();

    private static final class CppProxy extends Recipe
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
        public Dish getDish()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getDish(this.nativeRef);
        }
        private native Dish native_getDish(long _nativeRef);

        @Override
        public Menu getMenu()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getMenu(this.nativeRef);
        }
        private native Menu native_getMenu(long _nativeRef);
    }
}

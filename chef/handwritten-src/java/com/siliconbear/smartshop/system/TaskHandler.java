package com.siliconbear.smartshop.system;

import android.os.Looper;

import com.siliconbear.kitchen.Handler;


/**
 * Created by izehi on 10/22/16.
 */
public class TaskHandler extends Handler implements java.lang.Runnable {

    private com.siliconbear.kitchen.Runnable mRunnable;
    private android.os.Handler mHandler;

    public TaskHandler() {
        mHandler = new android.os.Handler(Looper.getMainLooper());
    }

    @Override
    public void post(com.siliconbear.kitchen.Runnable runnable) {
        mRunnable = runnable;
        mHandler.post(this);
    }

    @Override
    public void run() {
        mRunnable.run();
    }
}

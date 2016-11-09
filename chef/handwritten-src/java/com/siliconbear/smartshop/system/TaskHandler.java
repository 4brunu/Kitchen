package com.siliconbear.smartshop.system;

import android.os.Looper;

import com.siliconbear.kitchen.Handler;


/**
 * Created by izehi on 10/22/16.
 */
public class TaskHandler extends Handler {

    private android.os.Handler mHandler;

    public TaskHandler() {
        mHandler = new android.os.Handler(Looper.getMainLooper());
    }

    @Override
    public void post(final com.siliconbear.kitchen.Runnable runnable) {
        mHandler.post(new Runnable() {
            @Override
            public void run() {
                runnable.run();
            }
        });
    }
}

package com.siliconbear.smartshop.system;

import com.siliconbear.kitchen.Runnable;
import com.siliconbear.kitchen.Service;

/**
 * Created by izehi on 10/22/16.
 */
public class ApplicationService extends Service implements java.lang.Runnable {

    private Thread mThread;
    private Runnable mRunnable;

    @Override
    public void onCreate() {

    }

    @Override
    public void onStart(String name, Runnable runnable) {
        mRunnable = runnable;
        mThread = new Thread(this);
        if (name != null) {
            mThread.setName(name);
        }
        mThread.setDaemon(true);
        mThread.start();
    }

    @Override
    public void run() {
        mRunnable.run();
    }
}

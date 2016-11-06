package com.siliconbear.smartshop.app;

import com.siliconbear.kitchen.Api;
import com.siliconbear.smartshop.system.ApplicationService;
import com.siliconbear.smartshop.system.TaskHandler;

/**
 * Created by izehi on 10/22/16.
 */
public class DjinniKitchen {

    static {
        System.loadLibrary("naomi_jni");
    }

    private String mRoot;

    private Api mApplication;
    private TaskHandler mTaskHandler;
    private ApplicationService mService;

    public DjinniKitchen(String root) {
        mRoot = root;
        mTaskHandler = new TaskHandler();

        mService = new ApplicationService();
        mApplication = Api.getInstance(mRoot, mTaskHandler, mService);
    }

    public Api initialize() {
        return mApplication;
    }
}




package com.siliconbear.android;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.webkit.WebView;

import com.siliconbear.kitchen.Intention;
import com.siliconbear.kitchen.Module;
import com.siliconbear.kitchen.Response;
import com.siliconbear.kitchen.Sandwich;
import com.siliconbear.smartshop.app.SmartShopper;

public class MainActivity extends AppCompatActivity {

    private Sandwich mSandwich;
    private SmartShopper mShopper;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        final WebView webview = (WebView) findViewById(R.id.webView1);

                mShopper = new SmartShopper("");
        mSandwich = mShopper.create().getApplication();
        mSandwich.grab(Module.CATALOG)
                .serve(Intention.STORE_LIST, new Response() {
                    @Override
                    public void onLoad(String message) {
                        webview.getSettings().setJavaScriptEnabled(true);
                        webview.loadDataWithBaseURL("", message, "text/html", "UTF-8", "");
                    }
                });
    }
}

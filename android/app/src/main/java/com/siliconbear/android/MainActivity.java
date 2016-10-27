package com.siliconbear.android;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.webkit.WebView;

import com.siliconbear.kitchen.Chef;
import com.siliconbear.kitchen.Intention;
import com.siliconbear.kitchen.Module;
import com.siliconbear.kitchen.Response;
import com.siliconbear.smartshop.app.DjinniKitchen;

public class MainActivity extends AppCompatActivity {

    private Chef mChef;
    private DjinniKitchen mKitchen;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        final WebView webview = (WebView) findViewById(R.id.webView1);

        mKitchen = new DjinniKitchen("");
        mChef = mKitchen.initialize().getChef();
        mChef.grab(Module.CATALOG)
                .serve(Intention.STORE_LIST, new Response() {
                    @Override
                    public void onLoad(String message) {
                        webview.getSettings().setJavaScriptEnabled(true);
                        webview.loadDataWithBaseURL("", message, "text/html", "UTF-8", "");
                    }
                });
    }
}

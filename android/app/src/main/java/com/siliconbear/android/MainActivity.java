package com.siliconbear.android;

import android.os.Environment;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.webkit.WebView;

import com.siliconbear.kitchen.Chef;
import com.siliconbear.kitchen.LoadType;
import com.siliconbear.kitchen.Menu;
import com.siliconbear.kitchen.Sandwich;
import com.siliconbear.kitchen.ServiceBinder;
import com.siliconbear.kitchen.SimpleCursor;
import com.siliconbear.smartshop.app.DjinniKitchen;

import java.io.File;
import java.util.HashMap;

public class MainActivity extends AppCompatActivity {

    private Chef mChef;
    private DjinniKitchen mKitchen;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        final WebView webview = (WebView) findViewById(R.id.webView1);

        String name = Environment.getDataDirectory() + "/data/" + getPackageName();
        File folder = new File(name);

        if (!folder.exists()) {
            folder.mkdir();
        }

        mKitchen = new DjinniKitchen(name);
        mChef = mKitchen.initialize().getChef();
        mChef.addRecipe(Sandwich.getInstance().getRecipe());

        HashMap<String, String> s = new HashMap<>();
        s.put("data", "{\"product_id\": \"76684\", \"width\": 300, \"height\": 300, \"limit\": 2}");

        mChef.grab(Menu.OPEN_BEETROOT_SANDWICH)

                .serve(com.siliconbear.kitchen.Package.STORE_LIST, s, new ServiceBinder() {
                    @Override
                    public LoadType loadType() {
                        return LoadType.LAZY;
                    }

                    @Override
                    public void onError(String message) {
                        webview.loadDataWithBaseURL("", message, "text/html", "UTF-8", "");
                    }

                    @Override
                    public void onLoad(String message, boolean cache, SimpleCursor cursor) {
                        webview.getSettings().setJavaScriptEnabled(true);
                        webview.loadDataWithBaseURL("", "message: " + message + " data: " + cursor.toJsonString(), "text/html", "UTF-8", "");
                    }
                });
    }
}

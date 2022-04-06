package com.example.cppexample;

import androidx.appcompat.app.AppCompatActivity;

import android.content.res.AssetManager;
//import android.os.Bundle;
//import android.view.View;
//import android.widget.Button;
//import android.widget.EditText;
//import android.widget.TextView;
//
//import com.example.cppexample.databinding.ActivityMainBinding;

public class CppActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

//    private ActivityMainBinding binding;
//
//    private TextView mTextView;
//    private EditText mEditText;
//    private Button mButton;
//
//    @Override
//    protected void onCreate(Bundle savedInstanceState) {
//        super.onCreate(savedInstanceState);
//
////        binding = ActivityMainBinding.inflate(getLayoutInflater());
////        setContentView(binding.getRoot());
//
//        setContentView(R.layout.activity_main);
//        mTextView =findViewById(R.id.sample_text);
//        mEditText = findViewById(R.id.editTextNumber);
//        mButton = findViewById(R.id.button);
//        setNativeAssetManager(getAssets());
//
//        // Example of a call to a native method
////        TextView tv = binding.sampleText;
////
////        String temp = "775423655217723322774542556434664313111616";
////
////
////        tv.setText(mystringFromJNI(temp));
//    }
//
//    public void calculate(View view) {
//        String message = mEditText.getText().toString();
//        mTextView.setText(mystringFromJNI(message));
//    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();

    public native String mystringFromJNI(String boardState);
    public native void setNativeAssetManager(AssetManager assetManager);
}
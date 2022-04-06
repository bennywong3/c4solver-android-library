package com.example.librarytest;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import com.example.cppexample.CppActivity;

public class MainActivity extends AppCompatActivity {
    private CppActivity mCppActivity = new CppActivity();
    private TextView mTextView;

    private EditText mEditText;
    private Button mButton;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mCppActivity.setNativeAssetManager(getAssets());
        mTextView = findViewById(R.id.temp);
        mEditText = findViewById(R.id.editTextNumber);
        mButton = findViewById(R.id.button);
//        String temp = "4453";
//        //mTextView.setText(temp);
//        mTextView.setText(mCppActivity.mystringFromJNI(temp));
    }

    public void calculate(View view) {
        String message = mEditText.getText().toString();
        mTextView.setText(mCppActivity.mystringFromJNI(message));
    }
}
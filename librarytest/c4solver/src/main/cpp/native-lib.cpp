#include <jni.h>
#include <string>
#include "Interface.hpp"
#include "Solver.hpp"
#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_cppexample_CppActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}


extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_cppexample_CppActivity_mystringFromJNI(JNIEnv *env, jobject thiz,
                                                        jstring jStr) {
    // TODO: implement mystringFromJNI()
    const jclass stringClass = env->GetObjectClass(jStr);
    const jmethodID getBytes = env->GetMethodID(stringClass, "getBytes", "(Ljava/lang/String;)[B");
    const jbyteArray stringJbytes = (jbyteArray) env->CallObjectMethod(jStr, getBytes, env->NewStringUTF("UTF-8"));
    size_t length = (size_t) env->GetArrayLength(stringJbytes);
    jbyte* pBytes = env->GetByteArrayElements(stringJbytes, NULL);

    std::string ret = std::string((char *)pBytes, length);
    env->ReleaseByteArrayElements(stringJbytes, pBytes, JNI_ABORT);

    env->DeleteLocalRef(stringJbytes);
    env->DeleteLocalRef(stringClass);



    std::string hello = demo(ret);

    return env->NewStringUTF(hello.c_str());
}

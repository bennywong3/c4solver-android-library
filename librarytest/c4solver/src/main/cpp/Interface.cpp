#include "Solver.hpp"
#include "Position.hpp"
#include <android/log.h>
#include <jni.h>
#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>


using namespace GameSolver::Connect4;


std::string demo(std::string line) //return type- address of integer array
{
    Solver solver;
    Position P;
    std::string opening_book = "7x6.book";
    __android_log_print(ANDROID_LOG_VERBOSE, "interface.cpp", "before loadbook");
    solver.loadBook(opening_book);

//    static int a[7]; //array declared as static
    std::string output = "";
    if(P.play(line) == line.size()) {
        //int score = solver.solve(P);
        std::vector<int> scores = solver.analyze(P, false);
        for(int i = 0; i< Position::WIDTH; i++)
        {
//            a[i] = scores[i]; //array initialisation
            output += std::to_string(scores[i]);
            output += ',';
        }
    } else {
        for(int i = 0; i<7; i++)
        {
//            a[i] = i; //array initialisation
            output += std::to_string(i);
        }
    }

    return output; //address of a returned
}

AAssetManager *nativeasset;
AAsset *assetFile;

extern "C"
JNIEXPORT void JNICALL
Java_com_example_cppexample_CppActivity_setNativeAssetManager(JNIEnv *env, jobject thiz,
                                                              jobject asset_manager) {
    // TODO: implement setNativeAssetManager()
    nativeasset = AAssetManager_fromJava(env, asset_manager);
}

//int readCount = 0;

void openasset(){
    assetFile = AAssetManager_open(nativeasset, "7x6.jpg", AASSET_MODE_BUFFER);
    //get file length
    size_t fileLength = AAsset_getLength(assetFile);
    __android_log_print(ANDROID_LOG_VERBOSE, "openasset", "fileLength: %d", fileLength);
}

void readasset(char *__s, size_t __n){
//    AAsset *assetFile = AAssetManager_open(nativeasset, "7x6.jpg", AASSET_MODE_BUFFER);
//    //get file length
//    size_t fileLength = AAsset_getLength(assetFile);


    AAsset_read(assetFile, __s, __n);
    AAsset_seek(assetFile, 0, SEEK_CUR);
//    readCount++;
//    __android_log_print(ANDROID_LOG_VERBOSE, "readasset", "count: %d", readCount);
//    if (readCount == 8){
//        AAsset_close(assetFile);
//        __android_log_print(ANDROID_LOG_VERBOSE, "readasset", "closed");
//        readCount = 0;
//        __android_log_print(ANDROID_LOG_VERBOSE, "readasset", "count: %d", readCount);
//    }
}

void closeasset(){
    AAsset_close(assetFile);
    __android_log_print(ANDROID_LOG_VERBOSE, "readasset", "closed");
}
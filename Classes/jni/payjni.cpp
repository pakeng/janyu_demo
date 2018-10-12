#include "payjni.hpp"
#include "PayManager.hpp"
/*
 * Class:     org_cocos2dx_cpp_AppActivity
 * Method:    pay_result
 * Signature: (ZLjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_org_cocos2dx_cpp_AppActivity_pay_1result(JNIEnv* env, jobject obj, jboolean result, jstring msg)
{
    PayManager::getInstance()->pay_result(result, jstring2str(env, msg));
    CCLOG("pay_result");
}

/*
 * Class:     org_cocos2dx_cpp_AppActivity
 * Method:    init_result
 * Signature: (ZLjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_org_cocos2dx_cpp_AppActivity_init_1result(JNIEnv* env, jobject obj, jboolean result, jstring msg)
{
    PayManager::getInstance()->init_result(true, jstring2str(env, msg));
    CCLOG("init_result == %s", jstring2str(env, msg).c_str());
}

std::string jstring2str(JNIEnv* env, jstring jstr)
{
    char*   rtn   =   NULL;
    jclass   clsstring   =   env->FindClass("java/lang/String");
    jstring   strencode   =   env->NewStringUTF("UTF8");
    jmethodID   mid   =   env->GetMethodID(clsstring,   "getBytes",  "(Ljava/lang/String;)[B");
    jbyteArray   barr=   (jbyteArray)env->CallObjectMethod(jstr,mid,strencode);
    jsize   alen   =   env->GetArrayLength(barr);
    jbyte*   ba   =   env->GetByteArrayElements(barr,JNI_FALSE);
    if(alen   >   0)
    {
        rtn   =   (char*)malloc(alen+1);
        memcpy(rtn,ba,alen);
        rtn[alen]=0;
    }
    env->ReleaseByteArrayElements(barr,ba,0);
    std::string stemp(rtn);
    free(rtn);
    return   stemp;
}


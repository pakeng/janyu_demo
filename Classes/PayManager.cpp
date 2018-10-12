//
// Created by Vito_d on 2018/10/12.
//

#include "PayManager.hpp"
#include <jni.h>
#include "jni/JniHelper.h"

#define PACKAGE_NAME "org/cocos2dx/cpp/AppActivity"

static PayManager* _instance;

PayManager* PayManager::getInstance()
{
    if (!_instance){
        _instance = new PayManager();
    }
    return _instance;
}

void PayManager::pay_result(bool result, std::string msg)
{
    if (_currentLayer){
        _currentLayer->pay_callback(result, msg);
    }
}

void PayManager::pay(std::string payid, std::string pay_price)
{
    JniMethodInfo methodInfo;
    if (JniHelper::getStaticMethodInfo(methodInfo, PACKAGE_NAME, "pay", "(Ljava/lang/String;Ljava/lang/String;)V"))
    {
        jstring pid = methodInfo.env->NewStringUTF(payid.c_str());
        jstring price = methodInfo.env->NewStringUTF(pay_price.c_str());
        methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID,pid, price);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
        methodInfo.env->DeleteLocalRef(price);
        methodInfo.env->DeleteLocalRef(pid);
    }
}

void PayManager::init_sdk(std::string appid, std::string channel)
{
    JniMethodInfo methodInfo;
    if (JniHelper::getStaticMethodInfo(methodInfo, PACKAGE_NAME, "init_sdk", "(Ljava/lang/String;Ljava/lang/String;)V"))
    {
        jstring j_appid = methodInfo.env->NewStringUTF(appid.c_str());
        jstring j_channel = methodInfo.env->NewStringUTF(channel.c_str());
        methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, j_appid, j_channel);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
        methodInfo.env->DeleteLocalRef(j_appid);
        methodInfo.env->DeleteLocalRef(j_channel);
    }
}

void PayManager::init_result(bool result, std::string msg) {
    if (_currentLayer){
        _currentLayer->init_callback(result, msg);
    }
}

void PayManager::setLayer(Callback* layer) {
    _currentLayer = layer;
}

PayManager::PayManager():
        _currentLayer(nullptr)
{

}

PayManager::~PayManager()
{

}

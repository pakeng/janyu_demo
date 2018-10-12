//
// Created by Vito_d on 2018/10/12.
//

#ifndef PROJ_ANDROID_PAYMANAGER_H
#define PROJ_ANDROID_PAYMANAGER_H
#include "cocos2d.h"
#include <string>
#include "Callback.h"
USING_NS_CC;

class PayManager {
public:
    static PayManager* getInstance();
    void pay_result(bool result, std::string msg);
    void pay(std::string payid, std::string pay_price);
    void init_sdk(std::string appid, std::string channel);
    void init_result(bool result, std::string msg);
    void setLayer(Callback* layer);
private:
    Callback* _currentLayer;
    PayManager();
    ~PayManager();
};


#endif //PROJ_ANDROID_PAYMANAGER_H

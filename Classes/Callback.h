//
// Created by Vito_d on 2018/10/12.
//

#ifndef PROJ_ANDROID_CALLBACK_H
#define PROJ_ANDROID_CALLBACK_H

#include <string>

class Callback {
public:
    virtual void pay_callback(bool result, std::string msg) = 0;
    virtual void init_callback(bool result, std::string msg) = 0;
};


#endif //PROJ_ANDROID_CALLBACK_H

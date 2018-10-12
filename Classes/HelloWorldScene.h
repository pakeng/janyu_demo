#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "Callback.h"

class HelloWorld : public cocos2d::Layer, public Callback, public cocos2d::ui::EditBoxDelegate
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    virtual void pay_callback(bool result, std::string msg);
    virtual void init_callback(bool result, std::string msg);
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
    HelloWorld();
    ~HelloWorld();
private:
    Node* _rootNode;
    cocos2d::ui::EditBox* _appid_input_box;
    cocos2d::ui::EditBox* _channel_input_box;
    cocos2d::ui::EditBox* _price_input_box;
    cocos2d::ui::EditBox* _pay_id_input_box;
    cocos2d::ui::Text* _result_text;
    cocos2d::ui::Button* _pay_btn;
    void init_view();
    void init_action();
    virtual void editBoxReturn(cocos2d::ui::EditBox* editBox);
    std::string _appid;
    std::string _channel;
    std::string _payid;
    std::string _price;
    bool _isInited;
};

#endif // __HELLOWORLD_SCENE_H__

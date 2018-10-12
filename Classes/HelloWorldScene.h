#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

class HelloWorld : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
private:
    Node* _rootNode;
    cocos2d::ui::TextField* _appid_input_box;
    cocos2d::ui::TextField* _channel_input_box;
    cocos2d::ui::TextField* _price_input_box;
    cocos2d::ui::TextField* _pay_id_input_box;
    
    cocos2d::ui::Button* _pay_btn;
    void init_view();
    void init_action();
    
};

#endif // __HELLOWORLD_SCENE_H__

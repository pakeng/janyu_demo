#include "HelloWorldScene.h"


USING_NS_CC;

using namespace cocostudio::timeline;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    _rootNode = CSLoader::createNode("MainScene.csb");
    init_view();
    init_action();
    addChild(_rootNode);

    return true;
}

void HelloWorld::init_action()
{
    _pay_btn->addClickEventListener([&](Ref* pSender){
        CCLOG("Call back");
    });
}

void HelloWorld::init_view()
{
    auto main_layer = _rootNode->getChildByName("main_layer");
    auto root_panel = main_layer->getChildByName("Panel_1");
    _pay_btn = (cocos2d::ui::Button*)root_panel->getChildByName("Button_Pay");
    auto pay_panel = root_panel->getChildByName("pay_panel");
    // APPID node
    auto appid_node = pay_panel->getChildByName("appid_node");
    auto title = (cocos2d::ui::Text*)appid_node->getChildByName("name");
    _appid_input_box = (cocos2d::ui::TextField*)appid_node->getChildByName("input_bg")->getChildByName("input_box");
    title->setString("APPID:");
    title->setFontSize(24);
    // channel node
    auto channel_node = pay_panel->getChildByName("channel_node");
    _channel_input_box = (cocos2d::ui::TextField*)channel_node->getChildByName("input_bg")->getChildByName("input_box");
    title = (cocos2d::ui::Text*)channel_node->getChildByName("name");
    title->setString("Channel:");
    title->setFontSize(24);
    // pay id node
    auto pay_id_node = pay_panel->getChildByName("payid_node");
    _pay_id_input_box = (cocos2d::ui::TextField*)pay_id_node->getChildByName("input_bg")->getChildByName("input_box");
    title = (cocos2d::ui::Text*)pay_id_node->getChildByName("name");
    title->setString("Pay id:");
    title->setFontSize(24);
    
    // price node
    auto price_node = pay_panel->getChildByName("price_node");
    _price_input_box = (cocos2d::ui::TextField*)price_node->getChildByName("input_bg")->getChildByName("input_box");
    title = (cocos2d::ui::Text*)price_node->getChildByName("name");
    title->setString("Price:");
    title->setFontSize(24);
}

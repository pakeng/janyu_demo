#include "HelloWorldScene.h"
#include "PayManager.hpp"

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
    // set callback
    PayManager::getInstance()->setLayer(this);
    return true;
}

void HelloWorld::init_action()
{
    _pay_btn->addClickEventListener([&](Ref* pSender){
        if (_isInited){
            PayManager::getInstance()->pay(_pay_id_input_box->getText(), _price_input_box->getText());
        } else{
            PayManager::getInstance()->init_sdk(_appid_input_box->getText(), _channel_input_box->getText());
        }
        CCLOG("Call back");
    });
}

void HelloWorld::init_view()
{
    auto main_layer = _rootNode->getChildByName("main_layer");
    auto root_panel = main_layer->getChildByName("Panel_1");
    _pay_btn = (cocos2d::ui::Button*)root_panel->getChildByName("Button_Pay");
    _pay_btn->setTitleText("Init SDK");
    _result_text = (cocos2d::ui::Text*)(root_panel->getChildByName("Image_4")->getChildByName("result"));
    auto pay_panel = root_panel->getChildByName("pay_panel");
    // APPID node
    auto appid_node = pay_panel->getChildByName("appid_node");
    auto title = (cocos2d::ui::Text*)appid_node->getChildByName("name");
    auto temp = (cocos2d::ui::TextField*)appid_node->getChildByName("input_bg");
    SpriteFrame * frame = SpriteFrame::create("res/input_box_bg.png", Rect(0, 0, 10, 10));
    Size input_size = temp->getChildByName("input_box")->getContentSize();
    Vec2 input_position = temp->getChildByName("input_box")->getPosition();
    Vec2 input_anchorpoint = temp->getChildByName("input_box")->getAnchorPoint();
    temp->getChildByName("input_box")->removeFromParent();
    _appid_input_box =cocos2d::ui::EditBox::create(input_size,
                                                    cocos2d::ui::Scale9Sprite::createWithSpriteFrame(frame));
    _appid_input_box->setPosition(input_position);
    _appid_input_box->setAnchorPoint(input_anchorpoint);
    _appid_input_box->setInputMode(cocos2d::ui::EditBox::InputMode::SINGLE_LINE);
    _appid_input_box->setDelegate(this);
    _appid_input_box->setTag(1001);
    temp->addChild(_appid_input_box);

    title->setString("APPID:");
    title->setFontSize(24);
    // channel node
    auto channel_node = pay_panel->getChildByName("channel_node");
    temp = (cocos2d::ui::TextField*)channel_node->getChildByName("input_bg");
    input_size = temp->getChildByName("input_box")->getContentSize();
    input_position = temp->getChildByName("input_box")->getPosition();
    input_anchorpoint = temp->getChildByName("input_box")->getAnchorPoint();
    temp->getChildByName("input_box")->removeFromParent();
    _channel_input_box =cocos2d::ui::EditBox::create(input_size,
                                                   cocos2d::ui::Scale9Sprite::createWithSpriteFrame(frame));
    _channel_input_box->setPosition(input_position);
    _channel_input_box->setAnchorPoint(input_anchorpoint);
    _channel_input_box->setInputMode(cocos2d::ui::EditBox::InputMode::SINGLE_LINE);
    _channel_input_box->setDelegate(this);
    _channel_input_box->setTag(1002);
    temp->addChild(_channel_input_box);

    title = (cocos2d::ui::Text*)channel_node->getChildByName("name");
    title->setString("Channel:");
    title->setFontSize(24);
    // pay id node
    auto pay_id_node = pay_panel->getChildByName("payid_node");
    temp = (cocos2d::ui::TextField*)pay_id_node->getChildByName("input_bg");
    input_size = temp->getChildByName("input_box")->getContentSize();
    input_position = temp->getChildByName("input_box")->getPosition();
    input_anchorpoint = temp->getChildByName("input_box")->getAnchorPoint();
    temp->getChildByName("input_box")->removeFromParent();

    _pay_id_input_box =cocos2d::ui::EditBox::create(input_size,
                                                    cocos2d::ui::Scale9Sprite::createWithSpriteFrame(frame));
    _pay_id_input_box->setPosition(input_position);
    _pay_id_input_box->setAnchorPoint(input_anchorpoint);
    _pay_id_input_box->setInputMode(cocos2d::ui::EditBox::InputMode::DECIMAL);
    _pay_id_input_box->setDelegate(this);
    _pay_id_input_box->setTag(1003);
    temp->addChild(_pay_id_input_box);
    title = (cocos2d::ui::Text*)pay_id_node->getChildByName("name");
    title->setString("Pay id:");
    title->setFontSize(24);
    
    // price node
    auto price_node = pay_panel->getChildByName("price_node");
    temp = (cocos2d::ui::TextField*)price_node->getChildByName("input_bg");
    input_size = temp->getChildByName("input_box")->getContentSize();
    input_position = temp->getChildByName("input_box")->getPosition();
    input_anchorpoint = temp->getChildByName("input_box")->getAnchorPoint();
    temp->getChildByName("input_box")->removeFromParent();
    _price_input_box =cocos2d::ui::EditBox::create(input_size,
                                                    cocos2d::ui::Scale9Sprite::createWithSpriteFrame(frame));
    _price_input_box->setPosition(input_position);
    _price_input_box->setAnchorPoint(input_anchorpoint);
    _price_input_box->setInputMode(cocos2d::ui::EditBox::InputMode::DECIMAL);
    _price_input_box->setDelegate(this);
    _price_input_box->setTag(1004);
    temp->addChild(_price_input_box);
    title = (cocos2d::ui::Text*)price_node->getChildByName("name");
    title->setString("Price:");
    title->setFontSize(24);
}

void HelloWorld::pay_callback(bool result, std::string msg) {
    CCLOG("pay_callback layer %s", msg.c_str());
    _result_text->setString(_result_text->getString()+"\n"+msg);
}

void HelloWorld::init_callback(bool result, std::string msg) {
    CCLOG("init_callback layer %s", msg.c_str());
    if (result){
        _pay_btn->setTitleText("Pay");
        _result_text->setString(_result_text->getString()+"\n"+msg);
        _isInited = true;
    }else {
        _isInited = false;
        _result_text->setString(_result_text->getString()+"\n"+msg);
    }
}

void HelloWorld::editBoxReturn(cocos2d::ui::EditBox *editBox) {
    switch (editBox->getTag()){
        case 1001:

            break;
        case 1002:

            break;
        case 1003:

            break;
        case 1004:

            break;
    }
}

HelloWorld::HelloWorld():
_appid(""),
_channel(""),
_payid(""),
_price(""),
_isInited(false)
{

}

HelloWorld::~HelloWorld() {

}


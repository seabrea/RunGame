#include "HelloWorldScene.h"

Scene* HelloWorld::createScene()
{

    auto scene = Scene::create();
    

    auto layer = HelloWorld::create();


    scene->addChild(layer);


    return scene;
}

bool HelloWorld::init()
{

    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto mune = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("StartMuen_1.ExportJson");
	this->addChild(mune);

	auto startButton = (Button*)Helper::seekWidgetByName(mune, "Button_5");
	auto overButton = (Button*)Helper::seekWidgetByName(mune, "Button_6");
	startButton->addTouchEventListener(this, toucheventselector(HelloWorld::startButtonOnhandler));
	overButton->addTouchEventListener(this, toucheventselector(HelloWorld::overButtonOnhandler));
    return true;
}

void HelloWorld::startButtonOnhandler(Ref* r, TouchEventType type)
{
	log("GAME!");

	switch (type)
	{
	case TOUCH_EVENT_ENDED:

		Director::getInstance()->replaceScene(TransitionMoveInT::create(1.0f, GameScene::createScene()));

		break;
	}
}

void HelloWorld::overButtonOnhandler(Ref* r, TouchEventType type)
{

	log("END!");

	switch (type)
	{
	case TOUCH_EVENT_ENDED:

		Director::getInstance()->end();

		break;
	}
	
}


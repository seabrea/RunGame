#include "GameScene.h"

Scene* GameScene::createScene()
{
	auto scene = Scene::createWithPhysics();
	//scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	scene->getPhysicsWorld()->setGravity(Vec2(0,-1000));

	auto layer = GameScene::create();

	scene->addChild(layer);

	return scene;
}

bool GameScene::init()
{
	if (!LayerColor::initWithColor(Color4B::WHITE))
	{
		return false;
	}

	visibleSize = Director::getInstance()->getVisibleSize();
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("parkour.plist");

	controllers.insert(0 , Controller::create(this , 50));
	controllers.insert(0, Controller::create(this, 300));
	controllers.insert(0, Controller::create(this, 550));

	auto scoreLabel = LabelTTF::create("time : 0" , "arker Felt" , 42);
	this->addChild(scoreLabel);
	scoreLabel->setColor(Color3B::BLACK);
	scoreLabel->setPosition(Vec2(visibleSize.width / 2 , visibleSize.height / 2));
	scoreLabel->setTag(0);

	auto listener = EventListenerPhysicsContact::create();
	listener->onContactBegin = [this](PhysicsContact& contact)
	{
		UserDefault::getInstance()->setIntegerForKey("time", time);
		UserDefault::getInstance()->flush();
		auto nextScene = GameOverScene::createScene();
		Director::getInstance()->replaceScene(nextScene);
		return true;
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	auto dispatcher = EventListenerTouchOneByOne::create();
	dispatcher->onTouchBegan = [this](Touch* t , Event* e)
	{
		for (auto i = controllers.begin(); i != controllers.end(); i++)
		{
			if ((*i)->hitTestPoint(t->getLocation()))
			{
				(*i)->onTouch();
				break;
			}
		}

		return false;
	};


	auto keyHandler = EventListenerKeyboard::create();
	keyHandler->onKeyReleased = [this](EventKeyboard::KeyCode code , 
		Event* event)
	{
		if (code == EventKeyboard::KeyCode::KEY_BACKSPACE)
		{
			Director::getInstance()->end();
		}
		else if (code == EventKeyboard::KeyCode::KEY_BACK)
		{
			Director::getInstance()->end();
		}
	};

	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(dispatcher, this);

	scheduleUpdate();

	this->schedule(schedule_selector(GameScene::updateTime),0.1f);

	return true;
}

void GameScene::update(float t)
{
	for (auto i = controllers.begin(); i != controllers.end(); i++)
	{
		(*i)->onUpdate(t);
	}
}

void GameScene::updateTime(float t)
{
	++time;
	auto label = static_cast<LabelTTF*>(this->getChildByTag(0));
	label->setString(String::createWithFormat("time : %d.%d" ,(time - time % 10) / 10 , time % 10)->_string);
}


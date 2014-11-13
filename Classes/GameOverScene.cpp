#include "GameOverScene.h"

Scene* GameOverScene::createScene()
{

	auto scene = Scene::create();

	GameOverScene* layer = GameOverScene::create();

	scene->addChild(layer);

	return scene;
}
bool GameOverScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	work();

	return true;
}

void GameOverScene::work()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();

	auto text = LabelTTF::create("GameOver", "Arial", 30);
	text->setPosition(visibleSize.width / 2, visibleSize.height * 5 / 6);
	this->addChild(text);
	auto time = UserDefault::getInstance()->getIntegerForKey("time");
	auto timescore = LabelTTF::create("", "Arial", 30);
	timescore->setString(String::createWithFormat("time : %d.%d",(time - time % 10) / 10, (time % 10))->_string);
	timescore->setPosition(Vec2(visibleSize.width / 2, visibleSize.height * 4 / 6));
	this->addChild(timescore);

	auto restart = MenuItemFont::create("RESTART" , CC_CALLBACK_1(GameOverScene::restartHandler , this));
	restart->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 6));

	auto end = MenuItemFont::create("END", CC_CALLBACK_1(GameOverScene::endHandler, this));
	end->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));

	auto menu = Menu::create(restart,end,NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu);
}

void GameOverScene::restartHandler(Ref* f)
{
	UserDefault::getInstance()->purgeSharedUserDefault();
	Director::getInstance()->replaceScene(TransitionMoveInB::create(1.0f, GameScene::createScene()));
}

void GameOverScene::endHandler(Ref* f)
{
	Director::getInstance()->end();
}


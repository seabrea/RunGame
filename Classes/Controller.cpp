#include "Controller.h"

Controller* Controller::create(Layer* layer, float positionY)
{
	Controller*pRet = new Controller();
	if (pRet && pRet->init(layer, positionY))
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{
		delete pRet;
		pRet = NULL;
		return NULL;
	}
}

bool Controller::init(Layer* layer, float positionY)
{
	_layer = layer;
	_positionY = positionY;

	Size visiblesize = Director::getInstance()->getVisibleSize();

	player = Hero::create();
	player->setPosition(100, player->getContentSize().height / 2 + positionY + 1);
	_layer->addChild(player);

	border = Border::create();
	border->setPosition(visiblesize.width / 2, visiblesize.height / 2 + positionY);
	border->setContentSize(visiblesize);
	_layer->addChild(border);

	auto ground = Sprite::create();
	ground->setColor(Color3B::BLACK);
	ground->setTextureRect(Rect(0, 0, visiblesize.width, 3));
	ground->setPosition(visiblesize.width / 2, 1.5 + positionY);
	_layer->addChild(ground);

	resetFrames();

	return true;
}

void Controller::addBlock()
{
	auto block = Block::create();
	block->setPosition(100, block->block->getContentSize().height / 2 + _positionY);
	_layer->addChild(block);
}

void Controller::resetFrames()
{
	currentFrameIndex = 0;
	nextFrameCount = (rand() % 120) + 100;
}

void Controller::onUpdate(float dt)
{
	currentFrameIndex++;

	if (currentFrameIndex >= nextFrameCount) 
	{
		resetFrames();

		addBlock();
	}
}

void Controller::onTouch()
{
	if (player->getPositionY() <= (player->getContentSize().height + _positionY))
	{
		player->getPhysicsBody()->setVelocity(Vec2(0, 400));
	}
}

bool Controller::hitTestPoint(Point p)
{
	return border->getBoundingBox().containsPoint(p);
}
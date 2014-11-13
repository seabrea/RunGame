#include "Block.h"

bool Block::init()
{
	if (!Sprite::init())
	{
		return false;
	}

	Size size = Size(56,44);
	Size visi = Director::getInstance()->getVisibleSize();

	block = Sprite::createWithSpriteFrameName("rock.png");
	this->addChild(block);

	block->setPhysicsBody(PhysicsBody::createBox(size));
	block->getPhysicsBody()->setDynamic(false);
	block->setPositionX(visi.width);
	block->setContentSize(size);
	block->getPhysicsBody()->setContactTestBitmask(1);

	scheduleUpdate();

	return true;
}

void Block::update(float t)
{
	block->setPositionX(block->getPositionX() - 5);

	if (block->getPositionX() < (0-block->getContentSize().width))
	{
		unscheduleUpdate();
		removeFromParent();
	}
}
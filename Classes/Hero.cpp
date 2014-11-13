#include "Hero.h"

bool Hero::init()
{
	if (!Sprite::init())
	{
		return false;
	}

	Size size = Size(52, 56);

	//SpriteFrameCache::getInstance()->addSpriteFramesWithFile("parkour.plist");
	Vector<SpriteFrame*>frames;
	auto run1 = SpriteFrameCache::getInstance()->getSpriteFrameByName("runner1.png");
	auto run2 = SpriteFrameCache::getInstance()->getSpriteFrameByName("runner2.png");
	auto run3 = SpriteFrameCache::getInstance()->getSpriteFrameByName("runner3.png");
	//auto run4 = SpriteFrameCache::getInstance()->getSpriteFrameByName("runner4.png");
	auto run5 = SpriteFrameCache::getInstance()->getSpriteFrameByName("runner5.png");
	auto run6 = SpriteFrameCache::getInstance()->getSpriteFrameByName("runner6.png");
	auto run7 = SpriteFrameCache::getInstance()->getSpriteFrameByName("runner7.png");
	frames.pushBack(run1);
	frames.pushBack(run2);
	frames.pushBack(run3);
	//frames.pushBack(run4);
	frames.pushBack(run5);
	frames.pushBack(run6);
	frames.pushBack(run7);

	Animation* animation = Animation::createWithSpriteFrames(frames , 0.06f);

	this->runAction(RepeatForever::create(Animate::create(animation)));

	this->setPhysicsBody(PhysicsBody::createBox(size));
	this->getPhysicsBody()->setRotationEnable(false);
	this->setContentSize(size);
	this->getPhysicsBody()->setContactTestBitmask(1);

	return true;
}
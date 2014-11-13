#include "Border.h"

bool Border::init()
{
	if (!Node::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();

	this->setPhysicsBody(PhysicsBody::createEdgeBox(visibleSize));

	this->setContentSize(visibleSize);

	return true;
}
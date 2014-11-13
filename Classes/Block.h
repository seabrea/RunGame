#pragma once 

#include "cocos2d.h"

USING_NS_CC;

class Block : public Sprite
{
public:
	virtual bool init();

	virtual void update(float t);

	CREATE_FUNC(Block);

	Sprite* block;
};
#pragma once

#include "cocos2d.h"
#include "Hero.h"
#include "Block.h"
#include "Border.h"

USING_NS_CC;

class Controller : public Ref 
{
public:
	virtual bool init(Layer* layer , float positionY);
	static Controller* create(Layer* layer, float positionY);

	void onUpdate(float dt);

	int currentFrameIndex;

	float nextFrameCount;

	bool hitTestPoint(Point p);

	void onTouch();

private:
	Layer* _layer;

	Border* border;

	Hero* player;

	float _positionY;

	void addBlock();

	void resetFrames();

};
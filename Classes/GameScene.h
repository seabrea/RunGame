#pragma once

#include "cocos2d.h"
#include "Controller.h"
#include "GameOverScene.h"

USING_NS_CC;

class GameScene : public LayerColor
{
public:
	virtual bool init();

	static Scene* createScene();

	CREATE_FUNC(GameScene);

public:

	Size visibleSize;

	Vector<Controller*>controllers;

private:
	int time = 0;

	virtual void update(float t);

	void updateTime(float t);
};
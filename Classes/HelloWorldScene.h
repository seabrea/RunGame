#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "cocostudio\CocoStudio.h"
#include "ui\CocosGUI.h"
#include "editor-support\cocostudio\CCSGUIReader.h"
#include "GameScene.h"
//#include "cocos-ext.h"

USING_NS_CC;
//USING_NS_CC_EXT;
using namespace ui;
using namespace cocostudio;


class HelloWorld : public cocos2d::Layer
{
public:
    
    static cocos2d::Scene* createScene();

    
    virtual bool init();  
    
    void menuCloseCallback(cocos2d::Ref* pSender);

    CREATE_FUNC(HelloWorld);

private:
	void startButtonOnhandler(Ref* r, TouchEventType type);

	void overButtonOnhandler(Ref* r, TouchEventType type);
};

#endif // __HELLOWORLD_SCENE_H__

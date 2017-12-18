#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;
class HelloWorld : public cocos2d::Layer
{
	cocos2d::Sprite *sprite;
	
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
	void moveToRight();
	void moveToLeft();
	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
	virtual  void update(float dt);
    CREATE_FUNC(HelloWorld);
private:
	Sprite*fish;
	Sprite*bg;
};

#endif // __HELLOWORLD_SCENE_H__

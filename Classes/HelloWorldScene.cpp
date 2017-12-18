#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	/*auto layer1 = LayerColor::create(Color4B(100, 255, 255, 255));
	layer1->setContentSize(CCSizeMake(600, 600));
	layer1->ignoreAnchorPointForPosition(false);
	layer1->setAnchorPoint(Point(0.5, 0.5));
	
	layer1->setPosition(visibleSize.width/2,visibleSize.height/2);
	
	scene->addChild(layer1, 10);

	auto layer2= LayerColor::create(Color4B(255,100, 100, 255));
	layer2->setContentSize(CCSizeMake(300, 300));
	layer2->ignoreAnchorPointForPosition(false);
	layer2->setAnchorPoint(Point(0.5, 0.5));

	layer2->setPosition(visibleSize.width / 2, visibleSize.height / 2);

	scene->addChild(layer2, 11);

	auto layer3 = LayerColor::create(Color4B(200, 255, 100, 255));
	layer3->setContentSize(CCSizeMake(150,150));
	layer3->ignoreAnchorPointForPosition(false);
	layer3->setAnchorPoint(Point(0.5, 0.5));

	layer3->setPosition(visibleSize.width / 2, visibleSize.height / 2);

	scene->addChild(layer3,12);*/

	

	
 
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	/////////////////////////////
	//   // 2. add a menu item with "X" image, which is clicked to quit the program
	//   //    you may modify it.

	//   // add a "close" icon to exit the progress. it's an autorelease object
	//   auto closeItem = MenuItemImage::create(
	//                                          "CloseNormal.png",
	//                                          "CloseSelected.png",
	//                                          CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
	//   
	//closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
	//                               origin.y + closeItem->getContentSize().height/2));

	//   // create menu, it's an autorelease object
	//   auto menu = Menu::create(closeItem, NULL);
	//   menu->setPosition(Vec2::ZERO);
	//   this->addChild(menu, 1);

	//   /////////////////////////////
	//   // 3. add your codes below...

	//   // add a label shows "Hello World"
	//   // create and initialize a label
	//   
	//   auto label = LabelTTF::create("Hello World", "Arial", 24);
	//   
	//   // position the label on the center of the screen
	//   label->setPosition(Vec2(origin.x + visibleSize.width/2,
	//                           origin.y + visibleSize.height - label->getContentSize().height));

	//   // add the label as a child to this layer
	//   this->addChild(label, 1);

	//   // add "HelloWorld" splash screen"
	//   auto sprite = Sprite::create("HelloWorld.png");

	//   // position the sprite on the center of the screen
	//   sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

	//   // add the sprite as a child to this layer
	//   this->addChild(sprite, 0);
	//
	/*auto fish = Sprite::create("fish.png");
	fish->setPosition(Point(100, 100));
	this->addChild(fish);
	auto moveto1 = MoveTo::create(1.5, Point(600,600));*/
	/*fish->runAction(action);*/

	/*auto moveBy = MoveBy::create(3.0f, ccp(400, 0));
	auto flipxAction = FlipX::create(true);
	auto jumpto1=JumpTo::create(2, Point(460,400),
	100, 2);
	ccBezierConfig bezier;
	bezier.controlPoint_1 = Point(600, 600);
	bezier.controlPoint_2 = Point(150, 150);
	bezier.endPosition = Point(200, 300);
	auto bezierAction = BezierTo::create(1.0, bezier);

	auto blinkAction1 = Blink::create(1.5f, 5);
	auto scale1=ScaleTo::create(2, 0.5);
	auto scale2 = ScaleTo::create(2, 2);







	auto action = Sequence::create(moveto1, bezierAction, blinkAction1, scale1, moveBy, flipxAction, moveBy->reverse(), jumpto1, scale2,NULL);

	fish->runAction(action);*/

	
	
	
	/*SpriteFrameCache::getInstance()->addSpriteFramesWithFile("run.plist");
	sprite = Sprite::createWithSpriteFrameName("run.png");
	sprite->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
	addChild(sprite,12);
	Animation *animation = Animation::create();
	for (int i = 1; i <= 10; i++){
		String * frameName = String::createWithFormat("a%d.png", i);
		log("frameName= %s", frameName->getCString());
		SpriteFrame *spriteFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(frameName->getCString());
		animation->addSpriteFrame(spriteFrame);
	}
	animation->setDelayPerUnit(0.15f);//两帧之间的播放间隔
	animation->setRestoreOriginalFrame(true);
	Animate *action = Animate::create(animation);
	sprite->runAction(RepeatForever::create(action));*/
	
	
	
	// 键盘控制鱼的移动
	
	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = CC_CALLBACK_2(HelloWorld::onKeyPressed, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
      

	bg = Sprite::create("bg.png");
	bg->setPosition(Vec2(0,0));
	bg->ignoreAnchorPointForPosition(false);
	bg->setAnchorPoint(Point(0, 0));
	
	
	addChild(bg, 1);
	 fish = Sprite::create("fish.png");
	fish->setPosition(Point(260, 250));
	fish->setScale(0.5);
	this->addChild(fish,2);

	this->scheduleUpdate();




return true;
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
void HelloWorld::moveToRight(){
	fish->setPositionX(fish->getPositionX() + 20);
	if (fish->getPositionX() > 600){
		fish->setPositionX(600);
	}

}
void HelloWorld::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event){
	if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
		moveToRight();
	if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW)
		moveToLeft();

}
void HelloWorld::moveToLeft(){
	fish->setPositionX(fish->getPositionX() -20);
	if (fish->getPositionX() <40){
		fish->setPositionX(40);
	}
}
void HelloWorld::update(float dt){
	Size visibleSize = Director::getInstance()->getVisibleSize();
	/*if (fish->getPositionX() <= visibleSize.width / 2)
	{*/
		/*if (fish->getPositionX() != visibleSize.width / 2 ||
		bg->getPositionX() == -(bg->getContentSize().width - visibleSize.width))
		{
		fish->setPositionX(fish->getPositionX() + 20);
		}*/
		/*if (fish->getPositionX() == visibleSize.width / 2)
		{*/
		if (fish->getPositionX() >=350 /*|| bg->getPositionX() != -(bg->getContentSize().width - visibleSize.width)*/)
			{
			    
			bg->setPosition(bg->getPositionX() - 1, bg->getPositionY());
			if (bg->getPositionX() <= -359)
			{
				bg->setPositionX(-359);
			}
				
			}

		if (fish->getPositionX() <= 290 /*|| bg->getPositionX() != -(bg->getContentSize().width - visibleSize.width)*/)
		{

			bg->setPosition(bg->getPositionX() + 1, bg->getPositionY());
			if (bg->getPositionX() >=0)
			{
				bg->setPositionX(0);
			}

		}
		
		}
	/*}*/


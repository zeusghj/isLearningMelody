//
//  IndexScene.cpp
//  isLearningMelody
//
//  Created by guohongjun on 13-12-13.
//
//

#include "IndexScene.h"
#include "GamePlayScene.h"

USING_NS_CC ;

Scene *IndexScene::createScene()
{
    auto scene = Scene::create() ;
    
    auto layer = IndexScene::create() ;
    
    scene->addChild(layer) ;
    
    return scene ;
}

bool IndexScene::init()
{
    ///////////////////////////
    //1.super init first..
    if (!Layer::init()) {
        return  false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize() ;
    Point origin = Director::getInstance()->getVisibleOrigin();
    
    /////////////////////////////
    // 2. add your codes below...
    
    // add splash screen"
    auto sprite = Sprite::create("index.png");
    
    // position the sprite on the center of the screen
    sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    sprite->setScale(_WIDGET_SCALE_X_, _WIDGET_SCALE_Y_) ;
    
    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    
    
    //add a play game menu item.
    auto startItem = MenuItemImage::create(
                                           "btn-play-nz.png",
                                           "btn-play-pz.png",
                                           CC_CALLBACK_1(IndexScene::gamePlayAction, this)) ;
    startItem->setScale(_WIDGET_SCALE_Y_, _WIDGET_SCALE_Y_) ;
    
    Rect rect = startItem->getBoundingBox() ;
    
    startItem->setPosition(Point(visibleSize.width/2 + origin.x,visibleSize.height/5 +origin.y - rect.size.height/2)) ;
    
    
    //create menu, it's an autorelease object
    auto menu = Menu::create(startItem, NULL) ;
    menu->setPosition(Point::ZERO) ;
    
    this->addChild(menu, 1) ;
    
    
    return true ;
}

void IndexScene::gamePlayAction(cocos2d::Object *pSender)
{
    Director::getInstance()->replaceScene(CCTransitionFade::create(0.5, GamePlayScene::createScene())) ;
}


void IndexScene::menuCloseCallback(Object *pSender)
{
    Director::getInstance()->end() ;
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

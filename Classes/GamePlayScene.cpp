//
//  GamePlayScene.cpp
//  isLearningMelody
//
//  Created by guohongjun on 13-12-13.
//
//

#include "GamePlayScene.h"
#include "KeyboardLayer.h"

USING_NS_CC ;

Scene *GamePlayScene::createScene()
{
    auto scene = Scene::create() ;
    
    auto layer = GamePlayScene::create() ;
    
    scene->addChild(layer) ;
    
    return scene ;
}

bool GamePlayScene::init()
{
    ///////////////////////////
    //1.super init first..
    if (!Layer::init()) {
        return  false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize() ;
    Point origin = Director::getInstance()->getVisibleOrigin();
    
    auto sprite = Sprite::create("game.png");
    
    // position the sprite on the center of the screen
    sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    sprite->setScale(_WIDGET_SCALE_X_, _WIDGET_SCALE_Y_) ;
    
    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    
    
    //add the keyboard background image...
    auto keyboard = PianoKeyBoard::create("game-keyboard.png") ;
    keyboard->init() ;
    keyboard->setScale(_WIDGET_SCALE_X_, _WIDGET_SCALE_Y_) ;
    Size keyboardSize = (keyboard->getBoundingBox()).size ;
    keyboard->setPosition(Point(visibleSize.width - (keyboardSize.width/2), (keyboardSize.height/2) + origin.y));
    
    this->addChild(keyboard, 1) ;
    
    //add the play and pause MenuItem..
    auto playItem = MenuItemImage::create(
                                           "btn-Broadcast-n.png",
                                           "btn-Broadcast-p.png",
                                           CC_CALLBACK_1(GamePlayScene::playCallback, this)) ;
   
    playItem->setScale(_WIDGET_SCALE_Y_, _WIDGET_SCALE_Y_) ;
    Size pItemSize = (playItem->getBoundingBox()).size ;
    
    int xOff = ((visibleSize.width-keyboardSize.width) - pItemSize.width) / 2 ;
    if (xOff<0) {
        xOff = 0 ;
    }
    
    playBtnRct = Rect((pItemSize.width/2) + xOff , pItemSize.height/2, pItemSize.width, pItemSize.height) ;
    
    playItem->setPosition(Point((pItemSize.width/2) + xOff,pItemSize.height/2)) ;
    
    //create menu, it's an autorelease object
    auto menu = Menu::create(playItem, NULL) ;
    menu->setPosition(Point::ZERO) ;
    
    this->addChild(menu, 1) ;
    
    
    return true ;
}

void GamePlayScene::playCallback(cocos2d::Object *pSender)
{
    MenuItemImage *item = (MenuItemImage *)pSender ;
    
    
    item->setNormalSpriteFrame(SpriteFrame::create("btn-pause-n.png", playBtnRct)) ;
     item->setSelectedSpriteFrame(SpriteFrame::create("btn-pause-p.png", playBtnRct)) ;
}


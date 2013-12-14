//
//  GamePlayScene.h
//  isLearningMelody
//
//  Created by guohongjun on 13-12-13.
//
//

#ifndef __isLearningMelody__GamePlayScene__
#define __isLearningMelody__GamePlayScene__

#include <iostream>
#include "cocos2d.h"
#include "MyCommon.h" 


class GamePlayScene : public cocos2d::Layer {
public:
    static cocos2d::Scene *createScene() ;
    
    virtual bool init() ;
    
    CREATE_FUNC(GamePlayScene) ;
    
private:
    
    void playCallback(Object *pSender) ;
    
private:
    cocos2d::Rect playBtnRct ;
    
};




























#endif /* defined(__isLearningMelody__GamePlayScene__) */

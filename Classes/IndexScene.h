#ifndef __isLearningMelody__IndexScene__
#define __isLearningMelody__IndexScene__

#include <iostream>
#include "cocos2d.h"
#include "MyCommon.h"

class IndexScene : public cocos2d::Layer {
public:
    static cocos2d::Scene *createScene() ;
    
    virtual bool init() ;
    
    void menuCloseCallback(Object *pSender) ;
    
    CREATE_FUNC(IndexScene) ;
    
private:
    void gamePlayAction(Object *pSender) ;
    
};





















#endif /* defined(__isLearningMelody__IndexScene__) */

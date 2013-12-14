//
//  MyCommon.h
//  isLearningMelody
//
//  Created by guohongjun on 13-12-13.
//
//

#ifndef isLearningMelody_MyCommon_h
#define isLearningMelody_MyCommon_h

#define _SCREEN_WIDTH_    Director::getInstance()->getVisibleSize().width
#define _SCREEN_HEIGHT_   Director::getInstance()->getVisibleSize().height

#define _WIDGET_SCALE_X_  (_SCREEN_WIDTH_/2048.f)
#define _WIDGET_SCALE_Y_  (_SCREEN_HEIGHT_/1536.f)


inline std::string itoa(int value)
{
    std::stringstream s ;
    
    s << value ;
    
    return s.str() ;
}


#endif

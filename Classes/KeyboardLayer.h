//
//  KeyboardLayer.h
//  isLearningMelody
//
//  Created by guohongjun on 13-12-13.
//
//

#ifndef __isLearningMelody__KeyboardLayer__
#define __isLearningMelody__KeyboardLayer__

#include <iostream>
#include "cocos2d.h"
#include "DataCenter.h"


class PianoKey :public cocos2d::Object
{
public:
    int note_;
    int type_;
    //int finger_;
    //bool left_;
    bool matching_;
    bool down_;
    bool selected_;
    cocos2d::Point position_;
    cocos2d::Rect  rect_;
};

class PianoKeyBoard : public cocos2d::Sprite {
    
public:
    static PianoKeyBoard* create(const std::string& filename);
    
    virtual bool init() ;
    
    CREATE_FUNC(PianoKeyBoard) ;
    
private:
    int lowNote_ ;
    int highNote_ ;
    
    bool isCenterC ;
    cocos2d::Dictionary *keys_ ;
    cocos2d::Size keyboardSize_ ;
    
    float whiteKeyWidth_ ;
	float whiteKeyHeight_ ;
	float blackKeyWidth_ ;
	float blackKeyHeight_ ;
    
    const char* whiteNormalPix_ ;
	const char* whiteDownPix_ ;
    const char* whiteErrorPix_ ;
	const char* blackNormalPix_ ;
	const char* blackDownPix_ ;
    const char* blackErrorPix_ ;
    
public:
    cocos2d::Size getSize() ;
    
private:
    void calculateKeySize(cocos2d::Size size);
    float getBlackKeyOffset(int note) ;
    
    void createKeys(void) ;
    void drawKeyBoard(void) ;
    void drawImageKey(Node *node , PianoKey *key, int zOder);//添加按键精灵
    
    void keyTouched(Object *pSender) ;
    
};
























#endif /* defined(__isLearningMelody__KeyboardLayer__) */

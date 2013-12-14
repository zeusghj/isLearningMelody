//
//  DataCenter.h
//  PianoKeyboard
//
//  Created by guohongjun on 13-6-18.
//  Copyright (c) 2013年 Hongjun Guo. All rights reserved.
//

/*****
    处理键盘，midi发声等的数据。
 *****/

#ifndef __PianoKeyboard__DataCenter__
#define __PianoKeyboard__DataCenter__

#include <iostream>
#include "cocos2d.h"

using namespace cocos2d;

static std::string OCTAVE_NOTES[] = { "C", "C#", "D", "Eb", "E", "F", "F#", "G", "G#", "A", "Bb", "B" };

enum KEYTYPE
{
	BLACK_KEY = 0,
	WHITE_PURE,
	WHITE_RIGHT_BLACK,
	WHITE_LEFT_BLACK,
	WHITE_BOTH_BLACK
};

//extern CCString OCTAVE_NOTES[];
extern KEYTYPE OCTAVE_TYPE[];

class DataCenter
{
private:
    static DataCenter* m_pDataCenter;
    
public:
    static DataCenter* Get();
    static void release();
    
public:
    DataCenter();
    virtual ~DataCenter();
    
    void Init();
    void Exit();
    

};

inline int octave(int note)
{
    return note % 12;//Midi::TWELVE_TONE;
}

inline KEYTYPE getKeyType(int note)
{
    return OCTAVE_TYPE[octave(note)];
}

inline std::string getKeyName(int note)
{
	return OCTAVE_NOTES[octave(note)];
}

inline bool isBlackKey(KEYTYPE type)
{
	return (type == BLACK_KEY);
}

inline bool is_blackkey(int note)
{
	return isBlackKey(getKeyType(note));
}

#endif /* defined(__PianoKeyboard__DataCenter__) */

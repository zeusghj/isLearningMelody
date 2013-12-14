//
//  KeyboardLayer.cpp
//  isLearningMelody
//
//  Created by guohongjun on 13-12-13.
//
//

#include "KeyboardLayer.h"
#include "MyCommon.h"

USING_NS_CC ;

bool PianoKeyBoard::init()
{
    //1.enable the touch event...
    
    //2.
    lowNote_ = 48 ;
    highNote_ = 83 ;
    
    keys_ =new Dictionary();
   
    whiteNormalPix_="game-keyboard-white.png";
    whiteDownPix_="game-keyboard-white-p.png";
    whiteErrorPix_="game-keyboard-white-pw.png";
    blackNormalPix_="game-keyboard-black.png";
    blackDownPix_="game-keyboard-black-p.png";
    blackErrorPix_="game-keyboard-black-pw.png";
    
    
    keyboardSize_ = (this->getBoundingBox()).size ;
    calculateKeySize(keyboardSize_);
    
    createKeys();
    
    drawKeyBoard();
    
    return true ;
}

void PianoKeyBoard::calculateKeySize(cocos2d::Size size)
{
    int whiteKeyCount = 0 ;
    
	for ( int i=lowNote_; i<=highNote_; ++i )
	{
		if ( !isBlackKey(getKeyType(i)))
		{
			++whiteKeyCount ;
		}
	}
    
	whiteKeyWidth_ = (size.width-42) / whiteKeyCount ;
	whiteKeyHeight_ = 243  ;
	blackKeyWidth_ = whiteKeyWidth_ * 16 /27 ;
	blackKeyHeight_ = 124  ;

}

float PianoKeyBoard::getBlackKeyOffset(int note)
{
    float offset(0) ;
	float space(0) ;
	int whiteKeyCount(0) ;
	int blackKeyCount(0) ;
	int octaveNote = octave(note) ;
    
	for ( int i=0; i<octaveNote; ++i )
	{
		if ( is_blackkey(i))
		{
			++blackKeyCount ;
		}
		else
		{
			++whiteKeyCount ;
		}
	}
    
	if ( octaveNote < 5 )
	{
		space = whiteKeyWidth_ - blackKeyWidth_ * 2 / 3 ;
		offset =  space * whiteKeyCount + blackKeyWidth_ * blackKeyCount ;
		offset -= whiteKeyWidth_ * (whiteKeyCount - 1) ;
	}
	else
	{
		space = whiteKeyWidth_ - blackKeyWidth_ * 3 / 4 ;
		whiteKeyCount -= 3 ;
		blackKeyCount -= 2 ;
		offset =  space * whiteKeyCount + blackKeyWidth_ * blackKeyCount ;
		offset -= whiteKeyWidth_ * (whiteKeyCount - 1) ;
	}
    
	if ( offset < 0 )
	{
		assert(false) ;
	}
    
	return offset ;
}

void PianoKeyBoard::createKeys()
{
    keys_->removeAllObjects();
    
	float x = 0;
    
	for (int i=lowNote_; i<=highNote_; ++i)
	{
        PianoKey *key = new PianoKey();
        
        KEYTYPE type = getKeyType(i);
		Point pt = Point::ZERO ;
		Rect rect;
        
		if (isBlackKey(type))
		{
			pt.x = x - whiteKeyWidth_ + getBlackKeyOffset(i) ;
		}
		else
		{
			pt.x = x ;
			x += whiteKeyWidth_ ;
		}
        
		if (isBlackKey(type))
		{
			rect = Rect(pt.x+20, pt.y+17, blackKeyWidth_, blackKeyHeight_);
		}
		else
		{
			int offset = int(x) - (int(pt.x) + int(whiteKeyWidth_)) ;
            
            offset = (float)1.0/2;
            
			rect = Rect(pt.x+20, pt.y+17, whiteKeyWidth_+offset, whiteKeyHeight_);
		}
		key->note_ = i;
		key->type_ = type;
		key->rect_ = rect;
        
		key->position_ = pt;
		key->down_ = false;
        key->matching_ = false;
        
        keys_->setObject(key, itoa(i));
        
        key->release();
	}
    
}

void PianoKeyBoard::drawKeyBoard()
{
    CHECK_GL_ERROR_DEBUG();//to test GL error
    
    //clean all the children before redraw keyboard
    Array *nodesArr = this->getChildren();
    
    if (nodesArr != NULL) {
        
        this->removeAllChildren();
    }
    
    isCenterC = false;//make sure to draw "center C" when redraw keyboard
    
    //create menu, it's an autorelease object
    auto menu = Menu::create() ;
    menu->setPosition(Point::ZERO) ;
    
    for ( int i=lowNote_; i<=highNote_; ++i)
    {
        PianoKey* key = (PianoKey *)keys_->objectForKey(itoa(i));
        
        if (key->type_ != BLACK_KEY)
        {
            drawImageKey(menu, key,1);
            
            //keyTag ++;
        }
    }
    
    for ( int i=lowNote_; i<=highNote_; ++i)
    {
        PianoKey* key = (PianoKey *)keys_->objectForKey(itoa(i));
        
        if (key->type_ == BLACK_KEY)
        {
            drawImageKey(menu, key,2);
            
            //keyTag ++;
        }
    }
    
    this->addChild(menu,0) ;
    
}

void PianoKeyBoard::keyTouched(Object *pSender)
{
    CCLOG(__FUNCTION__) ;
}

void PianoKeyBoard::drawImageKey(cocos2d::Node *node, PianoKey *key, int zOder)
{
    if (key == NULL) {
        
        return ;
    }
    
    Rect rct = key->rect_;
    
    MenuItemImage *keySprite  ;

    if (key->type_ != BLACK_KEY) {
        keySprite = MenuItemImage::create(whiteNormalPix_, whiteDownPix_, CC_CALLBACK_1(PianoKeyBoard::keyTouched, this)) ;
        keySprite->setPosition(rct.origin.x, rct.origin.y) ;
    }else
    {
        keySprite = MenuItemImage::create(blackNormalPix_, blackDownPix_, CC_CALLBACK_1(PianoKeyBoard::keyTouched, this)) ;
        keySprite->setPosition(rct.origin.x, rct.origin.y+119) ;
    }
    
    keySprite->setAnchorPoint(Point::ZERO) ;
    keySprite->setTag(key->note_) ;

    node->addChild(keySprite, zOder) ;
    

}

PianoKeyBoard* PianoKeyBoard::create(const std::string& filename)
{
    
    PianoKeyBoard *sprite = new PianoKeyBoard();
    if (sprite && sprite->initWithFile(filename))
    {
        sprite->autorelease();
        
        return sprite;
    }
    CC_SAFE_DELETE(sprite);
    return NULL;
}















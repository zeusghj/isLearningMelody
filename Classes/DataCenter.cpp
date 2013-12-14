//
//  DataCenter.cpp
//  PianoKeyboard
//
//  Created by guohongjun on 13-6-18.
//  Copyright (c) 2013年 Hongjun Guo. All rights reserved.
//

#include "DataCenter.h"


KEYTYPE OCTAVE_TYPE[] =
{
    WHITE_RIGHT_BLACK, //c
	BLACK_KEY, //c#
	WHITE_BOTH_BLACK, //d
	BLACK_KEY, //d#
	WHITE_LEFT_BLACK, //e
	WHITE_RIGHT_BLACK, //f
	BLACK_KEY, //f#
	WHITE_BOTH_BLACK, //g
	BLACK_KEY, //g#
	WHITE_BOTH_BLACK, //a
	BLACK_KEY, //a#
	WHITE_LEFT_BLACK //b
};


DataCenter* DataCenter::m_pDataCenter = NULL;

DataCenter* DataCenter::Get()
{
    if ( m_pDataCenter == NULL)
    {
        m_pDataCenter = new DataCenter ;
        m_pDataCenter->Init() ;
    }
    
    return m_pDataCenter ;
    
}

void DataCenter::release()
{
    delete m_pDataCenter;
    
    m_pDataCenter = NULL;
}

DataCenter::DataCenter()
{
    
}

DataCenter::~DataCenter()
{
    
}

void DataCenter::Init()
{
    
    
}

void DataCenter::Exit()
{
    
}










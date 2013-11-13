//
//  LWConfig.h
//  LWGame
//
//  Created by 李跃文 on 13-7-26.
//
//

#ifndef __LWGame__LWConfig__
#define __LWGame__LWConfig__

#include <iostream>
#include "cocos2d.h"
#define DIRECTOR CCDirector::sharedDirector()
#define SCREEN DIRECTOR->getWinSize() // design resolution
#define CENTER ccp(SCREEN.width / 2, SCREEN.height / 2)
#define Def_IsIPod5   (CCDirector::sharedDirector() ->getWinSize().height == 1136)
#define Def_NORetina   (CCDirector::sharedDirector() ->getWinSize().height == 480)

//Game
#define PlayerJumpTime 0.3
#define PlayerSpeed 15
#define BigCandy 100


//


using namespace cocos2d;
class LWConfig : public CCObject
{
public:
    
    
};
#endif /* defined(__LWGame__LWConfig__) */

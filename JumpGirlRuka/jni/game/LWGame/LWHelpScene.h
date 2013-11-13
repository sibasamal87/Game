//
//  LWShopScene.h
//  EasterGame
//
//  Created by 李跃文 on 13-9-30.
//
//

#ifndef __EasterGame__LWHelpScene__
#define __EasterGame__LWHelpScene__
#define Tag_backTop 10

#include <iostream>
#include "LWConfig.h"
#include "LWGameOverScene.h"
#include "LWGM.h"
#include "LWAudioGM.h"
#include "LWGameRole.h"
#include "LWStartScene.h"
//#include "LWWebView.h"
class LWHelpScene: public CCLayer
{
public:
    ~LWHelpScene();
    LWHelpScene();
    static CCScene* creatHelpScene();
    void pushMenu(CCNode *sender);


};



#endif /* defined(__EasterGame__LWShopScene__) */

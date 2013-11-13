//
//  LWShopScene.h
//  EasterGame
//
//  Created by 李跃文 on 13-9-30.
//
//

#ifndef __EasterGame__LWShopScene__
#define __EasterGame__LWShopScene__
#define Tag_shop1 11
#define Tag_shop2 12
#define Tag_shop3 13
#define Tag_shop4 14
#define Tag_back 15

#define Price_Item1 1000
#define Price_Item2 1000
#define Price_Item3 2000
#define Price_Item4 2000

#include <iostream>
#include "LWConfig.h"
#include "LWGameOverScene.h"
#include "LWGM.h"
#include "LWAudioGM.h"
#include "LWGameRole.h"
#include "LWStartScene.h"
//#include "LWWebView.h"
class LWShopScene: public CCLayer
{
public:
    ~LWShopScene();
    LWShopScene();
    CCArray *m_array;
    CCLabelTTF *candyTb;
    CCMenuItemImage *itemShop1;
    CCMenuItemImage *itemShop2;
    CCMenuItemImage *itemShop3;
    CCMenuItemImage *itemShop4;
    static CCScene* creatShopScene();
    void buyItem(int type);
    void pushMenu(CCNode *sender);
    void addAds();
    void reflesh();

};



#endif /* defined(__EasterGame__LWShopScene__) */

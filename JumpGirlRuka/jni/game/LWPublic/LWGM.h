//
//  LWGM.h
//  LWGame
//
//  Created by 李跃文 on 13-7-26.
//
//

#ifndef __LWGame__LWGM__
#define __LWGame__LWGM__

#include <iostream>
#include "LWConfig.h"
class LWGM : public CCNode
{
public:
    ~LWGM();
    static LWGM *shared();
    virtual bool init();
    CC_SYNTHESIZE(int, m_gameCount, GameCount);
    CC_SYNTHESIZE(int, m_shopSign, ShopSign);
    float sysVerson();
    int m_maxBeatCount;
    int m_mantouBeatCount;
    
    
    
    void showText(std::string text);
    void hiddenText();
    void buyItem(int type);
    void noMoney();
    CCLayer *m_shop;
    CCLayer *m_gameScene;
    
    CCLayer *m_Layer;
    CCLabelTTF *m_Label;
    bool m_isPause;
    bool m_isStartLayer;
};
#endif /* defined(__LWGame__LWGM__) */

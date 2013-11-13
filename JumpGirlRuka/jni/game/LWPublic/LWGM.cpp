//
//  LWGM.cpp
//  LWGame
//
//  Created by æ�Žè·ƒæ–‡ on 13-7-26.
//
//

#include "LWGM.h"
static LWGM *gm_instance = NULL;
LWGM *LWGM::shared()
{
    if (!gm_instance) {
        gm_instance = new LWGM;
        gm_instance->init();
    }
    return gm_instance;
}

LWGM:: ~LWGM()
{
    
}
bool LWGM::init()
{
    m_isStartLayer=true;
    m_maxBeatCount=0;
    m_mantouBeatCount=0;
    m_gameCount = 0;
    m_shopSign=1;
    m_gameScene=NULL;
    
    m_isPause=false;
//    m_Label = CCLabelTTF::create("LewenGame", "HiraKakuProN-W6", 40);
//    m_Label->setPosition(ccp(CENTER.x, SCREEN.height+200));
//    DIRECTOR->getRunningScene()->addChild(m_Label, INT_MAX);
    return true;
}

void LWGM::showText(std::string text)
{
    m_Label->setString(text.c_str());
    CCMoveTo *move = CCMoveTo::create(0.6, ccp(CENTER.x, SCREEN.height-200));
    m_Label->runAction(move);
}
void LWGM::hiddenText()
{
    CCMoveTo *move = CCMoveTo::create(0.6, ccp(CENTER.x, SCREEN.height+200));
    m_Label->runAction(move);
}

float LWGM::sysVerson()
{
//    return  [[[UIDevice currentDevice] systemVersion] floatValue];
	return 1.0;
}
void LWGM::buyItem(int type)
{
    
//    [[GameCenterManager shareManager] buyItem:type];
}
void LWGM::noMoney()
{
//    UIAlertView *alertView = [[UIAlertView alloc]
//                              initWithTitle:@"ã�Šè�“å­�ã�®æ•°ã�Œã�Ÿã‚Šã�¾ã�›ã‚“"
//                              message:nil
//                              delegate:nil
//                              cancelButtonTitle:@"OK"
//                              otherButtonTitles:nil];
//    [alertView show];
}



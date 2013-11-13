//
//  LWGameOverScene.cpp
//  LWGame
//
//  Created by æ�Žè·ƒæ–‡ on 13-7-29.
//
//

#include "LWGameOverScene.h"
#include "LWStartScene.h"
#include "LWGameScene.h"
//#include "LWWebView.h"
#include "LWShopScene.h"
#include "AppAssitant.h"
LWGameOverScene::~LWGameOverScene()
{
//    LWWebView *web = (LWWebView*)this->getChildByTag(tag_ad_bottom1);
//    web->HideWebViewWithTag(tag_ad_bottom1);
}


CCScene* LWGameOverScene::creatGameOverScene(int type)
{
    CCScene *scene = CCScene::create();
    
    LWGameOverScene* layer = new LWGameOverScene();
    layer->init(type);
    scene->addChild(layer);
    layer->autorelease();
    
    return scene;
}
bool LWGameOverScene::init(int type)
{
    
    m_type=type;
    CCSprite *backGround;
    if (Def_IsIPod5)
    {
        backGround=CCSprite::create("Image/gameover_bg_1136@2x.png");
    }
    else
    {
        backGround=CCSprite::create("Image/gameover_bg_960@2x.png");
    }

    
    backGround->setPosition(CENTER);
    this->addChild(backGround);
    CCSprite *gameBg=CCSprite::create("Image/scoreboard_bg@2x.png");
    gameBg->setPosition(CENTER);
    backGround->addChild(gameBg);
    
    CCSprite *boardSp=CCSprite::create("Image/top3board@2x.png");
    boardSp->setPosition(ccp(gameBg->getContentSize().width/2, gameBg->getContentSize().height/2-70));
    gameBg->addChild(boardSp);
    
    
    
    CCMenuItemImage *menuRetry= CCMenuItemImage::create("Image/retrial@2x.png","Image/retrial@2x.png");
    menuRetry->setTag(Tag_MenuRetry);
    menuRetry->setTarget(this, menu_selector(LWGameOverScene::pushMenu));
    
    CCMenuItemImage *menuTop= CCMenuItemImage::create("Image/title@2x.png","Image/title@2x.png");
    menuTop->setTag(Tag_MenuTop);
    menuTop->setTarget(this, menu_selector(LWGameOverScene::pushMenu));
    
    CCMenu *mainMenu = CCMenu::create(menuTop,menuRetry,NULL);
    mainMenu->setPosition( ccp( gameBg->getContentSize().width/2, 50) );
    mainMenu->alignItemsHorizontallyWithPadding(20);
    gameBg->addChild(mainMenu,9);
    
    
////////  label
    
    if (type==2)
    {
        CCSprite *gameOverSp=CCSprite::create("Image/thistime@2x.png");
        gameOverSp->setPosition(ccp(gameBg->getContentSize().width/2,gameBg->getContentSize().height/2+280));
        gameBg->addChild(gameOverSp);
        
        CCSprite *spB=CCSprite::create("Image/thistimeboard@2x.png");
        spB->setPosition(ccp(gameBg->getContentSize().width/2,gameBg->getContentSize().height/2+180));
        gameBg->addChild(spB);
        
        CCString *numStr = CCString::createWithFormat("%.2f",LWGM::shared()->getGameCount()/100.0);
        CCLabelTTF *countLabel=CCLabelTTF::create(numStr->getCString(), "HiraKakuProN-W6", 50);
        countLabel->setString(numStr->getCString());
        countLabel->setAnchorPoint(ccp(0.5, 0.5));
        countLabel->setPosition(ccp(spB->getContentSize().width/2, spB->getContentSize().height/2));
        countLabel->setColor(ccBLACK);
        spB->addChild(countLabel, 2);

        
        if (LWGM::shared()->getGameCount()<=CCUserDefault::sharedUserDefault()->getIntegerForKey("bestPlayer1"))
        {
            CCSprite *sp=CCSprite::create("Image/newrecord@2x.png");
            sp->setPosition(ccp(gameBg->getContentSize().width/2, gameBg->getContentSize().height+20));
            gameBg->addChild(sp);
            
        }
    }
    else
    {
        CCSprite *gameOverSp=CCSprite::create("Image/gameover@2x.png");
        gameOverSp->setPosition(ccp(gameBg->getContentSize().width/2,gameBg->getContentSize().height/2+260));
        gameBg->addChild(gameOverSp);
    }
    
    CCString *numStr1 =this->getNumStr(CCUserDefault::sharedUserDefault()->getIntegerForKey("bestPlayer1"));
    CCLabelTTF *countLabel1=CCLabelTTF::create(numStr1->getCString(), "HiraKakuProN-W6", 35);
    if (CCUserDefault::sharedUserDefault()->getIntegerForKey("bestPlayer1")==99999)
    {
        numStr1 = CCString::create("--.--");
    }
    countLabel1->setString(numStr1->getCString());
    countLabel1->setAnchorPoint(ccp(1, 0.5));
    countLabel1->setPosition(ccp(boardSp->getContentSize().width/2+50, 220));
    boardSp->addChild(countLabel1, 2);
    
    
    
    CCString *numStr2 = this->getNumStr(CCUserDefault::sharedUserDefault()->getIntegerForKey("bestPlayer2"));
    if (CCUserDefault::sharedUserDefault()->getIntegerForKey("bestPlayer2")==99999)
    {
        numStr2 = CCString::create("--.--");
    }
    CCLabelTTF *countLabel2 = CCLabelTTF::create(numStr2->getCString(), "HiraKakuProN-W6", 35);
    countLabel2->setAnchorPoint(ccp(1, 0.5));
    countLabel2->setPosition(ccp(boardSp->getContentSize().width/2+50, 130));
    countLabel2->setColor(ccWHITE);
    boardSp->addChild(countLabel2, 2);
    
    CCString *numStr3 = this->getNumStr(CCUserDefault::sharedUserDefault()->getIntegerForKey("bestPlayer3"));
    if (CCUserDefault::sharedUserDefault()->getIntegerForKey("bestPlayer3")==99999)
    {
        numStr3 = CCString::create("--.--");
    }
    CCLabelTTF *countLabel3 = CCLabelTTF::create(numStr3->getCString(), "HiraKakuProN-W6", 35);
    countLabel3->setAnchorPoint(ccp(1, 0.5));
    countLabel3->setPosition(ccp(boardSp->getContentSize().width/2+50, 35));
    countLabel3->setColor(ccWHITE);
    boardSp->addChild(countLabel3, 2);
    
    countLabel1->setColor(ccBLACK);
    countLabel2->setColor(ccBLACK);
    countLabel3->setColor(ccBLACK);
    
    CCMenuItemImage *itemRank1= CCMenuItemImage::create("Image/ranking@2x.png","Image/ranking@2x.png");
    itemRank1->setTarget(this, menu_selector(LWStartScene::pushMenu));
    itemRank1->setColor(ccBLACK);
    itemRank1->setScale(0.6);
    itemRank1->setTag(Tag_rank);
    
    
    CCMenuItemImage *itemT= CCMenuItemImage::create("Image/twitter@2x.png","Image/twitter@2x.png");
    itemT->setTag(Tag_twitter);
    itemT->setColor(ccBLACK);
    itemT->setTarget(this, menu_selector(LWStartScene::pushMenu));
    itemT->setScale(0.6);
    
    CCMenu *menuRank1 = CCMenu::create(itemT,itemRank1,NULL);
    menuRank1->setPosition( ccp(SCREEN.width/2, 400) );
    menuRank1->alignItemsHorizontallyWithPadding(350);
    this->addChild(menuRank1);
    
    
    
    return true;
}
CCString *LWGameOverScene::getNumStr(int num)
{
    CCString *str;
    float numm = num/100.0;
    str = CCString::createWithFormat("%.2f",numm);
    return str;
}
LWGameOverScene::LWGameOverScene()
{

    

    
    
    

}

void LWGameOverScene::pushMenu(CCNode *sender)
{
    
    switch (sender->getTag())
    {
        case Tag_MenuRetry:
        {
//            LWAudioGM::sharedEngine()->playOnceEffect(SOUND_btn, 1);
            CCScene *scene = LWGameScene::creatGameScene();
            DIRECTOR->replaceScene(scene);
        }
            
            break;
        case Tag_MenuTop:
        {
//            LWAudioGM::sharedEngine()->playOnceEffect(SOUND_btn, 1);
            CCScene *scene = LWStartScene::creatStartScene();
            DIRECTOR->replaceScene(scene);
        }
            break;
        case Tag_shopover:
        {
//            LWAudioGM::sharedEngine()->playOnceEffect(SOUND_btn, 1);
            LWGM::shared()->setShopSign(2);
            CCScene *shopCence = LWShopScene::creatShopScene();
            DIRECTOR->pushScene(shopCence);
            
        }
            break;
        case Tag_rank:
        {
//            LWAudioGM::sharedEngine()->playOnceEffect(SOUND_btn, 1);
            AppAssitant::shareAssitant()->showLeaderBoard();

        }
            break;
        case Tag_twitter:
        {
//            LWAudioGM::sharedEngine()->playOnceEffect(SOUND_btn, 1);
//            AppAssitant::shareAssitant()->showTwitter(AppAssitant::shareAssitant()->m_count);
            
        }
            break;
            
            
            
            
            default:
            break;
    }
}




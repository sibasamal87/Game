//
//  LWStartScene.cpp
//  LWGame
//
//  Created by æ�Žè·ƒæ–‡ on 13-7-26.
//
//

#include "LWStartScene.h"
#include "LWGameScene.h"
#include "AppAssitant.h"
//#include "LWWebView.h"
#include "LWShopScene.h"
#include "LWHelpScene.h"
LWStartScene::~LWStartScene()
{
    
}

CCScene* LWStartScene::creatStartScene()
{
    CCScene *scene = CCScene::create();
    
    CCLayer* layer = new LWStartScene();
    scene->addChild(layer);
    layer->release();
    
    return scene;
}

LWStartScene::LWStartScene()
{

	this->setKeypadEnabled(true);
    if (CCUserDefault::sharedUserDefault()->getIntegerForKey("isfirstgame")==0)
    {
        if(CCUserDefault::sharedUserDefault()->getIntegerForKey("bestPlayer1")==0)
        {
            CCUserDefault::sharedUserDefault()->setIntegerForKey("bestPlayer1", 99999);
            CCUserDefault::sharedUserDefault()->setIntegerForKey("bestPlayer2", 99999);
            CCUserDefault::sharedUserDefault()->setIntegerForKey("bestPlayer3", 99999);
            CCUserDefault::sharedUserDefault()->setIntegerForKey("isfirstgame", 1);
            
        }
    }
    CCSprite *sprite;
    if (Def_IsIPod5)
    {
        sprite = CCSprite::create("Image/top1136@2x.png");
    }
    else
    {
        sprite = CCSprite::create("Image/top960@2x.png");
    }
    sprite->setPosition(CENTER);
    this->addChild(sprite);
    
    CCMenuItemImage *itemStart= CCMenuItemImage::create("Image/tap_start@2x.png","Image/tap_start@2x.png");
    itemStart->setTarget(this, menu_selector(LWStartScene::pushMenu));
    itemStart->setTag(Tag_StartGame);

    
    CCMenu *menuStart = CCMenu::create(itemStart,NULL);
    menuStart->setPosition( ccp( SCREEN.width/2, 240) );
    menuStart->alignItemsVerticallyWithPadding(20);
    this->addChild(menuStart);

    CCMenuItemImage *itemRank= CCMenuItemImage::create("Image/ranking1@2x.png","Image/ranking1@2x.png");
    itemRank->setTag(Tag_Rank);
    itemRank->setTarget(this, menu_selector(LWStartScene::pushMenu));
    
    CCMenuItemImage *itemKong= CCMenuItemImage::create("Image/recommend@2x.png","Image/recommend@2x.png");
    itemKong->setTag(Tag_kong);
    itemKong->setTarget(this, menu_selector(LWStartScene::pushMenu));
    
    CCMenu *menuRank = CCMenu::create(itemRank,itemKong,NULL);
    menuRank->setPosition( ccp( SCREEN.width/2, 150) );
    menuRank->alignItemsHorizontallyWithPadding(150);
    this->addChild(menuRank);
    
    CCMenuItemImage *itemRank1= CCMenuItemImage::create("Image/ranking@2x.png","Image/ranking@2x.png");
    itemRank1->setTag(Tag_rank1);
    itemRank1->setColor(ccBLACK);
    itemRank1->setTarget(this, menu_selector(LWStartScene::pushMenu));
    itemRank1->setScale(0.6);
    
    CCMenuItemImage *itemHelp= CCMenuItemImage::create("Image/guide@2x.png","Image/guide@2x.png");
    itemHelp->setTag(Tag_help);
//    itemHelp->setColor(ccBLACK);
    itemHelp->setTarget(this, menu_selector(LWStartScene::pushMenu));
    itemHelp->setScale(0.6);
    
    CCMenu *menuRank1 = CCMenu::create(itemRank1,itemHelp,NULL);
    menuRank1->setPosition( ccp( SCREEN.width/2, 350) );
    menuRank1->alignItemsHorizontallyWithPadding(350);
    this->addChild(menuRank1);
    
//    CCMenuItemImage *itemRank2= CCMenuItemImage::create("Image/ranking@2x.png","Image/ranking@2x.png");
//    itemRank2->setTag(Tag_Rank2);
//    itemRank2->setTarget(this, menu_selector(LWStartScene::pushMenu));
//    
//    CCMenuItemImage *itemInfo= CCMenuItemImage::create("Image/recommend@2x.png","Image/recommend@2x.png");
//    itemInfo->setTag(Tag_info);
//    itemInfo->setTarget(this, menu_selector(LWStartScene::pushMenu));
//    
//    CCMenu *menuInfo = CCMenu::create(itemRank,itemKong,NULL);
//    menuInfo->setPosition( ccp( SCREEN.width/2, 320) );
//    menuInfo->alignItemsHorizontallyWithPadding(180);
//    this->addChild(menuInfo);
    
    
    CCMenuItemImage *item_sound_on= CCMenuItemImage::create("Image/sound_on.png",NULL);
    CCMenuItemImage *item_sound_off= CCMenuItemImage::create("Image/sound_off.png",NULL);
    CCMenuItemToggle *item_toggle = CCMenuItemToggle::createWithTarget(this, menu_selector(LWStartScene::pushMenu), item_sound_on,item_sound_off,NULL);
    
    if (!CCUserDefault::sharedUserDefault()->getBoolForKey("isFirst"))
    {
        CCUserDefault::sharedUserDefault()->setBoolForKey("isMusic", true);
        CCUserDefault::sharedUserDefault()->setBoolForKey("isFirst", false);
        
    }
    
    if(CCUserDefault::sharedUserDefault()->getBoolForKey("isMusic"))
        item_toggle->setSelectedIndex(0);
    else
        item_toggle->setSelectedIndex(1);
    
    item_toggle->setTag(Tag_Music);
    
    CCSize size = CCSize(item_sound_on->getContentSize().width, item_sound_on->getContentSize().height);
    item_toggle->setContentSize(size);
    
    CCMenu *menuMusic = CCMenu::create(item_toggle,NULL);
    menuMusic->setPosition( ccp(item_toggle->getContentSize().width/2+10, SCREEN.height-400) );
    this->addChild(menuMusic);
    
    
    //ads


    
}
void LWStartScene::pushMenu(CCNode *sender)
{
    //LWWebView::showAppExTrade();
    switch (sender->getTag())
    {
        case Tag_StartGame:
        {
            
            
            this->removeAdds();
            
//            LWAudioGM::sharedEngine()->playOnceEffect(SOUND_btn, 1);
            CCScene *gameScene = LWGameScene::creatGameScene();
            DIRECTOR->replaceScene(gameScene);
            
            
        }
            break;
        case Tag_Music:
        {
//            LWAudioGM::sharedEngine()->playOnceEffect(SOUND_btn, 1);
            CCMenuItemToggle * item_toggle = (CCMenuItemToggle*)sender;
            //sound on
            if(item_toggle->getSelectedIndex()==0)
            {
                CCUserDefault::sharedUserDefault()->setBoolForKey("isMusic", true);
                LWAudioGM::sharedEngine()->setIsOnMusic(true);
            }
            else
            {
                CCUserDefault::sharedUserDefault()->setBoolForKey("isMusic", false);
                LWAudioGM::sharedEngine()->setIsOnMusic(false);
            }
            CCUserDefault::sharedUserDefault()->flush();
        }
            break;
        case  Tag_Rank:
        {
//            LWAudioGM::sharedEngine()->playOnceEffect(SOUND_btn, 1);
            AppAssitant::shareAssitant()->showLeaderBoard();
        }
            break;
        case Tag_GameFeet:
        {
            
        }
            break;
        case Tag_help:
		{
//			CCScene *gameScene = LWHelpScene::creatHelpScene();
//			DIRECTOR->replaceScene(gameScene);
		}
			break;
            
        default:
            break;
    }
    
}


void LWStartScene::removeAdds()
{
    
//    LWWebView *web = (LWWebView*)this->getChildByTag(tag_ad_top);
//    web->HideWebViewWithTag(tag_ad_top);
//
//    
//    web = (LWWebView*)this->getChildByTag(tag_ad_bottom);
//    web->HideWebViewWithTag(tag_ad_bottom);
}

void LWStartScene::keyBackClicked() {

//	Ad::shareAd()->clearApplicationCache();
//	SimpleAudioEngine::sharedEngine()->stopBackgroundMusic(true);
	CCDirector::sharedDirector()->end();

	#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
			exit(0);
	#endif

}

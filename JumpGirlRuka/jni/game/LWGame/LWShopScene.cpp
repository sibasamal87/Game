//
//  LWShopScene.cpp
//  EasterGame
//
//  Created by 李跃文 on 13-9-30.
//
//

#include "LWShopScene.h"
LWShopScene::~LWShopScene()
{
    
}
LWShopScene::LWShopScene()
{
    CCSprite *sprite;
    if (Def_IsIPod5)
    {
        sprite = CCSprite::create("Image/shop_page1136@2x.png");
    }
    else
    {
        sprite = CCSprite::create("Image/shop_page@2x.png");
    }
    sprite->setPosition(CENTER);
    this->addChild(sprite);
    
    
    
    itemShop1= CCMenuItemImage::create("Image/item_stick@2x.png","Image/item_stick@2x.png","Image/item_stick_sold@2x.png");
    itemShop1->setTag(Tag_shop1);
    itemShop1->setTarget(this, menu_selector(LWShopScene::pushMenu));
    if (CCUserDefault::sharedUserDefault()->getIntegerForKey("shop1")==0)
    {
        itemShop1->setEnabled(true);
    }
    else
    {
        itemShop1->setEnabled(false);
    }
    
    
    itemShop2= CCMenuItemImage::create("Image/item_hand@2x.png","Image/item_hand@2x.png","Image/item_hand_sold@2x.png");
    itemShop2->setTag(Tag_shop2);
    itemShop2->setTarget(this, menu_selector(LWShopScene::pushMenu));
    
    if (CCUserDefault::sharedUserDefault()->getIntegerForKey("shop2")==0)
    {
        itemShop2->setEnabled(true);
    }
    else
    {
        itemShop2->setEnabled(false);
    }
    
    
    CCMenu *menu1 = CCMenu::create(itemShop1,itemShop2,NULL);
    menu1->setPosition( ccp( SCREEN.width/2, SCREEN.height/2+130) );
    menu1->alignItemsHorizontallyWithPadding(10);
    this->addChild(menu1);
    
    
    itemShop3= CCMenuItemImage::create("Image/item_robo@2x.png","Image/item_robo@2x.png","Image/item_robo_sold@2x.png");
    itemShop3->setTag(Tag_shop3);
    itemShop3->setTarget(this, menu_selector(LWShopScene::pushMenu));
    if (CCUserDefault::sharedUserDefault()->getIntegerForKey("shop3")==0)
    {
        itemShop3->setEnabled(true);
    }
    else
    {
        itemShop3->setEnabled(false);
    }
    
    
    itemShop4= CCMenuItemImage::create("Image/item_belt@2x.png","Image/item_belt@2x.png","Image/item_belt_sold@2x.png");
    itemShop4->setTag(Tag_shop4);
    itemShop4->setTarget(this, menu_selector(LWShopScene::pushMenu));
    if (CCUserDefault::sharedUserDefault()->getIntegerForKey("shop4")==0)
    {
        itemShop4->setEnabled(true);
    }
    else
    {
        itemShop4->setEnabled(false);
    }
    
    
    CCMenu *menu2 = CCMenu::create(itemShop3,itemShop4,NULL);
    menu2->setPosition( ccp( SCREEN.width/2, SCREEN.height/2-135) );
    menu2->alignItemsHorizontallyWithPadding(10);
    this->addChild(menu2);
    
    CCMenuItemImage *menuBack= CCMenuItemImage::create("Image/back@2x.png","Image/back@2x.png");
    menuBack->setTag(Tag_back);
    menuBack->setTarget(this, menu_selector(LWShopScene::pushMenu));
    
    CCMenu *mainMenu = CCMenu::create(menuBack,NULL);
    mainMenu->setPosition(ccp( SCREEN.width/2, SCREEN.width/2-170));
    mainMenu->alignItemsHorizontallyWithPadding(20);
    this->addChild(mainMenu,9);
    
    
    
    CCSprite *shopCountSp=CCSprite::create("Image/point@2x.png");
    shopCountSp->setPosition(ccp(CENTER.x, CENTER.y+320));
    this->addChild(shopCountSp);
    
    int candyCount= CCUserDefault::sharedUserDefault()->getIntegerForKey("candyCount");
    CCString *candyStr=CCString::createWithFormat("%d",candyCount);
    candyTb=CCLabelTTF::create(candyStr->getCString(), "HiraKakuProN-W6", 40);
    candyTb->setAnchorPoint(ccp(1, 0.5));
    candyTb->setPosition(ccp(shopCountSp->getContentSize().width-20, shopCountSp->getContentSize().height/2-12));
    shopCountSp->addChild(candyTb);
    if (LWGM::shared()->sysVerson()>=7)
    {
        candyTb->setPosition(ccp(shopCountSp->getContentSize().width-20, shopCountSp->getContentSize().height/2));
    }
    LWGM::shared()->m_shop=this;
}
void LWShopScene::addAds()
{
}
CCScene* LWShopScene::creatShopScene()
{
    CCScene *scene = CCScene::create();
    
    CCLayer* layer = new LWShopScene();
    scene->addChild(layer);
    layer->autorelease();
    
    return scene;
}

void LWShopScene::buyItem(int type)
{
    
}
void LWShopScene::reflesh()
{
    if (CCUserDefault::sharedUserDefault()->getIntegerForKey("shop1")==0)
    {
        itemShop1->setEnabled(true);
    }
    else
    {
        itemShop1->setEnabled(false);
    }
    if (CCUserDefault::sharedUserDefault()->getIntegerForKey("shop2")==0)
    {
        itemShop2->setEnabled(true);
    }
    else
    {
        itemShop2->setEnabled(false);
    }
    if (CCUserDefault::sharedUserDefault()->getIntegerForKey("shop3")==0)
    {
        itemShop3->setEnabled(true);
    }
    else
    {
        itemShop3->setEnabled(false);
    }
    if (CCUserDefault::sharedUserDefault()->getIntegerForKey("shop4")==0)
    {
        itemShop4->setEnabled(true);
    }
    else
    {
        itemShop4->setEnabled(false);
    }
    int candyCount= CCUserDefault::sharedUserDefault()->getIntegerForKey("candyCount");
    CCString *candyStr=CCString::createWithFormat("%d",candyCount);
    candyTb->setString(candyStr->getCString());
}
void LWShopScene::pushMenu(CCNode *sender)
{
//    LWAudioGM::sharedEngine()->playOnceEffect(SOUND_btn, 1);
    int candyCount= CCUserDefault::sharedUserDefault()->getIntegerForKey("candyCount");
    switch (sender->getTag())
    {
        case Tag_back:
        {
            
            if (LWGM::shared()->getShopSign()==1)
            {
                CCScene *start=LWStartScene::creatStartScene();
                DIRECTOR->replaceScene(start);
            }
            else
            {
                DIRECTOR->popScene();
            }
            
        }
            break;
        case Tag_shop1:
        {
            if (Price_Item1>candyCount)
            {
                LWGM::shared()->noMoney();
            }
            else
            {
               LWGM::shared()->buyItem(1); 
            }
            
        }
            break;
        case Tag_shop2:
        {
            if (Price_Item2>candyCount)
            {
                LWGM::shared()->noMoney();
            }
            else
            {
                LWGM::shared()->buyItem(2);
            }
        }
            break;
        case Tag_shop3:
        {
            if (Price_Item3>candyCount)
            {
                LWGM::shared()->noMoney();
            }
            else
            {
                LWGM::shared()->buyItem(3);
            }
        }
            break;
        case Tag_shop4:
        {
            if (Price_Item4>candyCount)
            {
                LWGM::shared()->noMoney();
            }
            else
            {
                LWGM::shared()->buyItem(4);
            }
        }
            break;
            
            
        default:
        break;
    }
    
}











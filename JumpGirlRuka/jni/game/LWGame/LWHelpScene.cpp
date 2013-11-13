//
//  LWHelpScene.cpp
//  EasterGame
//
//  Created by 李跃文 on 13-9-30.
//
//

#include "LWHelpScene.h"
LWHelpScene::~LWHelpScene()
{
    
}
LWHelpScene::LWHelpScene()
{
    CCSprite *sprite;
    if (Def_IsIPod5)
    {
        sprite = CCSprite::create("Image/howto1136@2x.png");
    }
    else
    {
        sprite = CCSprite::create("Image/howto@2x.png");
    }
    sprite->setPosition(CENTER);
    this->addChild(sprite);
    
    CCMenuItemImage *menuBack= CCMenuItemImage::create("Image/back@2x.png","Image/back@2x.png");
    menuBack->setTag(Tag_backTop);
    menuBack->setTarget(this, menu_selector(LWHelpScene::pushMenu));
    
    CCMenu *mainMenu = CCMenu::create(menuBack,NULL);
    mainMenu->setPosition(ccp( SCREEN.width/2, SCREEN.width/2-200));
    mainMenu->alignItemsHorizontallyWithPadding(20);
    this->addChild(mainMenu,9);

}

CCScene* LWHelpScene::creatHelpScene()
{
    CCScene *scene = CCScene::create();
    
    CCLayer* layer = new LWHelpScene();
    scene->addChild(layer);
    layer->autorelease();
    
    return scene;
}


void LWHelpScene::pushMenu(CCNode *sender)
{
    switch (sender->getTag())
    {
        case Tag_backTop:
        {
//            LWAudioGM::sharedEngine()->playOnceEffect(SOUND_btn, 1);
            CCScene *start=LWStartScene::creatStartScene();
            DIRECTOR->replaceScene(start);
        }
            break;

        default:
        break;
    }
    
}











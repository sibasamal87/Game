
#include "LWGameScene.h"
#include "LWStartScene.h"
#include "LWGM.h"
#include "AppAssitant.h"
//#include "LWWebView.h"
//#include "stdcheaders.h"

LWGameScene::~LWGameScene()
{
    CC_SAFE_RELEASE(m_worldLayer);
    CC_SAFE_RELEASE(m_worldLayer2);
    m_signArray->removeAllObjects();
    CC_SAFE_RELEASE(m_signArray);
    LWGM::shared()->m_gameScene=NULL;

}


CCScene* LWGameScene::creatGameScene()
{
    CCScene *scene = CCScene::create();
    
    CCLayer* layer = new LWGameScene();
    scene->addChild(layer);
    layer->autorelease();
    
    return scene;
}

void LWGameScene::gameStartLayer()
{
    LWGM::shared()->m_isStartLayer=true;
    LWAudioGM::sharedEngine()->playOnceEffect(SOUND_3_0_01, 1);
    CCSprite *sprite;
    if (Def_IsIPod5)
    {
        sprite = CCSprite::create("Image/play1136@2x.png");
    }
    else
    {
        sprite = CCSprite::create("Image/play960@2x.png");
    }
    
    sprite->setPosition(CENTER);
    this->addChild(sprite,99);
    sprite->setTag(9987);
    
    m_pauseMenu->setTouchEnabled(false);
    m_mainMenu->setTouchEnabled(false);
    CCSize s = CCDirector::sharedDirector()->getWinSize();
    CCSprite *sp_numbering = CCSprite::create("Image/start3@2x.png");
    // sprite->autorelease();
    sp_numbering->setTag(100);
    sp_numbering->setPosition( ccp( s.width/2, s.height/2-260) );
    this->addChild(sp_numbering,99);
    
    
    //animation
    
    CCTexture2D *texture0 = CCTextureCache::sharedTextureCache()->addImage("Image/start3@2x.png");
    CCRect size = CCRect(0, 0, texture0->getContentSize().width, texture0->getContentSize().height);
    CCSpriteFrame *frame0 = CCSpriteFrame::createWithTexture(texture0, size);
    
    CCTexture2D *texture1 = CCTextureCache::sharedTextureCache()->addImage("Image/start2@2x.png");
    
    CCSpriteFrame *frame1 = CCSpriteFrame::createWithTexture(texture1, size);
    
    CCTexture2D *texture2 = CCTextureCache::sharedTextureCache()->addImage("Image/start1@2x.png");
    
    CCSpriteFrame *frame2 = CCSpriteFrame::createWithTexture(texture2, size);
    
    
    CCArray *array_frames = CCArray::create(frame0,frame1,frame2,NULL);
    
    CCAnimation *animation = CCAnimation::createWithSpriteFrames(array_frames);
    
    animation->setLoops(1);
    animation->setDelayPerUnit(1.0);
    CCAnimate *animate = CCAnimate::create(animation);
    
    CCCallFunc *func = CCCallFunc::create(this, callfunc_selector(LWGameScene::startGame));
    
    CCSequence *se = CCSequence::create(animate,func,NULL);
    
    sp_numbering->runAction(se);

    
}

void LWGameScene::addCloud()
{
    CCSprite *cloudSp=CCSprite::create("Image/background_cloud@2x.png");
    cloudSp->setAnchorPoint(ccp(0, 0));
    cloudSp->setPosition(ccp(-200, CENTER.y+50));
    this->addChild(cloudSp,1);
    CCMoveTo *move1=CCMoveTo::create(7, ccp(640, CENTER.y+50));
    CCMoveTo *move2=CCMoveTo::create(7, ccp(-200, CENTER.y+50));
    CCSequence *seq=CCSequence::create(move1,CCDelayTime::create(2),move2,CCDelayTime::create(2),NULL);
    CCRepeatForever *rep=CCRepeatForever::create(seq);
    cloudSp->runAction(rep);
    
}
void LWGameScene::startGame()
{
    m_pauseMenu->setTouchEnabled(true);
    m_mainMenu->setTouchEnabled(true);
    DIRECTOR->resume();
    this->removeChildByTag(9987);
    this->removeChildByTag(100);
//    this->schedule(schedule_selector(LWGameScene::refresh));
    this->schedule(schedule_selector(LWGameScene::timeAdd),1/100.0);
    LWAudioGM::sharedEngine()->playOnceEffect(SOUND_ikimaasu_01, 1);
    LWAudioGM::sharedEngine()->playBackgroundMd(SOUND_011, 1);
    LWGM::shared()->m_isStartLayer=false;
}


LWGameScene::LWGameScene()
{
    
//    {
//        LWWebView *webView_bottom= (LWWebView *)LWWebView::create();
//        CCRect rect = CCRect(0, SCREEN.height-100, SCREEN.width, 100);
//        webView_bottom->setTag(Tag_ad);
//        webView_bottom->addAdstirWebView("MEDIA-2d9d0c2b","1", rect);
//        this->addChild(webView_bottom);
//    }
    m_signArray=new CCArray();
    m_signArray->init();
    isCanMove=true;
    m_direction=1;
    m_count=0;
    m_jumpTime=0;
    m_gameTime=0;
    m_lenth=0;
    m_count=0;
    
    CCSprite *sprite;
    if (Def_IsIPod5)
    {
        sprite = CCSprite::create("Image/background_1136@2x.png");
    }
    else
    {
        sprite = CCSprite::create("Image/background_960@2x.png");
    }
    
    sprite->setPosition(CENTER);
    this->addChild(sprite);
    
    m_worldLayer = new CCLayer();
    this->addChild(m_worldLayer,3);
    m_worldLayer2 = new CCLayer();
    this->addChild(m_worldLayer2,2);
    
    CCMenuItemImage *menuItem1= CCMenuItemImage::create("Image/red@2x.png","Image/red@2x.png");
    menuItem1->setTag(Tag_item1);
    menuItem1->setTarget(this, menu_selector(LWGameScene::pushMenuJump));
    
    CCMenuItemImage *menuItem2= CCMenuItemImage::create("Image/blue@2x.png","Image/blue@2x.png");
    menuItem2->setTag(Tag_item2);
    menuItem2->setTarget(this, menu_selector(LWGameScene::pushMenuJump));
    
    CCMenuItemImage *menuItem3= CCMenuItemImage::create("Image/green@2x.png","Image/green@2x.png");
    menuItem3->setTag(Tag_item3);
    menuItem3->setTarget(this, menu_selector(LWGameScene::pushMenuJump));
    
    CCMenuItemImage *menuItem4= CCMenuItemImage::create("Image/yellow@2x.png","Image/yellow@2x.png");
    menuItem4->setTag(Tag_item4);
    menuItem4->setTarget(this, menu_selector(LWGameScene::pushMenuJump));
    
    m_mainMenu = CCMenu::create(menuItem1,menuItem2,menuItem3,menuItem4,NULL);
    m_mainMenu->setPosition(ccp(CENTER.x, 144));
//    m_mainMenu->alignItemsVerticallyWithPadding(40);
    m_mainMenu->alignItemsHorizontallyWithPadding(1);
    this->addChild(m_mainMenu,9);
    this->addMap();
    
    CCMenuItemImage *menuCenter= CCMenuItemImage::create("Image/stop@2x.png","Image/stop@2x.png");
    menuCenter->setTag(Tag_MenuPause);
    menuCenter->setAnchorPoint(ccp(0, 1));
    menuCenter->setTarget(this, menu_selector(LWGameScene::pushMenu));
    m_pauseMenu = CCMenu::create(menuCenter,NULL);
    m_pauseMenu->setPosition( ccp( 20, SCREEN.height-20));
    this->addChild(m_pauseMenu,9);
    
    CCSprite *timeSp=CCSprite::create("Image/time_background@2x.png");
    timeSp->setAnchorPoint(ccp(1, 1));
    timeSp->setPosition(ccp(SCREEN.width-10, SCREEN.height-20));
    this->addChild(timeSp, 9);
    
    m_countLb=CCLabelTTF::create("", "HiraKakuProN-W6", 30);
    m_countLb->setAnchorPoint(ccp(1, 0.5));
    m_countLb->setColor(ccBLACK);
    m_countLb->setPosition(ccp(timeSp->getContentSize().width-10, timeSp->getContentSize().height/2-6));
    timeSp->addChild(m_countLb);
    
    
    LWGM::shared()->m_gameScene=this;
    this->addCloud();
    this->gameStartLayer();
    
    
}
void LWGameScene::setNumLabel(int num)
{
    CCString *str;
    
    float numm = num/100.0;
    str = CCString::createWithFormat("%.2f",numm);
    m_countLb->setString(str->getCString());
}
std::string LWGameScene::getLeftBalcony()
{
    std::string nameStr;
    int type=arc4random()%3;
    CCString *typeStr=CCString::create("");
    switch (type)
    {
        case 0:
            nameStr="Image/vera_r_left@2x.png";
            typeStr->m_sString="type1";
            break;
        case 1:
            nameStr="Image/vera_b_left@2x.png";
            typeStr->m_sString="type2";
            break;
        case 2:
            nameStr="Image/vera_g_left@2x.png";
            typeStr->m_sString="type3";
            break;
        case 3:
            nameStr="Image/vera_y_left@2x.png";
            typeStr->m_sString="type4";
            break;
            
        default:
            break;
    }
    m_signArray->addObject(typeStr);
    return nameStr;
    
}
std::string LWGameScene::getRightBalcony()
{
    std::string nameStr;
    int type=arc4random()%4;
    CCString *typeStr=CCString::create("");
    switch (type)
    {
        case 0:
            nameStr="Image/vera_r_right@2x.png";
            typeStr->m_sString="type1";
            break;
        case 1:
            nameStr="Image/vera_b_right@2x.png";
            typeStr->m_sString="type2";
            break;
        case 2:
            nameStr="Image/vera_g_right@2x.png";
            typeStr->m_sString="type3";
            break;
        case 3:
            nameStr="Image/vera_y_right@2x.png";
            typeStr->m_sString="type4";
            break;
            
        default:
            break;
    }
    m_signArray->addObject(typeStr);
    return nameStr;
}
void LWGameScene::addMap()
{
    CCSprite *startSp=CCSprite::create("Image/start_p@2x.png");
    startSp->setAnchorPoint(ccp(0, 0));
    startSp->setPosition(ccp(0, 100));
    m_worldLayer->addChild(startSp,2);
    for (int i=1; i<=50; i++)
    {
        CCSprite *houseSp1=CCSprite::create("Image/wall_left@2x.png");
        houseSp1->setAnchorPoint(ccp(0, 0));
        houseSp1->setPosition(ccp(0, (i-1)*houseSp1->getContentSize().height+190));
        m_worldLayer->addChild(houseSp1,2);
        
        
        CCSprite *houseSp2=CCSprite::create("Image/wall_right@2x.png");
        houseSp2->setAnchorPoint(ccp(1, 0));
        houseSp2->setPosition(ccp(SCREEN.width, (i-1)*houseSp2->getContentSize().height+190));
        m_worldLayer->addChild(houseSp2,2);
        houseSp1->setTag(1000+i);
        houseSp2->setTag(2000+i);
        if(this->judge_number(i)&&i!=1)
        {
            std::string nameStr=this->getLeftBalcony();
            CCSprite *balconySp=CCSprite::create(nameStr.c_str());
            balconySp->setAnchorPoint(ccp(0, 0));
            balconySp->setPosition(ccp(houseSp1->getContentSize().width, 0));
            houseSp1->addChild(balconySp);
            if (i==5)
            {
                m_cat=LWGameRole::creatRoleWithType(2);
                m_cat->setPosition(ccp(balconySp->getContentSize().width/2, balconySp->getContentSize().height+20));
                balconySp->addChild(m_cat);
                
            }
        }
        else if(!this->judge_number(i)&&i!=1)
        {
            std::string nameStr=this->getRightBalcony();
            CCSprite *balconySp=CCSprite::create(nameStr.c_str());
            balconySp->setAnchorPoint(ccp(1, 0));
            balconySp->setPosition(ccp(0, 0));
            houseSp2->addChild(balconySp);
            if (i==10)
            {
                m_cow=LWGameRole::creatRoleWithType(3);
                m_cow->setPosition(ccp(balconySp->getContentSize().width/2, balconySp->getContentSize().height+20));
                balconySp->addChild(m_cow);
                m_cow->setFlipX(true);
                
            }
        }
        
    }
    CCSprite *sp=(CCSprite *)m_worldLayer->getChildByTag(1050);
    
    CCSprite *leftBuilding=CCSprite::create("Image/background_buil_left@2x.png");
    leftBuilding->setAnchorPoint(ccp(0, 0));
    leftBuilding->setPosition(ccp(0, 190));
    m_worldLayer2->addChild(leftBuilding);
    
    CCSprite *rightBuilding=CCSprite::create("Image/background_buil_right@2x.png");
    rightBuilding->setAnchorPoint(ccp(1, 0));
    rightBuilding->setPosition(ccp(SCREEN.width, 190));
    m_worldLayer2->addChild(rightBuilding);
    
    CCSprite *goalSp=CCSprite::create("Image/goal_p@2x.png");
    goalSp->setAnchorPoint(ccp(0.5, 0));
    goalSp->setPosition(ccp(CENTER.x, sp->getPositionY()+sp->getContentSize().height));
    m_worldLayer->addChild(goalSp);
    
    m_girl=LWGameRole::creatRoleWithType(1);
    m_girl->setPosition(ccp(200,340));
    m_worldLayer->addChild(m_girl,3);

    
}
int LWGameScene::judge_number(int i_val)
{
    if (i_val&1)
        return 1;//å¥‡æ•°
    else
        return 0;//å�¶æ•°
}


void LWGameScene::gamePause()
{
    LWAudioGM::sharedEngine()->stopBackgroundMd();
    LWGM::shared()->m_isPause=true;
    m_mainMenu->setTouchEnabled(false);
    LWAudioGM::sharedEngine()->stopBackgroundMd();
    m_pauseMenu->setTouchEnabled(false);
    this->unschedule(schedule_selector(LWGameScene::refresh));
    DIRECTOR->pause();
    CCSprite *m_pauseSprite;
    if (Def_IsIPod5)
    {
        m_pauseSprite=CCSprite::create("Image/stop_bg.png");
    }
    else
    {
        m_pauseSprite=CCSprite::create("Image/stop_bg.png");
    }
    m_pauseSprite->setPosition(CENTER);
    m_pauseSprite->setTag(76);
    this->addChild(m_pauseSprite, 10);
    
    
    
    CCMenuItemImage *menuBackGame= CCMenuItemImage::create("Image/backgame.png","Image/backgame.png");
    menuBackGame->setTag(Tag_MenuBackGame);
    menuBackGame->setTarget(this, menu_selector(LWGameScene::pushMenu));
    
    CCMenuItemImage *menuBackStart= CCMenuItemImage::create("Image/backtitle.png","Image/backtitle.png");
    menuBackStart->setTag(Tag_MenuBackStart);
    menuBackStart->setTarget(this, menu_selector(LWGameScene::pushMenu));
    
    
    CCMenu *menu = CCMenu::create(menuBackGame,menuBackStart,NULL);
    menu->setPosition( ccp( m_pauseSprite->getContentSize().width/2, m_pauseSprite->getContentSize().height/2-88) );
    menu->alignItemsVerticallyWithPadding(10);
    m_pauseSprite->addChild(menu,9);
    
    
    
    
    
}


void LWGameScene::removeNode(CCNode *node)
{
    node->removeFromParentAndCleanup(true);
}


void LWGameScene::refresh()
{

    
    
}
void LWGameScene::mapMove()
{
    isCanMove=false;
    CCMoveTo *move = CCMoveTo::create(PlayerJumpTime, ccp(m_worldLayer->getPositionX(), m_worldLayer->getPositionY()-200));
    CCCallFunc *call=CCCallFunc::create(this, callfunc_selector(LWGameScene::mapMovedone));
    CCSequence *seq=CCSequence::create(move,call,NULL);
    m_worldLayer->runAction(seq);
    CCMoveTo *move2 = CCMoveTo::create(PlayerJumpTime, ccp(m_worldLayer2->getPositionX(), m_worldLayer2->getPositionY()-50));
    m_worldLayer2->runAction(move2);
}
void LWGameScene::mapMovedone()
{
    isCanMove=true;
}
void LWGameScene::pushMenuJump(CCNode *sender)
{
    if (isCanMove)
    {
        
        m_count++;
        if (m_count==4)
        {
            m_cat->setImageS();
        }
        else
        {
            m_cat->setImageN();
        }
        
        if (m_count==9)
        {
            m_cow->setImageS();
        }
        else
        {
            m_cow->setImageN();
        }
        CCString *str=CCString::create("");
        if (sender->getTag()==Tag_item1)
        {
            str->m_sString="type1";
        }
        else if (sender->getTag()==Tag_item2)
        {
            str->m_sString="type2";
        }
        else if (sender->getTag()==Tag_item3)
        {
            str->m_sString="type3";
        }
        else if (sender->getTag()==Tag_item4)
        {
            str->m_sString="type4";
        }
//        CCLog("m_jumpTime=%d",m_jumpTime);
        if (m_jumpTime<40)
        {
            m_girl->setJumpType(2);
        }
        else
        {
            m_girl->setJumpType(1);
        }
        
        m_jumpTime=0;
        if (m_count!=50)
        {
            CCString *strSign=(CCString *)m_signArray->objectAtIndex(m_count-1);
            std::string stringSign=strSign->m_sString;
            if (str->m_sString==stringSign)
            {
                m_girl->setIsEnbleBeat(true);
            }
            else
            {
                m_girl->setIsEnbleBeat(false);
            }
//            m_girl->girlJump(m_direction);
            if (m_count==49)
            {
                m_girl->girlJump(m_direction);
                CCCallFunc *call=CCCallFunc::create(this, callfunc_selector(LWGameScene::lastJump));
                CCSequence *seq=CCSequence::create(CCDelayTime::create(0.6),call,NULL);
                this->runAction(seq);
            }
            else
            {
                m_girl->girlJump(m_direction);
            }
            
        }
        else
        {
             //m_girl->girlJump(3);
        }
        
        this->mapMove();
        if (m_direction==1)
        {
            m_direction=2;
        }
        else if(m_direction==2)
        {
            m_direction=1;
        }
    }
    
}
void LWGameScene::lastJump()
{
    m_girl->girlJump(3);
}
void LWGameScene::timeAdd()
{
    m_jumpTime++;
    m_gameTime++;
    this->setNumLabel(m_gameTime);
}
void LWGameScene::pushMenu(CCNode *sender)
{
//    LWAudioGM::sharedEngine()->playOnceEffect(SOUND_btn, 1);
    switch (sender->getTag())
    {
            case Tag_MenuPause:
        {
            this->gamePause();
        }
            break;
        case Tag_MenuBackGame:
        {
            this->gameResum();
        }
            break;
        case Tag_MenuBackStart:
        {
            CCScene *scene = LWStartScene::creatStartScene();
            DIRECTOR->replaceScene(scene);
            DIRECTOR->resume();
        }
            break;
        case Tag_MenuGameStart:
        {
            this->startGame();
        }
            break;
        default:
            break;
            
    }
}
void LWGameScene::win()
{
    LWGM::shared()->setGameCount(m_gameTime);
    //ä¿�å­˜æœ€é«˜åˆ†
    this->unschedule(schedule_selector(LWGameScene::timeAdd));
    int s1 = CCUserDefault::sharedUserDefault()->getIntegerForKey("bestPlayer1");
    int s2 = CCUserDefault::sharedUserDefault()->getIntegerForKey("bestPlayer2");
    int s3 = CCUserDefault::sharedUserDefault()->getIntegerForKey("bestPlayer3");
    if(LWGM::shared()->getGameCount()<s1)
    {
        float fen = LWGM::shared()->getGameCount()/100;
//        AppAssitant::shareAssitant()->reportScore(fen);
        CCUserDefault::sharedUserDefault()->setIntegerForKey("bestPlayer3", CCUserDefault::sharedUserDefault()->getIntegerForKey("bestPlayer2"));
        CCUserDefault::sharedUserDefault()->setIntegerForKey("bestPlayer2", CCUserDefault::sharedUserDefault()->getIntegerForKey("bestPlayer1"));
        CCUserDefault::sharedUserDefault()->setIntegerForKey("bestPlayer1", LWGM::shared()->getGameCount());
        CCUserDefault::sharedUserDefault()->flush();
    }
    else if(LWGM::shared()->getGameCount()<s2&&LWGM::shared()->getGameCount()>s1)
    {
        CCUserDefault::sharedUserDefault()->setIntegerForKey("bestPlayer3", CCUserDefault::sharedUserDefault()->getIntegerForKey("bestPlayer2"));
        CCUserDefault::sharedUserDefault()->setIntegerForKey("bestPlayer2", LWGM::shared()->getGameCount());
        CCUserDefault::sharedUserDefault()->flush();
    }
    else if(LWGM::shared()->getGameCount()<s3&&LWGM::shared()->getGameCount()>s2)
    {
        CCUserDefault::sharedUserDefault()->setIntegerForKey("bestPlayer3", LWGM::shared()->getGameCount());
        CCUserDefault::sharedUserDefault()->flush();
    }
    this->gameOver(2);
}
void LWGameScene::gameOver(int type)
{
    m_gameOverType=type;
    if (m_gameOverType==1)
    {
        LWAudioGM::sharedEngine()->playOnceEffect(SOUND_aaa_01, 1);
    }
//    LWGM::shared()->setGameCount(m_gameTime);
    m_mainMenu->setTouchEnabled(false);
    
    LWAudioGM::sharedEngine()->stopBackgroundMd();
    this->unschedule(schedule_selector(LWGameScene::timeAdd));
    
    //DIRECTOR->pause();
    CCCallFunc *call=CCCallFunc::create(this,callfunc_selector(LWGameScene::gameOverReplace));
    CCSequence *seq=CCSequence::create(CCDelayTime::create(0.4),call,NULL);
    this->runAction(seq);
    
}
void LWGameScene::gameOverReplace()
{
    CCScene *scene= LWGameOverScene::creatGameOverScene(m_gameOverType);
    DIRECTOR->replaceScene(scene);
    
}
void LWGameScene::gameResum()
{
    LWAudioGM::sharedEngine()->playBackgroundMd(SOUND_011, 1);
    LWGM::shared()->m_isPause=false;
    this->schedule(schedule_selector(LWGameScene::update));
    DIRECTOR->resume();
    m_pauseMenu->setTouchEnabled(true);
    m_mainMenu->setTouchEnabled(true);
    CCSprite *m_pauseSprite=(CCSprite *)this->getChildByTag(76);
    m_pauseSprite->removeFromParentAndCleanup(true);
    this->schedule(schedule_selector(LWGameScene::refresh));
}



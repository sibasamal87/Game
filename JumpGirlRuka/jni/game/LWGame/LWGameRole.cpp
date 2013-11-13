//
//  LWGameRole.cpp
//  BraveGame
//
//  Created by 李跃文 on 13-8-3.
//
//

#include "LWGameRole.h"
#include "LWAudioGM.h"
#include "LWGameScene.h"
LWGameRole::~LWGameRole()
{
    
}
LWGameRole::LWGameRole()
{
    m_HP=0;
    m_isEnbleBeat=true;
    m_PlayerAtteak=false;
    m_jumpType=1;

}

LWGameRole* LWGameRole::creatRoleWithName(const char *pszFileName)
{
    LWGameRole *role = new LWGameRole();
    if (role&&role->initWithName(pszFileName))
    {
        role->autorelease();
        return role;
    }
    CC_SAFE_DELETE(role);
    return NULL;
}
bool LWGameRole::initWithName(const char *pszFileName)
{
    this->initWithFile(pszFileName);
    m_roleType=tNpcBoss;
    return true;
}

LWGameRole* LWGameRole::creatRoleWithType(int type)
{

    LWGameRole *role = new LWGameRole();
    if (role&&role->initWithType(type))
    {
        role->autorelease();
        return role;
    }
    CC_SAFE_DELETE(role);
    return NULL;

    
}
bool LWGameRole::initWithType(int type)
{
    m_roleType=type;
    m_soundJump1=1;
    m_soundJump2=1;
    this->setAnchorPoint(ccp(0.5,0));
    switch (type)
    {
        case 1:
        {
            this->initWithFile("Image/character_right_a@2x.png");
        }
            break;
        case 2:
        {
            this->initWithFile("Image/cat_left@2x.png");
        }
            break;
        case 3:
        {
            this->initWithFile("Image/crow_left@2x.png");
        }
            break;
        case 4:
        {
            this->initWithFile("Image/character_sub3_1@2x.png");
        }
            break;
        case 5:
        {
            this->initWithFile("Image/enemy_1@2x.png");
        }
            break;

            default:
            break;
    }
    return true;
}
void LWGameRole::setImageN()
{
    if (m_roleType==2)
    {
        CCSprite *sp=CCSprite::create("Image/cat_left@2x.png");
        this->setTexture(sp->getTexture());
    }
    else if (m_roleType==3)
    {
        CCSprite *sp=CCSprite::create("Image/crow_left@2x.png");
        this->setTexture(sp->getTexture());
    }
}
void LWGameRole::setImageS()
{
    if (m_roleType==2)
    {
        CCSprite *sp=CCSprite::create("Image/cat_s_left@2x.png");
        this->setTexture(sp->getTexture());
    }
    else if (m_roleType==3)
    {
        CCSprite *sp=CCSprite::create("Image/crow_s_left@2x.png");
        this->setTexture(sp->getTexture());
    }
}


void LWGameRole::girlJump(int direction)
{
    m_direction=direction;
    float hei=200;
    CCPoint endPoint=CCPointMake(this->getPositionX()+240, this->getPositionY()+hei);
    if (direction==1)
    {
        endPoint=CCPointMake(this->getPositionX()+240, this->getPositionY()+hei);
    }
    else if(direction==2)
    {
        endPoint=CCPointMake(this->getPositionX()-240, this->getPositionY()+hei);
    }
    else if(direction==3)
    {
        endPoint=CCPointMake(CENTER.x, this->getPositionY()+142);
    }
    ccBezierConfig bezierCon;
    bezierCon.controlPoint_1=this->getPosition();//控制点1
    bezierCon.controlPoint_2=CCPointMake((this->getPositionX()+endPoint.x)/2, this->getPositionY()+270);//控制点2
    if(direction==3)
    {
        bezierCon.controlPoint_2=CCPointMake((this->getPositionX()+endPoint.x)/2, this->getPositionY()+700);
    }
    bezierCon.endPosition =endPoint;// 结束位置
    CCActionInterval * action = CCBezierTo::create(PlayerJumpTime, bezierCon);
    
    CCAnimation* bulletanimation = CCAnimation::create();
    
    bulletanimation -> setRestoreOriginalFrame(true);
    if (m_jumpType==1)
    {
        m_soundJump2=1;
        if (m_soundJump1==1)
        {
            LWAudioGM::sharedEngine()->playOnceEffect(SOUND_yo_02, 1);
            m_soundJump1=2;
        }
        else
        {
            LWAudioGM::sharedEngine()->playOnceEffect(SOUND_ho_02, 1);
            m_soundJump1=1;
        }
        bulletanimation -> setDelayPerUnit(PlayerJumpTime/1);
        for (int i=1; i<=1; i++)
        {
            CCString* frameName = CCString::createWithFormat("Image/character_right_j0%d@2x.png",i);
            bulletanimation->addSpriteFrameWithFileName(frameName->getCString());
        }
    }
    else
    {
        m_soundJump1=1;
        if (m_soundJump2==1)
        {
            LWAudioGM::sharedEngine()->playOnceEffect(SOUND_kyahhoo_01, 1);
            m_soundJump2=2;
        }
        else
        {
            LWAudioGM::sharedEngine()->playOnceEffect(SOUND_yeah_04, 1);
            m_soundJump2=1;
        }
        bulletanimation -> setDelayPerUnit(PlayerJumpTime/9);
        for (int i=1; i<=9; i++)
        {
            CCString* frameName = CCString::createWithFormat("Image/character_right_j0%d@2x.png",i);
            bulletanimation->addSpriteFrameWithFileName(frameName->getCString());
        }
    }
    
    CCAnimate *animate = CCAnimate::create(bulletanimation);
    CCSpawn *spa=CCSpawn::create(action,animate,NULL);
    CCCallFunc *call=CCCallFunc::create(this, callfunc_selector(LWGameRole::setFlipXCall));
    CCSequence *seq=CCSequence::create(spa,call,NULL);
    
    this->runAction(seq);
}
void LWGameRole::setFlipXCall()
{
    if (m_direction==1)
    {
      this->setFlipX(true);
    }
    else if(m_direction==2)
    {
      this->setFlipX(false);
    }
    else if (m_direction==3)
    {
        LWAudioGM::sharedEngine()->playOnceEffect(SOUND_yattane_01, 1);
        this->setFlipX(false);
        CCSprite *sp=CCSprite::create("Image/character_goal@2x.png");
        this->setTexture(sp->getTexture());
        LWGameScene *ss=(LWGameScene *)LWGM::shared()->m_gameScene;
        ss->win();
    }
    if (!this->getIsEnbleBeat())
    {
        LWAudioGM::sharedEngine()->playOnceEffect(SOUND_kyaa_02, 1);
        CCSprite *sp=CCSprite::create("Image/character_right_miss@2x.png");
        this->setTexture(sp->getTexture());
        LWGameScene *ss=(LWGameScene *)LWGM::shared()->m_gameScene;
        ss->gameOver(1);
    }
    
}

void LWGameRole::playSound()
{
    
}

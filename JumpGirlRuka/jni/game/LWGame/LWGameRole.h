//
//  LWGameRole.h
//  BraveGame
//
//  Created by 李跃文 on 13-8-3.
//
//

#ifndef __BraveGame__LWGameRole__
#define __BraveGame__LWGameRole__

#include <iostream>
#include "LWConfig.h"
#define npcTime 1
#define npcTimeStone 0.3
typedef enum
{
    tPlayer,
    tNPC1,
    tNPC2,
    tNPC3,
    tNPC4,
    tCandy,
    tNpcBoss,
    tNpcStone,
    tNpcFlower,
    tNpcCi,
    tNpcSoldier
    
}tRoleType;
class LWGameRole: public CCSprite
{
public:
    ~LWGameRole();
    LWGameRole();
    CC_SYNTHESIZE(float, m_HP, HP);
    CC_SYNTHESIZE(bool, m_isEnbleBeat, IsEnbleBeat);
    CC_SYNTHESIZE(bool, m_PlayerAtteak, PlayerAtteak);
    CC_SYNTHESIZE(int, m_roleType, RoleType);
    CC_SYNTHESIZE(int, m_jumpType, JumpType);
    int m_soundJump1;
    int m_soundJump2;
    int m_direction;
    void setImageN();
    void setImageS();
    
    bool initWithType(int type);
    static LWGameRole* creatRoleWithType(int type);
    static LWGameRole* creatRoleWithName(const char *pszFileName);
    bool initWithName(const char *pszFileName);
    void setFlipXCall();
    
    void girlJump(int direction);
    void playSound();

};


#endif /* defined(__BraveGame__LWGameRole__) */

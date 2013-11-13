//
//  LWGameScene.h
//  LWGame
//
//  Created by æ�Žè·ƒæ–‡ on 13-7-26.
//
//

#ifndef __LWGame__LWGameScene__
#define __LWGame__LWGameScene__

#include <iostream>
#include <fstream>
#include "LWConfig.h"
#include "LWGameOverScene.h"
#include "LWGM.h"
#include "LWAudioGM.h"
#include "LWGameRole.h"
#define Heigh_Boy 334
#define Tag_MenuLeft 101
#define Tag_MenuRight 102
#define Tag_MenuPause 103
#define Tag_AmiRepeat 104
#define Tag_MenuBackGame 105
#define Tag_MenuBackStart 106
#define Tag_MenuGameStart 107
#define Tag_MenuGameRetry 109
#define Tag_ad 108
#define Tag_RankGame 111
#define Tag_Twitter 110
#define Tag_Twitter1 112
#define Tag_item1 113
#define Tag_item2 114
#define Tag_item3 115
#define Tag_item4 116



class LWGameScene: public CCLayer
{
public:
    ~LWGameScene();
    LWGameScene();

    void win();
    LWGameRole *m_girl;
    int m_direction;
    int m_gameTime;
    bool isCanMove;
    static CCScene* creatGameScene();
    void gameStartLayer();
    void removeFace(CCNode *node);
    void setPercentWithNode(CCNode *node,float percent);
    void goTime();
    float m_time;
    CCSprite *m_scoreBg;
    void addMap();
    std::string getLeftBalcony();
    std::string getRightBalcony();
    int judge_number(int i_val);
    void pushMenuJump(CCNode *sender);
    void mapMove();
    void mapMovedone();
    CCArray *m_signArray;
    void addCloud();
    void lastJump();
    CCSprite *m_mapBg1;
    CCSprite *m_mapBg2;
    CCLayer *m_worldLayer;
    CCLayer *m_worldLayer2;
    //CCSprite * m_pauseSprite;
    CCLabelTTF *m_countLb;
    void setNumLabel(int num);
    
    void setScore(int score);
    void addScoreAmi(CCNode *node,int score,int count);
    void removeNode(CCNode *node);
    void NPCComeBack(CCNode *node);
    float pointAngle(CCPoint pointA,CCPoint pointB);
    void bounsTime();
    LWGameRole *m_cat;
    LWGameRole *m_cow;
    
    float m_lenth;
    int m_count;
    int m_gameOverType;
    float boy_speed;
    float speedAdd;
    CCMenu *m_mainMenu;
    CCMenu *m_pauseMenu;

    void gamePause();
    void startGame();
    void gameOverReplace();
    void gameOver(int type);
    void refresh();
    void pushMenu(CCNode *sender);
    
    void gameResum();
    void timeAdd();
    int m_jumpTime;

};

#endif /* defined(__LWGame__LWGameScene__) */

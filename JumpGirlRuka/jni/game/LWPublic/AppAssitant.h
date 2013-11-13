//
//  AppAssitant.h
//  sharkHelpme
//
//  Created by YAN SUSHI on 13-6-26.
//
//

#ifndef __sharkHelpme__AppAssitant__
#define __sharkHelpme__AppAssitant__

#include <iostream>
#include "cocos2d.h"

#define bgSoundMuted "bgSoundMuted"

using namespace cocos2d;
class AppAssitant : public CCObject
{
public:
    AppAssitant();
    ~AppAssitant();
    static AppAssitant *shareAssitant();
    
    CCArray *getArray_sinkingMen();
    
    static float getDistance(CCPoint* p1,CCPoint *p2);
    void reportScore(float score);
    void showLeaderBoard();
    void enterGameCenter();
    void showApp();
    void showTwitter(float num);
    void showTwitter1();
    int m_count;
    
public:    
    int helped_people_count;
    bool paused_manually;
    //设置这个是为了控制背景音乐。cocos2d-x的bug：在背景音乐stop后，resume一下可以播放
    bool is_in_playView;
private:
    CCArray *array_sinkingMen;
    
};



#endif /* defined(__sharkHelpme__AppAssitant__) */

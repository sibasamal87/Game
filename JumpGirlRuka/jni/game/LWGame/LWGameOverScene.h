//
//  LWGameOverScene.h
//  LWGame
//
//  Created by 李跃文 on 13-7-29.
//
//

#ifndef __LWGame__LWGameOverScene__
#define __LWGame__LWGameOverScene__
#define Tag_MenuRetry 100
#define Tag_MenuTop 101
#define Tag_shopover 102
#define Tag_rank 103
#define Tag_twitter 104
#define tag_ad_bottom1  105
#define tag_ad_1  106
#define tag_ad_2  107
#include <iostream>
#include "LWConfig.h"
#include "LWGM.h"
#include "LWAudioGM.h"
class LWGameOverScene: public CCLayer
{
public:
    ~LWGameOverScene();
    LWGameOverScene();
    static CCScene* creatGameOverScene(int type);
    void pushMenu(CCNode *sender);
    bool init(int type);
    int m_type;
    CCString *getNumStr(int num);
    
};
#endif /* defined(__LWGame__LWGameOverScene__) */

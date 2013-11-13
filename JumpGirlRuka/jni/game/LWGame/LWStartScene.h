//
//  LWStartScene.h
//  LWGame
//
//  Created by æ�Žè·ƒæ–‡ on 13-7-26.
//
//

#ifndef __LWGame__LWStartScene__
#define __LWGame__LWStartScene__


#include <iostream>
#include "LWConfig.h"
#include "LWAudioGM.h"
#define tag_ad_middle_left  106
#define tag_ad_middle_right  107
#define tag_ad_middle_left1  108
#define tag_ad_middle_right1  109

#define Tag_StartGame 10001
#define Tag_Music 10002
#define Tag_Rank 10003
#define tag_ad_top  10004
#define tag_ad_middle_left  10005
#define tag_ad_middle_right  10006
#define tag_ad_recommend  10007
#define tag_ad_bottom  10008
#define Tag_popular 10009
#define Tag_popularApps 10010
#define Tag_ad_popularApps 10011
#define Tag_ad_shop 10012
#define Tag_ad_help 10013
#define Tag_GameFeet 10014
#define Tag_kong 10015
#define Tag_Rank2 10016
#define Tag_info 10017
#define Tag_rank1 10018
#define Tag_help 10019

class LWStartScene: public CCLayer
{
public:
    ~LWStartScene();
    LWStartScene();
    static CCScene* creatStartScene();
    void removeAdds();
    
    void pushMenu(CCNode *sender);
    void keyBackClicked();
    
};

#endif /* defined(__LWGame__LWStartScene__) */

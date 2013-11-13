//
//  LWAudioGM.h
//  LWGame
//
//  Created by 李跃文 on 13-7-26.
//
//

#ifndef __LWGame__LWAudioGM__
#define __LWGame__LWAudioGM__

#include <iostream>
#define SOUND_3_0_01 "sound/3-0_01.wav"
#define SOUND_aaa_01 "sound/aaa_01.wav"
#define SOUND_bgm "sound/bgm.wav"
#define SOUND_ho_02 "sound/ho_02.wav"
#define SOUND_ikimaasu_01 "sound/ikimaasu_01.wav"
#define SOUND_kyaa_02 "sound/kyaa_02"
#define SOUND_kyahhoo_01 "sound/kyahhoo_01.wav"
#define SOUND_yattane_01 "sound/yattane_01.wav"
#define SOUND_yeah_04 "sound/yeah_04.wav"
#define SOUND_yo_02 "sound/yo_02.wav"
#define SOUND_011 "sound/011.wav"


#include "LWConfig.h"
#include "cocos-ext.h"
using namespace cocos2d;
using namespace extension;
class LWAudioGM: public CCObject
{
public:
    static LWAudioGM* sharedEngine();
    bool init();
    CC_SYNTHESIZE(bool, m_isOnMusic, IsOnMusic);
    CC_SYNTHESIZE(bool, m_isOnEffect, IsOnEffect);
    void playOnceEffect(const char* string,float volume);
    void playBackgroundMd(const char * string,float volume);
    void stopBackgroundMd();
    void stopEffect();
};

#endif /* defined(__LWGame__LWAudioGM__) */

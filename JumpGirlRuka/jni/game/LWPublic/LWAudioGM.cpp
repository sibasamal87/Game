//
//  LWAudioGM.cpp
//  LWGame
//
//  Created by 李跃文 on 13-7-26.
//
//

#include "LWAudioGM.h"
#include "SimpleAudioEngine.h"
static LWAudioGM *g_sharedEngine = NULL;

LWAudioGM*  LWAudioGM::sharedEngine()
{
    if (!g_sharedEngine)
    {
        g_sharedEngine = new LWAudioGM();
        g_sharedEngine -> init();
    }
    return g_sharedEngine;
}

bool LWAudioGM::init()
{
    CCUserDefault *isMusic = CCUserDefault::sharedUserDefault();
    if (!isMusic ->getBoolForKey("isFirst"))
    {
        isMusic->setBoolForKey("isFirst", true);
        isMusic->setBoolForKey("isMusic", true);
        
    }
    m_isOnMusic = isMusic ->getBoolForKey("isMusic");
    
    return true;
}
void LWAudioGM::playOnceEffect(const char* string,float volume)//播放音效（规定时间内只播放一次音效）
{
    if (m_isOnMusic)
    {
        CocosDenshion::SimpleAudioEngine::sharedEngine() -> playEffect(string);
        CocosDenshion::SimpleAudioEngine::sharedEngine() -> setEffectsVolume(volume);
    }
}

void LWAudioGM::playBackgroundMd(const char * string,float volume)
{

    if (m_isOnMusic)
    {
        CocosDenshion::SimpleAudioEngine::sharedEngine() -> playBackgroundMusic(string, true);
        CocosDenshion::SimpleAudioEngine::sharedEngine() -> setBackgroundMusicVolume(volume);
    }
}
void LWAudioGM::stopEffect()
{
    CocosDenshion::SimpleAudioEngine::sharedEngine() ->stopAllEffects();
}
void LWAudioGM::stopBackgroundMd()
{
    CocosDenshion::SimpleAudioEngine::sharedEngine() -> stopBackgroundMusic();
}
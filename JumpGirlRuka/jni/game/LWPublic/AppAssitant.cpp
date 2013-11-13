//
//  AppAssitant.cpp
//  sharkHelpme
//
//  Created by YAN SUSHI on 13-6-26.
//
//

#include "AppAssitant.h"

static AppAssitant *_shareAssitant = NULL;

AppAssitant* AppAssitant::shareAssitant()
{
    if(!_shareAssitant)
    {
        _shareAssitant = new AppAssitant();
    }
    return _shareAssitant;
}

float AppAssitant::getDistance(CCPoint *p1, CCPoint *p2)
{
    return sqrtf((p1->x-p2->x)*(p1->x-p2->x)+(p1->y-p2->y)*(p1->y-p2->y));
}

AppAssitant::AppAssitant()
{
    //autorelease
    array_sinkingMen = CCArray::create();
    array_sinkingMen->retain();
}

AppAssitant::~AppAssitant()
{
    array_sinkingMen->release();
}

CCArray* AppAssitant::getArray_sinkingMen()
{
    
    return array_sinkingMen;
}
void AppAssitant::enterGameCenter()
{
}
void AppAssitant::showApp()
{
    struct cc_timeval now;
    CCTime::gettimeofdayCocos2d(&now, NULL);
    
    int time =now.tv_sec * 1000 + now.tv_usec / 1000;
    struct tm *tm;
    
    tm = localtime(&now.tv_sec);
    
    
    int day = tm->tm_mday;
    
    int today= CCUserDefault::sharedUserDefault()->getIntegerForKey("today");
    if (today==0)
    {
        CCUserDefault::sharedUserDefault()->setIntegerForKey("today", day);
    }
    
    if (today!=day)
    {
        CCUserDefault::sharedUserDefault()->setIntegerForKey("today", day);
        CCUserDefault::sharedUserDefault()->setIntegerForKey("isAlert", 2);
    }
    
    int isAlert =CCUserDefault::sharedUserDefault()->getIntegerForKey("isAlert");
    if (isAlert==0)
    {
        CCUserDefault::sharedUserDefault()->setIntegerForKey("isAlert", 2);
    }
    
    if (isAlert==2)
    {
        int alart= CCUserDefault::sharedUserDefault()->getIntegerForKey("alert");
        if (alart==7)
        {
            alart=0;
            CCUserDefault::sharedUserDefault()->setIntegerForKey("alert", alart);
            CCUserDefault::sharedUserDefault()->setIntegerForKey("isAlert", 1);
            
        }
        if (alart<7)
        {
            alart++;
            CCUserDefault::sharedUserDefault()->setIntegerForKey("alert", alart);
        }
        
    }
    
}
void AppAssitant::reportScore(float score)
{
}

void AppAssitant::showLeaderBoard()
{
    
}
void AppAssitant::showTwitter1()
{
}

void AppAssitant::showTwitter(float num)
{
}

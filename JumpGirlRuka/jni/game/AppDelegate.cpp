//
//  EasterGameAppDelegate.cpp
//  EasterGame
//
//  Created by æ�Žè·ƒæ–‡ on 13-9-24.
//  Copyright __MyCompanyName__ 2013å¹´. All rights reserved.
//

#include "AppDelegate.h"

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "LWStartScene.h"

USING_NS_CC;
using namespace CocosDenshion;

AppDelegate::AppDelegate()
{

}

AppDelegate::~AppDelegate()
{
}

bool AppDelegate::applicationDidFinishLaunching()
{
    // initialize director
    CCDirector *pDirector = CCDirector::sharedDirector();
    pDirector->setOpenGLView(CCEGLView::sharedOpenGLView());

    // turn on display FPS
    //pDirector->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);
    
    CCSize realSize = CCEGLView::sharedOpenGLView()->getFrameSize();
    	        //å¤šåˆ†è¾¨çŽ‡ä½¿é…�
	TargetPlatform target = getTargetPlatform();
	if(target == kTargetIpad){

	CCEGLView::sharedOpenGLView()->setDesignResolutionSize(1024, 768, kResolutionExactFit);
	// pDirector->setContentScaleFactor(1024.0/960);

	}else if(target == kTargetIphone){

	CCEGLView::sharedOpenGLView()->setDesignResolutionSize(realSize.width, realSize.height, kResolutionExactFit);

	}
	else if(target == kTargetAndroid){

	CCEGLView::sharedOpenGLView()->setDesignResolutionSize(640,1136, kResolutionExactFit);

	}

    // create a scene. it's an autorelease object
    CCScene *pScene = LWStartScene::creatStartScene();

    // run
    pDirector->runWithScene(pScene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
    CCDirector::sharedDirector()->stopAnimation();
//    SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->pauseAllEffects();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    CCDirector::sharedDirector()->startAnimation();
//    SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->resumeAllEffects();
}

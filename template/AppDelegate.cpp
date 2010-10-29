// Application application cpp file.
 
// Original file name: cocosTemplateApp.cpp
// Generated by TOPS Builder:Project wizard,Date:2010-09-27
 

#include "cocos2d.h"

#include "AppDelegate.h"
#include "HelloWorldScene.h"
#include "Resource.h"

using namespace cocos2d;

extern const AppResourceEntry cocosTemplateResourceEntry;

// the works are the same as NSObject<UIApplicationDelegate>::applicationDidFinishLaunching of cocos2d-iphone
bool AppDelegate::initCocos2d()
{
	// init director
	CCDirector *pDirector = CCDirector::getSharedDirector();
	pDirector->setOpenGLView(m_pMainWnd);

	// sets landscape mode
	pDirector->setDeviceOrientation(kCCDeviceOrientationLandscapeLeft);

	// turn on display FPS
	pDirector->setDisplayFPS(true);

    // set the ResourceEntry
    CCFileUtils::setResourceEntry(&cocosTemplateResourceEntry);

    // set the Images ResInfo (name and ResID)
    CCFileUtils::setResourceInfo(ResInfo, sizeof(ResInfo) / sizeof(T_ResourceInfo));

	// create a scene. it's an autorelease object
	CCScene *pScene = HelloWorld::scene();

	// run
	CCDirector::getSharedDirector()->runWithScene(pScene);

	return true;
}


AppDelegate::AppDelegate()
:m_rcWnd(0, 0, GetScreenWidth(), GetScreenHeight())
,m_pMainWnd(NULL)
{

}

AppDelegate::~AppDelegate()
{

}

Boolean  AppDelegate::EventHandler(EventType*  pEvent)
{
	Boolean bHandled = FALSE;

	switch(pEvent->eType)
	{
	case EVENT_AppLoad:
		{
			// it's important to use CCXEGLView, or you may inherit it to add your implement
			if (! (m_pMainWnd = new CCXEGLView(this)) || ! m_pMainWnd->Create(&m_rcWnd))
			{
        		// create window failed, clear the heap
				delete m_pMainWnd;
				CCScheduler::purgeSharedScheduler();

				// quit application
				SendStopEvent();
				bHandled = TRUE;
				break;
			}
			SetActiveWindow(m_pMainWnd);
			// do not return bHandle equal TRUE, CCXApplication::EventHandler need do some thing.
			break;
		}
		bHandled = TRUE;
		break;

	case EVENT_AppStopNotify:
		{
			
		}
		bHandled = FALSE;
		break;
	}

	return (bHandled) ? TRUE : CCXApplication::EventHandler(pEvent);
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
    CCDirector::getSharedDirector()->stopAnimation();

	// if you use SimpleAudioEngine, it must be pause
	// SimpleAudioEngine::getSharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    CCDirector::getSharedDirector()->startAnimation();
	
	// SimpleAudioEngine::getSharedEngine()->resumeBackgroundMusic();
}

#include "ofMain.h"
#include "ofApp.h"
#include "ofAppGLFWWindow.h"

int getNumScreens(){
    CGDisplayCount displayCount;
    CGDirectDisplayID displays[32];
    CGGetActiveDisplayList(32, displays, &displayCount);
    return displayCount;
}

int main(){
    bool isProductionMode = false;

    shared_ptr<ofApp> mainApp(new ofApp);
    mainApp.get()->setIsProductionMode(isProductionMode);
    int numScreens = getNumScreens();

    ofGLFWWindowSettings settings;
    if(isProductionMode){
        settings.windowMode = OF_FULLSCREEN;
    }
    settings.monitor = 0;
    shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);

    settings.shareContextWith = mainWindow;
    settings.monitor = numScreens > 1 ? 1 : settings.monitor;
    shared_ptr<ofAppBaseWindow> secondWindow = ofCreateWindow(settings);
    secondWindow->setVerticalSync(false);

    settings.monitor = numScreens > 2 ? 2 : settings.monitor;
    shared_ptr<ofAppBaseWindow> thirdWindow = ofCreateWindow(settings);
    thirdWindow->setVerticalSync(false);

    ofAddListener(secondWindow->events().draw, mainApp.get(), &ofApp::drawSecondWindow);
    ofAddListener(thirdWindow->events().draw, mainApp.get(), &ofApp::drawThirdWindow);
    
    ofRunApp(mainWindow, mainApp);
    ofRunMainLoop();
}

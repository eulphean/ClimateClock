#include "CenteredClock.h"

void CenteredClock::setup(bool _isProductionMode) {
    isProductionMode = _isProductionMode;
    isThirdWindowSetup = false;
    clock.setup("newyork.xml");
}

void CenteredClock::update() {
    clock.update();
}

void CenteredClock::drawThirdWindow(){
    if(!isThirdWindowSetup){
        setupThirdWindow();
    }
}

void CenteredClock::setupThirdWindow(){
    ofSetHexColor(0xFFFFFF);
    ofBackground(0, 0, 0);
    ofEnableAlphaBlending();
    
    if(isProductionMode){
        ofSetFullscreen(true);
    } else {
        ofSetWindowPosition(8, 500);
        ofSetWindowShape(400, 400);
    }
    isThirdWindowSetup = true;
}

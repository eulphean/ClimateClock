#include "CenteredClock.h"

void CenteredClock::setup(bool _isProductionMode) {
    isProductionMode = _isProductionMode;
    isThirdWindowSetup = false;
    clock.setup("newyorkmain.xml");
  
    // TODO: Add a GUI to place the clock.
    // Get a good font.
    // Add a line on top as the city name.
    if (isProductionMode) {
      clock.setPosition(ofGetWidth()/2-100, ofGetHeight()/2);
    } else {
      clock.setPosition(50, 200);
    }
}

void CenteredClock::update() {
    clock.update();
}

void CenteredClock::drawThirdWindow(){
    if(!isThirdWindowSetup){
        setupThirdWindow();
    }
  
    clock.drawClock();
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

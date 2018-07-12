#include "CenteredClock.h"

void CenteredClock::setup(bool _isProductionMode) {
    isProductionMode = _isProductionMode;
    isThirdWindowSetup = false;
  
    // Initialize clock.
    clock.setup("mainnyc.xml", POSITION_MODE_CENTERED, "CenterCoreClock.xml");
    clock.hideRoundedBorder = true;
    clock.guiXOffsetForCity = true;
  
    // Setup the GUI.
    gui.setup("Centered Clock Params.");
    gui.setPosition(300, 250);
    gui.add(xPosition);
    gui.add(yPosition);
    gui.add(xScale);
    gui.add(yScale);
    gui.loadFromFile("CenterClock.xml");
  
    // Set position in the window if we are not in
    // production mode.
    if (!isProductionMode) {
      clock.setPosition(50, 200);
    }
}

void CenteredClock::update() {
    clock.update();
  
    if (isProductionMode) {
      clock.setPosition(xPosition, yPosition);
    }
}

void CenteredClock::drawFirstWindow() {
    // Core clock GUI.
    clock.drawGui();
  
    // Draw Centered Clock GUI in production mode only.
    if (isProductionMode) {
      gui.draw();
    }
}

void CenteredClock::drawThirdWindow(){
    if(!isThirdWindowSetup){
        setupThirdWindow();
    }
  
    ofPushMatrix();
      if (isProductionMode) {
        ofScale(xScale, yScale, 0);
      }
      clock.drawClock();
    ofPopMatrix();
}

void CenteredClock::setupThirdWindow(){
    ofBackground(52, 52, 52);
    ofEnableAlphaBlending();
    
    if(isProductionMode){
        ofSetFullscreen(true);
    } else {
        ofSetWindowPosition(8, 500);
        ofSetWindowShape(400, 400);
    }
    isThirdWindowSetup = true;
}

void CenteredClock::exit() {
   gui.saveToFile("CenterClock.xml");
   clock.exit();
}

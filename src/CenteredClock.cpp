#include "CenteredClock.h"

void CenteredClock::setup() {
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


void CenteredClock::exit() {
   gui.saveToFile("CenterClock.xml");
   clock.exit();
}

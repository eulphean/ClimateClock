#include "CenteredClock.h"

void CenteredClock::setup() {
    // Initialize clock.
    clock.setup("chicago.xml", POSITION_MODE_CENTERED, "CenterCoreClock.xml");
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
    clock.setPosition(xPosition, yPosition);
}

void CenteredClock::draw() {
  // Draw Gui (TODO: Add a flag to hide the GUI as well). 
  clock.drawGui();
  gui.draw();
  
  // Apply scaling to the center clock.
  ofPushMatrix();
    ofScale(xScale, yScale, 0);
    clock.drawClock();
  ofPopMatrix();
}


void CenteredClock::exit() {
   gui.saveToFile("CenterClock.xml");
   clock.exit();
}

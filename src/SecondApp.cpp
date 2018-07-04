#include "SecondApp.h"

//--------------------------------------------------------------
void SecondApp::setup() {
  // Setup clock
  myClock.setup();
  
  // Setup GUI.
  gui.setup();
  gui.setPosition(50, 65);
  gui.add(myClock.formatParams);
  gui.add(myClock.clockParams);
  gui.add(myClock.textColor.setup("Text color", ofColor(0), ofColor(0), ofColor(255)));
  gui.add(backgroundColor.setup("Background color", ofColor(255, 0, 0), ofColor(0), ofColor(255)));
  gui.loadFromFile("ClimateClockSecond.xml");
  
  myClock.setCurrentFont(7);
}

//--------------------------------------------------------------
void SecondApp::update() {
  ofBackground(backgroundColor);
  // A second has passed, update carbon countdown clock.
  myClock.update();
}

//--------------------------------------------------------------
void SecondApp::draw() {
  myClock.draw();
  
  if (!hideGui) {
    ofDrawBitmapStringHighlight("Press h to toggle GUI", 55, 30);
    ofDrawBitmapStringHighlight("Current font: " + myClock.currentFont() + " <-- Press left/right arraow keys to cycle the font.", 55, 55);
    gui.draw();
  }
}

void SecondApp::exit() {
  gui.saveToFile("ClimateClockSecond.xml");
}

void SecondApp::keyPressed(int key) {
  if (key == 'h') {
    hideGui = !hideGui;
  }
  
  if (key == OF_KEY_RIGHT) {
    myClock.cycleFont(true);
  }
  
  if (key == OF_KEY_LEFT) {
    myClock.cycleFont(false);
  }
}

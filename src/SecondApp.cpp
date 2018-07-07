#include "SecondApp.h"

//--------------------------------------------------------------
void SecondApp::setup() {
  // Setup clock
  clock.setup();
  
  // Setup GUI.
  gui.setup();
  gui.setPosition(50, 65);
  gui.add(clock.formatParams);
  gui.add(clock.textColor.setup("Text color", ofColor(0), ofColor(0), ofColor(255)));
  gui.add(backgroundColor.setup("Background color", ofColor(255, 0, 0), ofColor(0), ofColor(255)));
  gui.loadFromFile("ClimateClockSecond.xml");
  
  clock.setCurrentFont(4);
}

//--------------------------------------------------------------
void SecondApp::update() {
  ofBackground(backgroundColor);
  clock.update();
}

//--------------------------------------------------------------
void SecondApp::draw() {
  clock.draw();
  
  if (!hideGui) {
    ofDrawBitmapStringHighlight("Press h to toggle GUI", 55, 30);
    ofDrawBitmapStringHighlight("Current font: " + clock.currentFont() + " <-- Press left/right arraow keys to cycle the font.", 55, 55);
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
    clock.cycleFont(true);
  }
  
  if (key == OF_KEY_LEFT) {
    clock.cycleFont(false);
  }
}

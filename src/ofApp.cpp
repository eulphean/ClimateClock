#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  ofBackground(ofColor::red);
  
  // Setup clock
  myClock.setup();
  
  // Setup GUI.
  gui.setup();
  gui.setPosition(50, 65);
  gui.add(myClock.formatParams);
  gui.add(myClock.clockParams);
  gui.loadFromFile("ClimateClock.xml");
  
  // Record first time.
  lastTimeMillis = ofGetElapsedTimeMillis();
}

//--------------------------------------------------------------
void ofApp::update() {
  // As this time increases, the carbon countdown time
  // decreases.
  if (ofGetElapsedTimeMillis() - lastTimeMillis > 1000) {
    // A second has passed, update carbon countdown clock.
    myClock.update();
    
    // Reset time
    lastTimeMillis = ofGetElapsedTimeMillis();
  }
}

//--------------------------------------------------------------
void ofApp::draw() {
  myClock.draw();
  
  if (!hideGui) {
    ofDrawBitmapStringHighlight("Press h to toggle GUI", 55, 30);
    ofDrawBitmapStringHighlight("Current font: " + myClock.currentFont() + " <-- Press left/right arraow keys to cycle the font.", 55, 55);
    gui.draw();
  }
}

void ofApp::exit() {
  gui.saveToFile("ClimateClock.xml");
}

void ofApp::keyPressed(int key) {
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

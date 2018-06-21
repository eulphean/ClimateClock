#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  ofBackground(0);
  
  // Setup clock
  myClock.setup();
  
  // Setup GUI.
  gui.setup();
  gui.add(myClock.parameters);
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

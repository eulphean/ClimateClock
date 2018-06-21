#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  // Setup clock
  myClock.setup();
  
  // Setup GUI.
  gui.setup();
  gui.add(myClock.parameters);
  
  // Record first time.
  lastTimeMillis = ofGetElapsedTimeMillis();
}

//--------------------------------------------------------------
void ofApp::update(){
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
void ofApp::draw(){
  myClock.draw();
  gui.draw();
}

void ofApp::keyPressed(int key) {}

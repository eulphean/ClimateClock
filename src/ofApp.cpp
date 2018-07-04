#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  // Setup clock
  myClock.setup();
  
  // Setup GUI.
  gui.setup();
  gui.setPosition(50, 65);
  gui.add(myClock.formatParams);
  gui.add(myClock.clockParams);
  gui.add(myClock.textColor.setup("Text color", ofColor(0), ofColor(0), ofColor(255)));
  gui.add(backgroundColor.setup("Background color", ofColor(255, 0, 0), ofColor(0), ofColor(255)));
  gui.loadFromFile("ClimateClock.xml");

  // Setup projection mask
  projectionMask.setup(HOMOGRAPHY);
  clockFace = projectionMask.newPattern(1350, 70);
}

//--------------------------------------------------------------
void ofApp::update() {
  ofBackground(backgroundColor);
  projectionMask.update(mouseX, mouseY);
  
  myClock.update();
}

//--------------------------------------------------------------
void ofApp::draw() {
  clockFace->begin();
  {
    ofBackground(ofColor::white);
    myClock.draw();
  }
  clockFace->end();
  
  if (!hideGui) {
    ofDrawBitmapStringHighlight("Press h to toggle GUI", 55, 30);
    ofDrawBitmapStringHighlight("Current font: " + myClock.currentFont() + " <-- Press left/right arraow keys to cycle the font.", 55, 55);
    //gui.draw();
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

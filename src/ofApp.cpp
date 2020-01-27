#include "ofApp.h"

void ofApp::setup() {
  centeredClock.setup();
  hideGui = true;
  bg.load("background.jpg");
  
  // Initialize colors.
  colors.push_back(ofColor(211, 55, 35));
  colors.push_back(ofColor(237, 177, 30));
  colors.push_back(ofColor(22, 89, 144));
  colors.push_back(ofColor(89, 179, 60));
  colors.push_back(ofColor(220, 219, 218));
  lerpAmt = 0.0; // Must go from 0-1.
  curColIdx = 0;
  
  pressed = false;
}

void ofApp::update() {
  centeredClock.update();
  handleColorLerp();
}

void ofApp::draw() {
  if (pressed) {
    bg.draw(0, 0, ofGetWidth(), ofGetWidth());
  } else {
    ofBackground(lerped);
  }
  
  centeredClock.draw(hideGui);
}

void ofApp::handleColorLerp() {
  // Color lerping
  if (lerpAmt >= 1) {
    // Swap colors
    ofColor temp = end;
    end = start;
    start = temp;
    curColIdx = (curColIdx + 1) % colors.size();
    lerpAmt = 0;
  }
  
  int nextColIdx = (curColIdx + 1) % colors.size();
  start = colors[curColIdx]; end = colors[nextColIdx];
  lerped = start.getLerped(end, lerpAmt);
  lerpAmt = lerpAmt + 0.001;
}

void ofApp::exit(){
  centeredClock.exit();
}

void ofApp::keyPressed(int key) {
  if (key == 'h') {
    hideGui = !hideGui;
  }
}

void ofApp::mousePressed(int x, int y, int button) {
  centeredClock.nextTimezone();
  pressed = true;
}

void ofApp::mouseReleased(int x, int y, int button) {
  pressed = false;
}

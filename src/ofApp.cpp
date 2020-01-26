#include "ofApp.h"

void ofApp::setup() {
  centeredClock.setup();
  hideGui = true;
  bg.load("background.jpg");
}

void ofApp::update() {
  centeredClock.update();
}

void ofApp::draw() {
  bg.draw(0, 0, ofGetWidth(), ofGetWidth());
  for (int i = 0; i < dips.size(); i++) {
    dips[i].draw();
  }
  centeredClock.draw(hideGui);
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
  
  auto pos = glm::vec2(x, y);
  cout << pos << endl; 
  auto c = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
  auto r = ofRandom(5, 10);
  
  Dip d (pos, c, r);
  dips.push_back(d);
}

// Animations (interpolate the background) = no
// Touch response (animate/do something when something happens)

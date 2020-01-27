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
}

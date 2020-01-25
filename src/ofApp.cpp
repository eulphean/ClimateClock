#include "ofApp.h"

void ofApp::setup() {
  centeredClock.setup();
  hideGui = false;
}

void ofApp::update() {
  centeredClock.update();
}

void ofApp::draw() {
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

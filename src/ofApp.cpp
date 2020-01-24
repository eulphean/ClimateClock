#include "ofApp.h"

void ofApp::setup() {
  centeredClock.setup();
}

void ofApp::update() {
    centeredClock.update();
}

void ofApp::draw() {
    centeredClock.draw();
}

void ofApp::exit(){
    centeredClock.exit();
}

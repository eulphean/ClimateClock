#include "ofApp.h"

void ofApp::setup() {
    drawMode.setup();
    clockGrid.setup();
    videoOverlay.setup(isProductionMode);
    centeredClock.setup(isProductionMode);
}

void ofApp::update() {
    drawMode.update();
    clockGrid.update();
    videoOverlay.update();
    centeredClock.update();
}

void ofApp::draw() {
    if (drawMode.isClockGrid()) {
        clockGrid.drawFirstWindow();
        centeredClock.drawFirstWindow();
    } else if(drawMode.isVideoOverlay()) {
        videoOverlay.drawFirstWindow();
    }
}

void ofApp::drawSecondWindow(ofEventArgs &args) {
   if (drawMode.isClockGrid()) {
      ofPushStyle();
      unsigned long elapsedTime = ofGetElapsedTimeMillis() - drawMode.lastTime;
      int alpha = ofMap(elapsedTime, 0, 5000, 0, 255, true);
      ofEnableAlphaBlending();
      //ofSetColor(255, 255, 255, alpha);
      clockGrid.drawSecondWindow();
      ofDisableAlphaBlending();
      ofPopStyle();
    } else if (drawMode.isVideoOverlay()) {
      videoOverlay.drawSecondWindow();
    }
}

void ofApp::drawThirdWindow(ofEventArgs &args) {
    centeredClock.drawThirdWindow();
}

void ofApp::exit(){
    centeredClock.exit();
    clockGrid.exit();
}

void ofApp::setIsProductionMode(bool _isProductionMode){
    isProductionMode = _isProductionMode;
}

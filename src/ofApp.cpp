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
    } else if(drawMode.isNewYorkOverlay()) {
        videoOverlay.setCurrentCity("newyork");
        videoOverlay.drawFirstWindow();
    } else if(drawMode.isTokyoOverlay()) {
        videoOverlay.setCurrentCity("tokyo");
        videoOverlay.drawFirstWindow();
    } else if(drawMode.isParisOverlay()) {
        videoOverlay.setCurrentCity("paris");
        videoOverlay.drawFirstWindow();
    }
}

void ofApp::drawSecondWindow(ofEventArgs &args) {
    if (drawMode.isClockGrid()) {
        clockGrid.drawSecondWindow();
    } else if(drawMode.isNewYorkOverlay()) {
        videoOverlay.setCurrentCity("newyork");
        videoOverlay.drawSecondWindow();
    } else if(drawMode.isTokyoOverlay()) {
        videoOverlay.setCurrentCity("tokyo");
        videoOverlay.drawSecondWindow();
    } else if(drawMode.isParisOverlay()) {
        videoOverlay.setCurrentCity("paris");
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

#include "ofApp.h"

void ofApp::setup() {
    drawMode.setup();
    clockGrid.setup();
    videoOverlay.setup();
    centeredClock.setup();
}

void ofApp::update() {
    clockGrid.update();
    videoOverlay.update();
    centeredClock.update();
}

void ofApp::draw() {
    if (drawMode.isClockGrid()) {
        clockGrid.drawFirstWindow();
    } else if(drawMode.isVideoOverlay()) {
        videoOverlay.drawFirstWindow();
    }
}

void ofApp::drawSecondWindow(ofEventArgs &args) {
    if (drawMode.isClockGrid()) {
        clockGrid.drawSecondWindow();
    } else if(drawMode.isVideoOverlay()) {
        videoOverlay.drawSecondWindow();
    }
}

void ofApp::drawThirdWindow(ofEventArgs &args) {
    centeredClock.drawThirdWindow();
}

void ofApp::exit(){
    clockGrid.exit();
}

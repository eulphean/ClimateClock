#include "ofApp.h"

void ofApp::setup() {
    drawMode.setup();
    clock.setup("newyork.xml");
    clockGrid.setup();
    videoOverlay.setup(&clock);
}

void ofApp::update() {
    clock.update();
    clockGrid.update();
    videoOverlay.update();
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

void ofApp::exit(){
    clockGrid.exit();
}

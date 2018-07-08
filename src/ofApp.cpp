#include "ofApp.h"

void ofApp::setup() {
    drawMode = CC_DRAW_VIDEOS;
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
    if (isInGridMode()) {
        clockGrid.drawFirstWindow();
    } else if(isInVideoMode()) {
        videoOverlay.drawFirstWindow();
    }
}

void ofApp::drawSecondWindow(ofEventArgs &args) {
    if (isInGridMode()) {
        clockGrid.drawSecondWindow();
    } else if(isInVideoMode()) {
        videoOverlay.drawSecondWindow();
    }
}

void ofApp::keyPressed(int key) {
    if(key == OF_KEY_RETURN) {
        drawMode = isInVideoMode() ? CC_DRAW_GRID : CC_DRAW_VIDEOS;
    }
}

bool ofApp::isInGridMode(){
    return drawMode == CC_DRAW_GRID;
}

bool ofApp::isInVideoMode(){
    return drawMode == CC_DRAW_VIDEOS;
}

void ofApp::exit(){
    clockGrid.exit();
}

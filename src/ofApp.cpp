#include "ofApp.h"

void ofApp::setup() {
    clock.setup();

    gui.setup();
    gui.setPosition(50, 65);
    gui.add(clock.formatParams);
    gui.add(clock.textColor.setup("Text color", ofColor(0), ofColor(0), ofColor(255)));
    gui.add(backgroundColor.setup("Background color", ofColor(255, 0, 0), ofColor(0), ofColor(255)));
    gui.loadFromFile("ClimateClock.xml");

    projectionMask.setup(HOMOGRAPHY);
    clockFace = projectionMask.newPattern(1350, 70);

    setupImages();
    background = projectionMask.getBackground();
}

void ofApp::setupImages(){
    backgroundsDir = "cities";
    ofDirectory dir(backgroundsDir);
    dir.listDir();
    vector<ofFile> contents = dir.getFiles();

    for(int i = 0; i < contents.size(); i++){
        if(i == 0){
            currentCity = contents.at(i).getBaseName();
        }
        backgroundImage.load(backgroundsDir + "/" + contents.at(i).getFileName());
        backgrounds[contents.at(i).getBaseName()] = backgroundImage;
    }
}

void ofApp::update() {
    ofBackground(backgroundColor);
    projectionMask.update(mouseX, mouseY);
    clock.update();

    background->begin();
    {
        backgrounds[currentCity].draw(0, 0, background->getWidth(), background->getHeight());
    }
    background->end();
}

void ofApp::draw() {
    clockFace->begin();
    {
        ofBackground(ofColor::white);
        clock.draw();
    }
    clockFace->end();

    if (!hideGui) {
        ofDrawBitmapStringHighlight("Press h to toggle GUI", 55, 30);
        ofDrawBitmapStringHighlight("Current font: " + clock.currentFont() + " <-- Press left/right arraow keys to cycle the font.", 55, 55);
        //gui.draw();
    }
}

void ofApp::exit() {
    gui.saveToFile("ClimateClock.xml");
}

void ofApp::keyPressed(int key) {
    if (key == 'h') {
        hideGui = !hideGui;
    }

    if (key == OF_KEY_RIGHT) {
        clock.cycleFont(true);
    }

    if (key == OF_KEY_LEFT) {
        clock.cycleFont(false);
    }
}

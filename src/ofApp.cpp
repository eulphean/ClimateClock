#include "ofApp.h"

void ofApp::setup() {
    drawMode = CC_DRAW_VIDEOS;

    clock.setup("newyork.xml");
    clockGrid.setup();

    projectionMask.setup(HOMOGRAPHY, PRESETS_PRODUCTION);
    setupMovies();
    clockFace = projectionMask.newPattern(1350, 70);
    projectionMask.setStorageFileName(cities.at(currentCity));

    background = projectionMask.getBackground();
}

void ofApp::setupMovies(){
    currentCity = 0;
    backgroundsDir = "cities";
    ofDirectory dir(backgroundsDir);
    dir.listDir();
    vector<ofFile> contents = dir.getFiles();

    for(int i = 0; i < contents.size(); i++){
        cities.push_back(contents.at(i).getBaseName());
        backgroundMovie.load(backgroundsDir + "/" + contents.at(i).getFileName());
        backgrounds[contents.at(i).getBaseName()] = backgroundMovie;
    }
    playCurrentMovie();
}

void ofApp::update() {
    if(ofGetFrameNum() == 1){
        projectionMask.setStorageFileName(cities.at(currentCity));
    }
    projectionMask.update(mouseX, mouseY);
    clock.update();
    clockGrid.update();

    for(auto& background : backgrounds){
        background.second.update();
    }
}

void ofApp::draw() {
    if (isInGridMode()) {
        clockGrid.drawFirstWindow();
    } else if(isInVideoMode()) {
        background->begin();
        {
            backgrounds[cities.at(currentCity)].draw(0, 0, background->getWidth(), background->getHeight());
        }
        background->end();
        
        clockFace->begin();
        {
            ofBackground(ofColor::white);
            clock.drawClock();
        }
        clockFace->end();

        projectionMask.drawFirstWindow();
    }
}

void ofApp::drawSecondWindow(ofEventArgs &args) {
    if (isInGridMode()) {
        clockGrid.drawSecondWindow();
    } else if(isInVideoMode()) {
        projectionMask.drawSecondWindow();
    }
}

void ofApp::keyPressed(int key) {
    if(key == 'c' || key == 'C') {
        stopCurrentMovie();
        currentCity++;
        if(currentCity >= cities.size()){
            currentCity = 0;
        }
        projectionMask.setStorageFileName(cities.at(currentCity));
        playCurrentMovie();
    }

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

void ofApp::playCurrentMovie(){
    backgrounds[cities.at(currentCity)].play();
}

void ofApp::stopCurrentMovie(){
    backgrounds[cities.at(currentCity)].stop();
}

void ofApp::exit(){
    clockGrid.exit();
}

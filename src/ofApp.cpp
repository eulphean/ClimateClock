#include "ofApp.h"

void ofApp::setup() {
    clock.setup("newyork.xml");

    projectionMask.setup(HOMOGRAPHY);
    clockFace = projectionMask.newPattern(1350, 70);

    setupMovies();
    currentCity = 0;
    background = projectionMask.getBackground();
}

void ofApp::setupMovies(){
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
    projectionMask.update(mouseX, mouseY);
    clock.update();

    for(auto& background : backgrounds){
        background.second.update();
    }

    background->begin();
    {
        backgrounds[cities.at(currentCity)].draw(0, 0, background->getWidth(), background->getHeight());
    }
    background->end();
}

void ofApp::draw() {
    clockFace->begin();
    {
        ofBackground(ofColor::white);
        clock.drawClock();
    }
    clockFace->end();
}

void ofApp::drawSecondWindow(ofEventArgs &args){
    projectionMask.drawSecondWindow();
}

void ofApp::keyPressed(int key) {
    if (key == 'c' || key == 'C') {
        stopCurrentMovie();
        currentCity++;
        if(currentCity >= cities.size()){
            currentCity = 0;
        }
        projectionMask.setStorageFileName(cities.at(currentCity));
        playCurrentMovie();
    }
}

void ofApp::playCurrentMovie(){
    backgrounds[cities.at(currentCity)].play();
}

void ofApp::stopCurrentMovie(){
    backgrounds[cities.at(currentCity)].stop();
}

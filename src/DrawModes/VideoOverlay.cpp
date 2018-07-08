#include "VideoOverlay.h"

void VideoOverlay::setup(bool _isProductionMode) {
    isProductionMode = _isProductionMode;
    clock.setup();
    isProductionMode ?
        projectionMask.setup(HOMOGRAPHY, PRESETS_PRODUCTION) :
        projectionMask.setup(HOMOGRAPHY, PRESETS_DEVELOPMENT);

    setupMovies();
    clockFace = projectionMask.newPattern(1350, 70);
    projectionMask.setStorageFileName(cities.at(currentCity));
    background = projectionMask.getBackground();
    ofAddListener(ofEvents().keyPressed, this, &VideoOverlay::keyPressed);
}

void VideoOverlay::update() {
    clock.update();
    if(ofGetFrameNum() == 1){
        projectionMask.setStorageFileName(cities.at(currentCity));
    }
    projectionMask.update(ofGetMouseX(), ofGetMouseY());
    for(auto& background : backgrounds){
        background.second.update();
    }
}

void VideoOverlay::drawFirstWindow() {
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

void VideoOverlay::drawSecondWindow() {
    projectionMask.drawSecondWindow();
}

void VideoOverlay::keyPressed(ofKeyEventArgs& args){
    if(args.key == 'c' || args.key == 'C') {
        stopCurrentMovie();
        currentCity++;
        if(currentCity >= cities.size()){
            currentCity = 0;
        }
        projectionMask.setStorageFileName(cities.at(currentCity));
        playCurrentMovie();
    }
}

void VideoOverlay::setupMovies(){
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

void VideoOverlay::playCurrentMovie(){
    backgrounds[cities.at(currentCity)].play();
}

void VideoOverlay::stopCurrentMovie(){
    backgrounds[cities.at(currentCity)].stop();
}

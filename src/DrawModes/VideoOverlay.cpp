#include "VideoOverlay.h"

void VideoOverlay::setup(bool _isProductionMode) {
    isProductionMode = _isProductionMode;
    isProductionMode ?
        projectionMask.setup(HOMOGRAPHY, PRESETS_PRODUCTION) :
        projectionMask.setup(HOMOGRAPHY, PRESETS_DEVELOPMENT);

    currentCity = 0;
    setupBackgroundMovies();
    setupOverlayImages();

    cityClockDrawing.setup(&projectionMask);

    projectionMask.setStorageFileName(cities.at(currentCity));
    background = projectionMask.getBackground();
    ofAddListener(ofEvents().keyPressed, this, &VideoOverlay::keyPressed);
}

void VideoOverlay::update() {
    cityClockDrawing.update();
    if(ofGetFrameNum() == 1){
        projectionMask.setStorageFileName(cities.at(currentCity));
    }
    projectionMask.update(ofGetMouseX(), ofGetMouseY());
    for(auto& background : backgroundMovies){
        background.second.update();
    }
}

void VideoOverlay::drawFirstWindow() {
    background->begin();
    {
        ofPushMatrix();
        ofTranslate(background->getWidth() * 0.5, background->getHeight() * 0.5);
                ofScale(1.03, 1.03);
        ofRotateZ(1.75);
        ofTranslate(-(background->getWidth() * 0.5), -(background->getHeight() * 0.5));
        backgroundMovies[cities.at(currentCity)].draw(0, 0, background->getWidth(), background->getHeight());
        overlayImages[cities.at(currentCity)].draw(0, 0, background->getWidth(), background->getHeight());
        ofPopMatrix();
    }
    background->end();

    cityClockDrawing.draw(cities.at(currentCity));
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

void VideoOverlay::setupBackgroundMovies(){
    string loc = "cities";
    ofDirectory dir(loc);
    dir.listDir();
    vector<ofFile> contents = dir.getFiles();

    for(int i = 0; i < contents.size(); i++){
        cities.push_back(contents.at(i).getBaseName());
        backgroundMovie.load(loc + "/" + contents.at(i).getFileName());
        backgroundMovies[contents.at(i).getBaseName()] = backgroundMovie;
    }
    playCurrentMovie();
}

void VideoOverlay::setupOverlayImages(){
    string loc = "city-overlays";
    ofDirectory dir(loc);
    dir.listDir();
    vector<ofFile> contents = dir.getFiles();

    for(int i = 0; i < contents.size(); i++){
        overlayImage.load(loc + "/" + contents.at(i).getFileName());
        overlayImages[contents.at(i).getBaseName()] = overlayImage;
    }
}

void VideoOverlay::playCurrentMovie(){
    backgroundMovies[cities.at(currentCity)].play();
}

void VideoOverlay::stopCurrentMovie(){
    backgroundMovies[cities.at(currentCity)].stop();
}

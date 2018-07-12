#include "VideoOverlay.h"

void VideoOverlay::setup(bool _isProductionMode) {
    isProductionMode = _isProductionMode;
    isProductionMode ?
        projectionMask.setup(HOMOGRAPHY, PRESETS_PRODUCTION) :
        projectionMask.setup(HOMOGRAPHY, PRESETS_DEVELOPMENT);

    setupCities();
    setupBackgroundMovies();
    setupOverlayImages();
    cityClockDrawing.setup(&projectionMask);
    setCurrentCity("tokyo");
    playCurrentMovie();

    background = projectionMask.getBackground();
    ofAddListener(ofEvents().keyPressed, this, &VideoOverlay::keyPressed);
}

void VideoOverlay::update() {
    cityClockDrawing.update();
    if(ofGetFrameNum() == 1){
        setCurrentCity(currentCity);
    }
    projectionMask.update(ofGetMouseX(), ofGetMouseY());
    newYorkMovie.update();
    tokyoMovie.update();
}

void VideoOverlay::drawFirstWindow() {
    background->begin();
    {
        ofPushMatrix();
        if(currentCity == "newyork"){
            ofTranslate(background->getWidth() * 0.5, background->getHeight() * 0.5);
            ofScale(1.03, 1.03);
            ofRotateZ(1.75);
            ofTranslate(-(background->getWidth() * 0.5), -(background->getHeight() * 0.5));
        }
        drawCurrentMovie();
        drawCurrentOverlayImage();
        ofPopMatrix();
    }
    background->end();

    cityClockDrawing.draw(currentCity);
    projectionMask.drawFirstWindow();
}

void VideoOverlay::drawSecondWindow() {
    projectionMask.drawSecondWindow();
}

void VideoOverlay::keyPressed(ofKeyEventArgs& args){
    if(args.key == 'c' || args.key == 'C') {
        stopCurrentMovie();
        string nextCity;
        if(currentCity == "tokyo"){
            nextCity = "newyork";
        }else if(currentCity == "newyork"){
            nextCity = "tokyo";
        }
        setCurrentCity(nextCity);
        playCurrentMovie();
    }
}

void VideoOverlay::setCurrentCity(string city){
    currentCity = city;
    projectionMask.setStorageFileName(currentCity);
}

void VideoOverlay::setupCities(){
    cities.push_back("tokyo");
    cities.push_back("newyork");
}

void VideoOverlay::setupBackgroundMovies(){
    newYorkMovie.load("cities/newyork.mov");
    newYorkMovie.setVolume(0);
    tokyoMovie.load("cities/tokyo.mp4");
    tokyoMovie.setVolume(0);
}

void VideoOverlay::setupOverlayImages(){
    newYorkOverlayImage.load("city-overlays/newyork.png");
    tokyoOverlayImage.load("city-overlays/tokyo.png");
}

void VideoOverlay::playCurrentMovie(){
    if(currentCity == "tokyo"){
        tokyoMovie.play();
    } else if(currentCity == "newyork"){
        newYorkMovie.play();
    }
}

void VideoOverlay::stopCurrentMovie(){
    if(currentCity == "tokyo"){
        tokyoMovie.stop();
    } else if(currentCity == "newyork"){
        newYorkMovie.stop();
    }
}

void VideoOverlay::drawCurrentMovie(){
    if(currentCity == "tokyo"){
        tokyoMovie.draw(0, 0, background->getWidth(), background->getHeight());
    } else if(currentCity == "newyork"){
        newYorkMovie.draw(0, 0, background->getWidth(), background->getHeight());
    }
}

void VideoOverlay::drawCurrentOverlayImage(){
    if(currentCity == "tokyo"){
        tokyoOverlayImage.draw(0, 0, background->getWidth(), background->getHeight());
    } else if(currentCity == "newyork"){
        newYorkOverlayImage.draw(0, 0, background->getWidth(), background->getHeight());
    }
}

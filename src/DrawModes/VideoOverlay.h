#pragma once

#include "ofMain.h"
#include "ofxProjectionMask.h"
#include "ofxLayerMask.h"
#include "CityClockDrawing.h"

class VideoOverlay {
    
public:
    void setup(bool _isProductionMode);
    void update();
    void drawFirstWindow();
    void drawSecondWindow();
    void keyPressed(ofKeyEventArgs& args);
private:
    void setCurrentCity(string city);
    void setupBackgroundMovies();
    void setupOverlayImages();
    void playCurrentMovie();
    void stopCurrentMovie();
    void drawCurrentMovie();
    void drawCurrentOverlayImage();
    
    ofxProjectionMask projectionMask;
    ofxLayerMask *background;

    ofVideoPlayer newYorkMovie, tokyoMovie;
    ofImage newYorkOverlayImage, tokyoOverlayImage, eiffelTowerImage;

    CityClockDrawing cityClockDrawing;
    
    vector<string> cities;
    string currentCity;
    bool isProductionMode;
};

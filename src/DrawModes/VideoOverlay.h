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
    void setupMovies();
    void playCurrentMovie();
    void stopCurrentMovie();
    
    ofxProjectionMask projectionMask;
    ofxLayerMask *clockFace, *background;
    ofVideoPlayer backgroundMovie;
    map<string, ofVideoPlayer> backgrounds;
    string backgroundsDir;
    CityClockDrawing cityClockDrawing;
    
    vector<string> cities;
    int currentCity;
    bool isProductionMode;
};

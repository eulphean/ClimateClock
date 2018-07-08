#pragma once

#include "ofMain.h"
#include "ofxProjectionMask.h"
#include "ofxLayerMask.h"
#include "Clock.h"

class VideoOverlay {
    
public:
    void setup();
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
    Clock clock;
    
    vector<string> cities;
    int currentCity;
};

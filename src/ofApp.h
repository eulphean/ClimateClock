#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "Clock.h"
#include "ofxProjectionMask.h"
#include "ofxLayerMask.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void setupMovies();
    void update();
    void draw();
    void exit();
    void keyPressed(int key);
  
private:
    void playCurrentMovie();
    void stopCurrentMovie();

    bool hideGui = false;
    Clock clock;

    ofxProjectionMask projectionMask;
    ofxLayerMask *clockFace, *background;
    ofVideoPlayer backgroundMovie;
    map<string, ofVideoPlayer> backgrounds;
    string backgroundsDir;

    vector<string> cities;
    int currentCity;
};

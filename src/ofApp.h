#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "Clock.h"
#include "ClockGrid.h"
#include "ofxProjectionMask.h"
#include "ofxLayerMask.h"

enum ccDrawMode {
    CC_DRAW_GRID,
    CC_DRAW_VIDEOS
};

class ofApp : public ofBaseApp{

public:
    void setup();
    void setupMovies();
    void update();
    void draw();
    void drawSecondWindow(ofEventArgs &args);
    void keyPressed(int key);
    void exit();
  
private:
    bool isInGridMode();
    bool isInVideoMode();

    void playCurrentMovie();
    void stopCurrentMovie();

    ccDrawMode drawMode;

    Clock clock;
    ClockGrid clockGrid;

    ofxProjectionMask projectionMask;
    ofxLayerMask *clockFace, *background;
    ofVideoPlayer backgroundMovie;
    map<string, ofVideoPlayer> backgrounds;
    string backgroundsDir;

    vector<string> cities;
    int currentCity;
};

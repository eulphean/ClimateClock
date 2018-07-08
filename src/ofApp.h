#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "Clock.h"
#include "ClockGrid.h"
#include "VideoOverlay.h"

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

    ccDrawMode drawMode;

    Clock clock;
    ClockGrid clockGrid;
    VideoOverlay videoOverlay;
};

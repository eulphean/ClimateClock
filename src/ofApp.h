#pragma once

#include "ofMain.h"
#include "DrawMode.h"
#include "ClockGrid.h"
#include "VideoOverlay.h"
#include "CenteredClock.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void setupMovies();
    void update();
    void draw();
    void drawSecondWindow(ofEventArgs &args);
    void drawThirdWindow(ofEventArgs &args);
    void exit();
  
private:
    DrawMode drawMode;
    ClockGrid clockGrid;
    VideoOverlay videoOverlay;
    CenteredClock centeredClock;
};

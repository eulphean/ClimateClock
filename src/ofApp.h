#pragma once

#include "ofMain.h"
#include "Clock.h"
#include "ClockGrid.h"
#include "VideoOverlay.h"
#include "DrawMode.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void setupMovies();
    void update();
    void draw();
    void drawSecondWindow(ofEventArgs &args);
    void exit();
  
private:
    Clock clock;
    ClockGrid clockGrid;
    VideoOverlay videoOverlay;
    DrawMode drawMode;
};

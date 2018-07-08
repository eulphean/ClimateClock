#pragma once

#include "ofMain.h"

enum ccDrawMode {
    CC_DRAW_CLOCK_GRID,
    CC_DRAW_VIDEO_OVERLAY
};

class DrawMode {
    
public:
    void setup();
    void next();
    bool isClockGrid();
    bool isVideoOverlay();
    void keyPressed(ofKeyEventArgs& args);
protected:
    ccDrawMode drawMode;
};

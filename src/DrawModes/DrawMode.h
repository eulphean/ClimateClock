#pragma once

#include "ofMain.h"

enum ccDrawMode {
    CC_DRAW_CLOCK_GRID,
    CC_DRAW_VIDEO_OVERLAY
};

class DrawMode {
    
public:
    unsigned long lastTime;
  
    void setup();
    void update();
    void next();
    bool isClockGrid();
    bool isVideoOverlay();
    
    void keyPressed(ofKeyEventArgs& args);
protected:
    ccDrawMode drawMode;
    bool isSequencing = false;
    // Time between switching scenes. 
    unsigned long sequenceTime;
    const int minSequenceTime = 20; // 20 secs
    const int maxSequenceTime = 25; // 25 secs
};

#pragma once

#include "ofMain.h"

enum ccDrawMode {
    CC_DRAW_CLOCK_GRID,
    CC_DRAW_VIDEO_NEWYORK,
    CC_DRAW_VIDEO_TOKYO,
    CC_DRAW_VIDEO_PARIS,
};

class DrawMode {
    
public:
    unsigned long lastTime;
  
    void setup();
    void update();
    void next();
    bool isClockGrid();
    bool isNewYorkOverlay();
    bool isTokyoOverlay();
    bool isParisOverlay();

    void keyPressed(ofKeyEventArgs& args);
protected:
    ccDrawMode drawMode;
    bool isSequencing = false;
    // Time between switching scenes. 
    unsigned long sequenceTime = 30; // Start with 30 seconds. 
};

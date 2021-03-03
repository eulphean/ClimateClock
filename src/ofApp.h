#pragma once

#include "ofMain.h"
#include "WrapperClock.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();
    void handleColorLerp();
    void exit();
  
    void keyPressed(int key);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button); 
  
private:
    WrapperClock wrapperClock;
    bool hideGui;
    ofImage bg;
  
    // Background color lerp
    std::vector<ofColor> colors; ofColor start; ofColor end;
    ofColor lerped;
    float lerpAmt;
    int curColIdx;
  
    bool pressed;
};

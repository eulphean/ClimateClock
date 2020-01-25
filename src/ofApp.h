#pragma once

#include "ofMain.h"
#include "CenteredClock.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();
    void exit();
  
    void keyPressed(int key);
  
private:
    CenteredClock centeredClock;
    bool hideGui;
    ofImage bg; 
};

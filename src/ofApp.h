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
    void mousePressed(int x, int y, int button);
  
private:
    CenteredClock centeredClock;
    bool hideGui;
    ofImage bg; 
};

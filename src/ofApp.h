#pragma once

#include "ofMain.h"
#include "CenteredClock.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();
    void exit();
  
private:
    CenteredClock centeredClock;
};

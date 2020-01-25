#pragma once

#include "ofMain.h"
#include "Clock.h"
#include "ofxGui.h"

class CenteredClock {
    
public:
    void setup();
    void update();
    void draw(bool hideGui);
    void nextTimezone();
    void exit();
    
protected:
    Clock clock;
  
    // GUI parameters for Centered Clock. 
    ofxPanel gui;
    ofParameter<float> xPosition { "X Position", 50, -1000, 1000 }; // Distance between 2 consecutive words.
    ofParameter<float> yPosition { "Y Position", 80, 40, 1000 };
    ofParameter<float> xScale { "X Scale", 1, 0.5, 10 };
    ofParameter<float> yScale { "Y Scale", 1, 0.5, 10 };
  
    std::vector<string> timezones;
    int timezoneIdx;
  
    long currentTime;
    long maxWaitTime;
};

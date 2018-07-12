#pragma once

#include "ofMain.h"
#include "Clock.h"
#include "ofxGui.h"

class CenteredClock {
    
public:
    void setup(bool _isProductionMode);
    void update();
    void drawFirstWindow();
    void drawThirdWindow();
    void exit();
    
protected:
    void setupThirdWindow();
    Clock clock;
    bool isThirdWindowSetup, isProductionMode;
  
    // GUI parameters for Centered Clock. 
    ofxPanel gui;
    ofParameter<float> xPosition { "X Position", 50, -1000, 1000 }; // Distance between 2 consecutive words.
    ofParameter<float> yPosition { "Y Position", 80, 40, 1000 };
    ofParameter<float> xScale { "X Scale", 1, 1, 10 };
    ofParameter<float> yScale { "Y Scale", 1, 1, 10 };
};

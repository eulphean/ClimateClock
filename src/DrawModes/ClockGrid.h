#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "Clock.h"

class ClockGrid {

  public:
    void setup();
    void update();
    void drawFirstWindow();
    void drawSecondWindow();
    void exit();
    
    void windowResized(int w, int h);
    void updateFromGui(int & val);
  
  private:
    void createGrid();
    void loadTimeZones();
    string selectTimeZone();

    bool recreateGrid = false;

    vector<Clock> clocks;

    vector<string> timeZones;
    vector<int> tzIndices;

    ofxPanel gui;
    ofColor backgroundColor = ofColor(52,52,52,255);
    ofParameter<int> xOffset { "X Offset", 5, 0, 200 };
    ofParameter<int> yOffset { "Y Offset", 5, 0, 200 };
    ofParameter<int> clockWidth { "Clock Width", 300, 200, 500 }; // Distance between 2 consecutive words.
    ofParameter<int> clockHeight { "Clock Height", 80, 40, 200 };
};

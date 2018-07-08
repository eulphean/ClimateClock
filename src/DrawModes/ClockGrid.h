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
    ofxColorSlider backgroundColor;
    ofParameter<int> clockWidth { "Clock Width", 300, 200, 350 }; // Distance between 2 consecutive words.
    ofParameter<int> clockHeight { "Clock Height", 80, 40, 150 };
    ofParameter<int> xPadding { "X Padding", 10, 0, 100 };
    ofParameter<int> yPadding { "Y Padding", 10, 0, 100 };
};

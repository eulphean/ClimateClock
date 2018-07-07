#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "Clock.h"

class SecondApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    void exit();
    
    void keyPressed(int key);
    void windowResized(int w, int h);
    void updateFromGui(int & val);
  
  private:
    void createGrid();
    void loadTimeZones();
    string selectTimeZone();
    
    // flags
    bool hideGui = false;
    bool recreateGrid = false;
  
    // Grid clocks.
    std::vector<Clock> clocks;
  
    // Timezones
    std::vector<string> timeZones; // All the timezones
    std::vector<int> tzIndices; // Current timezone indices in the grid.
  
    // Gui.
    ofxPanel gui;
    ofxColorSlider backgroundColor;
    ofParameter<int> clockWidth { "Clock Width", 300, 200, 350 }; // Distance between 2 consecutive words.
    ofParameter<int> clockHeight { "Clock Height", 80, 40, 150 };
    ofParameter<int> xPadding { "X Padding", 10, 0, 100 };
    ofParameter<int> yPadding { "Y Padding", 10, 0, 100 };
};

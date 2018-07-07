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
  
  private:
    void createGrid();
    
    // flags
    bool hideGui = false;
  
    // Calculated from a fabricated clock.
    const int clockWidth = 300;
    const int clockHeight = 80;
  
    // Clock
    Clock clock;
  
    // Grid clocks.
    std::vector<Clock> clocks;
  
    // Gui.
    ofxPanel gui;
    ofxColorSlider backgroundColor;
};

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
  
  private:
    // flags
    bool hideGui = false;
  
    // Clock
    Clock clock;
  
    // Gui.
    ofxPanel gui;
    ofxColorSlider backgroundColor;
};

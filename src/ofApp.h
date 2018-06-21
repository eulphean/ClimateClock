#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "Clock.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    void exit();
    
    void keyPressed(int key);
  
  private:
    // flags
    bool hideGui = false;
    
    // Last recorded time. 
    unsigned long int lastTimeMillis;
  
    // Clock
    Clock myClock;
  
    ofxPanel gui;
    // TODO: Add clock setting commands
    // in the GUI. For now, just give
    // formatting commands. 
};

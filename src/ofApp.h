#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
  
    void keyPressed(int key);
    
    ofTrueTypeFont trueSeconds;
    ofTrueTypeFont trueMinutes;
  
    // Cycle fonts.
    int curFontIdx = 0;
    vector<string> fonts;
  
    int minutes; int seconds;
};

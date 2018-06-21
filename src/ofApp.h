#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
  
    void updateCarbonClock();
    
    void keyPressed(int key);
  
    // Constants for the time. 
    int years = 18;
    ofTrueTypeFont trueYears;
  
    int days = 198;
    ofTrueTypeFont trueDays;
  
    int hours = 1;
    ofTrueTypeFont trueHours;
  
    int minutes = 53;
    ofTrueTypeFont trueMinutes;
  
    int seconds = 59;
    ofTrueTypeFont trueSeconds;
  
    // Last recorded time. 
    unsigned long int lastTimeMillis;
  
    // Cycle fonts.
    int curFontIdx = 0;
    vector<string> fonts;  
};

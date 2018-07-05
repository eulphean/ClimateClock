#pragma once

#include "ofParameter.h"
#include "ofParameterGroup.h"
#include "ofMain.h"
#include "ofxGui.h"
#include "tz.h"

using namespace date;

class Clock {
  public:
    void setup();
    void update();
    void draw();
    void cycleFont(bool forward);
    string currentFont();
    void setCurrentFont(int idx);
  
    // GUI parameters.
    ofParameter<float> wordSpacing { "Word Spacing", 10.0, 5.0, 100.0 }; // Distance between 2 consecutive words.
    ofParameter<float> xPosition { "X Position", 5, -ofGetWidth(), ofGetWidth() };
    ofParameter<float> yPosition { "Y Position", 50, -ofGetHeight(), ofGetHeight() };
    ofParameter<int> fontSize { "Font Size", 15, 5, 500 };
    ofxColorSlider textColor;
  
    // GUI group.
    ofParameterGroup formatParams { "Format", wordSpacing, xPosition, yPosition, fontSize };
  
  private:
    void drawWords(int idx);
    void createWords();
    //date::sys_time<chrono::milliseconds> createFutureTime(date::time_zone *zone);
  
    // GUI listeners
    void updateFromGui(int & val);
    void updateDays(int & val);
    void updateHours(int & val);
    void updateMinutes(int & val);
    void updateSeconds(int & val);

    // 18 years, 198 days, 1 hrs, 50 mins, 34 secs
    // 10 unique words.
    // 0 - years, 2 - days, 4 - hours, 6 - minutes, 8 - seconds
    const int numWords = 10;
    std::vector<ofTrueTypeFont> clock;
  
    // Default clock time. 
    int days; int hours; int minutes; int seconds; int milliseconds; 
  
    vector<string> fonts;
  
    // Cycle fonts.
    int curFontIdx = 3;
  
    int currentX;
};

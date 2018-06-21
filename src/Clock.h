#pragma once

#include "ofParameter.h"
#include "ofParameterGroup.h"
#include "ofMain.h"

class Clock {
  public:
    void setup();
    void update();
    void draw();
    void cycleFont(bool forward);
  
    // GUI parameters.
    ofParameter<float> wordSpacing { "Word Spacing", 10.0, 5.0, 100.0 }; // Distance between 2 consecutive words.
  
    ofParameter<float> xPosition { "X Position", 50, -ofGetWidth(), ofGetWidth() };
    ofParameter<int> fontSize { "Font Size", 15, 5, 100 };
  
    // GUI group.
    ofParameterGroup parameters { "Clock", wordSpacing, xPosition, fontSize };
  
  private:
    void drawWords(int idx);
    void updateFromGui(int & val);
    void createWords();
  
    // 18 years, 198 days, 1 hrs, 50 mins, 34 secs
    // 10 unique word.
    // 0 - years, 2 - days, 4 - hours, 6 - minutes, 8 - seconds
    const int numWords = 10;
    std::vector<ofTrueTypeFont> clock;
  
    // Default clock time. 
    int years = 18; int days = 198; int hours = 1; int minutes = 53; int seconds = 59;
  
    // Cycle fonts.
    int curFontIdx = 0;
    vector<string> fonts;
  
    int currentX;
};

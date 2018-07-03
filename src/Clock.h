#pragma once

#include "ofParameter.h"
#include "ofParameterGroup.h"
#include "ofMain.h"
#include "ofxGui.h"

class Clock {
  public:
    void setup();
    void update();
    void draw();
    void cycleFont(bool forward);
    string currentFont();
  
    // GUI parameters.
    ofParameter<float> wordSpacing { "Word Spacing", 10.0, 5.0, 100.0 }; // Distance between 2 consecutive words.
    ofParameter<float> xPosition { "X Position", 5, -ofGetWidth(), ofGetWidth() };
    ofParameter<float> yPosition { "Y Position", 50, -ofGetHeight(), ofGetHeight() };
    ofParameter<int> fontSize { "Font Size", 15, 5, 100 };
    ofxColorSlider textColor;
  
    ofParameter<int> daysField { "Days", 195, 0, 198 };
    ofParameter<int> hoursField { "Hours", 1, 0, 23 };
    ofParameter<int> minutesField { "Minutes", 53, 0, 59 };
    ofParameter<int> secondsField { "Seconds", 59, 0, 59 };
  
    // GUI group.
    ofParameterGroup formatParams { "Format", wordSpacing, xPosition, fontSize };
    ofParameterGroup clockParams { "Clock", daysField, hoursField, minutesField, secondsField };
  
  private:
    void drawWords(int idx);
    void createWords();
  
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
    int years = 18; int days = 195; int hours = 1; int minutes = 53; int seconds = 59;
  
    // Cycle fonts.
    int curFontIdx = 3;
    vector<string> fonts;
  
    int currentX;
};

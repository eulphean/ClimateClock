#pragma once

#include "ofParameter.h"
#include "ofParameterGroup.h"
#include "ofMain.h"
#include "ofxGui.h"
#include "Date/tz.h"

using namespace date;

// Place
enum PlaceValue {
  Ten,
  Hundred,
  Thousand
};

class Clock {
  public:
    Clock();
    ~Clock();
    void setup();
    void update();
    void draw();
    void cycleFont(bool forward);
    string currentFont();
    void setCurrentFont(int idx);
  
    // GUI parameters.
    ofParameter<float> wordSpacing { "Word Spacing", 11.3, 5.0, 100.0 }; // Distance between 2 consecutive words.
    ofParameter<float> xPosition { "X Position", 5, 0, ofGetWidth() };
    ofParameter<float> yPositionTime { "Y Position (Time)", 50, 0, ofGetHeight() };
    ofParameter<int> fontSizeTime { "Font Size Time", 30, 5, 500 };
    ofParameter<int> fontSizeTitle { "Font Size Title", 22, 5, 500 };
    ofParameter<int> yPositionTitle { "Y Position (Title)", 23, 20, ofGetHeight()/2 };
    //ofxColorSlider textColor;
  
    // GUI group.
    ofParameterGroup formatParams { "Format", wordSpacing, xPosition, yPositionTime, fontSizeTime, fontSizeTitle, yPositionTitle };
  
    // Returns the dimension of the clock.
    int getHeight();
    int getWidth();
  
  private:
    void drawTime(int idx);
    void drawTimeTitle(int idx, string timeToPrint, string title);
    string placeValueTime(int unit, PlaceValue place); // Create the time string based on its Units place.
    void createTimeWords();
    void createTitleWords();
    void updateTime();
  
    // GUI listeners
    void updateTimeFont(int & val);
    void updateTitleFont(int & val);

    // 6756  15   11   11   221 <- Line 1 (5 words)
    // Days  Hrs Mins Secs mSecs <- Line 2 (5 words)
  
    const int numWordsTime = 5; // Line 1
    std::vector<ofTrueTypeFont> time;
    int currentX;
  
    const int numWordsTitle = 5; // Line 2
    std::vector<ofTrueTypeFont> title;
  
    // Clock parameters
    int days; int hours; int minutes; int seconds; int milliseconds; 
  
    // Cycle fonts.
    int curFontIdx = 3;
    vector<string> fonts;
};

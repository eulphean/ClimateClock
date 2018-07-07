#pragma once

#include "ofParameter.h"
#include "ofParameterGroup.h"
#include "ofMain.h"
#include "ofxGui.h"
#include "Date/tz.h"

// Place
enum PlaceValue {
  Ten,
  Hundred,
  Thousand
};

class Clock {
  public:
    void setup();
    void update();

    // Generic method that draws the entire clock
    void drawClock();
  
    // Custom draw methods (for projection mask).
    // Default x, y parameters for custom position.
    void drawYears(int x, int y); void drawYearsTitle(int x, int y);
    void drawDays(int x, int y); void drawDaysTitle(int x, int y);
    void drawHrs(int x, int y); void drawHrsTitle(int x, int y);
    void drawMins(int x, int y); void drawMinsTitle(int x, int y);
    void drawSecs(int x, int y); void drawSecsTitle(int x, int y);
  
    // Setters
    void setCurrentFont(int idx);
    void setTextColor(ofColor color);
    void setPosition (float x, float y);
    void setTimeZone (string timezone);
  
    // Getters
    string currentFont();
  
    // Utility functions.
    void cycleFont(bool forward);
  
    // TODO: Clean GUI parameters. 
    // GUI parameters.
    ofParameter<float> wordSpacing { "Word Spacing", 11.3, 5.0, 100.0 }; // Distance between 2 consecutive words.
    ofParameter<float> xPosition { "X Position", 5, 0, ofGetWidth() };
    ofParameter<float> yPositionTime { "Y Position (Time)", 50, 0, ofGetHeight() };
    ofParameter<int> fontSizeTime { "Font Size Time", 30, 5, 500 };
    ofParameter<int> fontSizeTitle { "Font Size Title", 22, 5, 500 };
    ofParameter<int> yPositionTitle { "Y Position (Title)", 23, 20, ofGetHeight()/2 };
  
    // GUI group.
    ofParameterGroup formatParams { "Format", wordSpacing, xPosition, yPositionTime, fontSizeTime, fontSizeTitle, yPositionTitle };
  
  private:
    void drawTimeTitle(int idx, string timeToPrint, string title);
    string placeValueTime(int unit, PlaceValue place); // Create the time string based on its Units place.
    void createTimeWords();
    void createTitleWords();
    void updateTime();
  
    // GUI listeners
    void updateTimeFont(int & val);
    void updateTitleFont(int & val);

    //  18   181  15   11   11  <- Line 1 (5 words)
    // Years Days Hrs Mins Secs <- Line 2 (5 words)
    const int numWordsTime = 5; // Line 1
    std::vector<ofTrueTypeFont> time;
    int currentX;
  
    const int numWordsTitle = 5; // Line 2
    std::vector<ofTrueTypeFont> title;
  
    // Clock parameters
    int years; int days; int hours; int minutes; int seconds; int milliseconds;
  
    // Text color.
    ofColor textColor;
  
    // Cycle fonts.
    int curFontIdx = 3;
    vector<string> fonts;
  
    // Timezone.
    string timeZone = "America/Chicago"; // Default Timezone. 
};

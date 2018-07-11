#pragma once

#include "ofParameter.h"
#include "ofParameterGroup.h"
#include "ofMain.h"
#include "ofxGui.h"
#include "ofxXmlSettings.h"
#include "Date/tz.h"

// Place
enum PlaceValue {
  Ten,
  Hundred,
  Thousand
};

// Position
enum PositionMode {
    POSITION_MODE_CENTERED,
    POSITION_MODE_NORMAL
};

class Clock {
  public:
    void setup(string fileName = " ", PositionMode _positionMode = POSITION_MODE_NORMAL);
    void update();

    // Generic method that draws the entire clock
    void drawClock();
  
    // Custom draw methods (for projection mask).
    // Default x, y parameters for custom position.
    void drawYears(int x=0, int y=0); void drawYearsTitle(int x=0, int y=0);
    void drawDays(int x=0, int y=0); void drawDaysTitle(int x=0, int y=0);
    void drawHrs(int x=0, int y=0); void drawHrsTitle(int x=0, int y=0);
    void drawMins(int x=0, int y=0); void drawMinsTitle(int x=0, int y=0);
    void drawSecs(int x=0, int y=0); void drawSecsTitle(int x=0, int y=0);
  
    // Setters
    void setTextColor(ofColor color);
    void setPosition (float x, float y);
    void setTimeZone (string timezone);
  
  private:
    void drawTimeTitle(int idx, string timeToPrint, string title);
    string placeValueTime(int unit, PlaceValue place); // Create the time string based on its Units place.
    void createTimeWords();
    void createTitleWords();
    void updateTime();
    void translate(int x, int y, ofTrueTypeFont& font, string str);
  
    // XML instance.
    ofxXmlSettings settings;
  
    // Clock format parameters.
    ofColor fontColor = ofColor::white;
    float wordSpacing = 11.3;
    int fontSizeTime = 30;
    int fontSizeTitle = 12;
    int yPositionTitle = 23;
    string fontTime = "instruction.otf";
    string fontTitle = "instruction.otf";
    string timeZone = "America/Chicago";
    float xPosition; float yPosition;
    PositionMode positionMode;

    //  18   181  15   11   11  <- Line 1 (5 words)
    // Years Days Hrs Mins Secs <- Line 2 (5 words)
    const int numWordsTime = 5; // Line 1
    std::vector<ofTrueTypeFont> time;
    int currentX;
  
    const int numWordsTitle = 5; // Line 2
    std::vector<ofTrueTypeFont> title;
  
    // Clock parameters
    int years; int days; int hours; int minutes; int seconds; int milliseconds;
};

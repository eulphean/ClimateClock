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
    void setup(string guiXml = " ");
    void update();
    void exit();

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
  
    // GUI
    void drawGui();
  
    // Hide border and don't use GUI for adjusting
    // GUI offset.
    bool hideRoundedBorder = false;
    bool guiXOffsetForCity = false;
  
  private:
    void drawSeperator();
    string getCityFromTimezone();
    void drawTimeTitle(int idx, string timeToPrint, string timeForSize, string title);
    string placeValueTime(int unit, PlaceValue place); // Create the time string based on its Units place.
    void createTimeWords();
    void createTitleWords();
    void createSeperators();
    void createProjectTitle();
    void createIPCCTitle();
    void createCity();
    void updateTime();
    void translate(int x, int y, ofTrueTypeFont& font, string str);
  
    // Clock format parameters. Some of them are in GUI
    // to be able to format the clock properly.
    ofxPanel gui;
    ofParameter<float> wordSpacing { "Word Spacing", 8, 5, 20 }; // Distance between 2 consecutive words.
    ofParameter<float> yPositionTitle { "Title Position", -45, -3000, 1000 };
    ofParameter<float> roundedRectWidth { "Rounded Rect Width", 310, 50, 3000 };
    ofParameter<float> roundedRectHeight { "Rounded Rect Height", 40, 10, 500 };
    ofParameter<float> rectXOffset { "Rect X Offset", 5, 0, 1000 };
    ofParameter<float> rectYOffset { "Rect Y Offset", 35, 0, 1000 };
    ofParameter<float> cityYOffset { "City Y Offset", 35, -1000, 1000 };
    ofParameter<float> cityXOffset { "City X Offset", 35, 0, 1000 };
    ofParameter<float> projectTitleXOffset { "Project Title X Offset", 35, -1000, 1000 };
    ofParameter<float> projectTitleYOffset { "Project Title Y Offset", 35, -1000, 1000 };
    ofParameter<float> ipccTitleXOffset { "IPCC Title X Offset", 35, -1000, 1000 };
    ofParameter<float> ipccTitleYOffset { "IPCC Title Y Offset", 35, -1000, 1000 };
    
    int fontSizeTime;
    int fontSizeTitle;
    int fontSizeCity;
    int fontSizeProjectTitle;
    int fontSizeIpccTitle;
    ofColor fontColor;
    ofColor fontTitleColor;
    ofColor fontCityColor;
    string fontTime;
    string fontTitle;
    string timeZone;
    float xPosition; float yPosition;

    //  18   181  15   11   11  <- Line 1 (5 words)
    // Years Days Hrs Mins Secs <- Line 2 (5 words)
    const int numWordsTime = 5; // Line 1
    std::vector<ofTrueTypeFont> time;
    int currentX;
  
    const int numWordsTitle = 5; // Line 2
    std::vector<ofTrueTypeFont> title;
  
    // 18 : 181 : 15 : 11 : 11 (:)
    const int numSeperators = 4;
    std::vector<ofTrueTypeFont> seperators;
  
    // City
    ofTrueTypeFont city; 
  
    // Clock parameters
    int years; int days; int hours; int minutes; int seconds; int milliseconds;
  
    ofTrueTypeFont projectTitle;
    ofTrueTypeFont ipccTitle;
  
    // Gui Xml file.
    string guiXmlFile;
};

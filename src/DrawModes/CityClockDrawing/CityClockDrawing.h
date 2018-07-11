#pragma once

#include "ofMain.h"
#include "ofxLayerMask.h"
#include "ofxProjectionMask.h"
#include "Clock.h"

class CityClockDrawing {
    
public:
    void setup(ofxProjectionMask* projectionMask);
    void update();
    void draw(string city);
protected:
    void drawNewYorkBuffers();
    void drawTokyoBuffers();
    void drawNewYorkYears();
    void drawNewYorkYearsLabel();
    void drawNewYorkDays();
    void drawNewYorkDaysLabel();
    void drawNewYorkHours();
    void drawNewYorkHoursLabel();
    void drawNewYorkMinutes();
    void drawNewYorkMinutesLabel();
    void drawNewYorkSeconds();
    void drawNewYorkSecondsLabel();

    int numFacePartsNYC = 10;
    ofxLayerMask* clockFace;
    vector<ofxLayerMask*> clockFaceParts;
    int bufferSize, halfBufferSize;

    Clock nycClock, tokyoClock;
    ofColor nycBgColor;
};

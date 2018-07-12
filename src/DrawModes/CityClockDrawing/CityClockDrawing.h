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

    void drawTokyoBuffers();
    void drawTokyoYears();
    void drawTokyoYearsLabel();
    void drawTokyoDays();
    void drawTokyoDaysLabel();
    void drawTokyoHours();
    void drawTokyoHoursLabel();
    void drawTokyoMinutes();
    void drawTokyoMinutesLabel();
    void drawTokyoSeconds();
    void drawTokyoSecondsLabel();

    int numFacePartsNYC = 10;
    ofxLayerMask* clockFace;
    vector<ofxLayerMask*> clockFaceParts;
    int bufferSize, halfBufferSize;

    Clock nycClock, tokyoClock;
};

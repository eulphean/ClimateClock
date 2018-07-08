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

    int numPatterns = 3;
    ofxLayerMask* clockFace;
    vector<ofxLayerMask*> clockFaceParts;
    Clock clock;
};

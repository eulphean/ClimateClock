#pragma once

#include "ofMain.h"
#include "ofxLayerMask.h"
#include "Clock.h"

class CityClockDrawing {
    
public:
    void setup(ofxLayerMask* _layerMask);
    void update();
    void draw(string city);
protected:
    void drawNewYorkBuffers();
    void drawTokyoBuffers();
    ofxLayerMask* layerMask;
    Clock clock;
};

#include "CityClockDrawing.h"

void CityClockDrawing::setup(ofxProjectionMask* projectionMask) {
    clock.setup();
    clockFace = projectionMask->newPattern(1080, 860);
    for(int i = 0; i < numPatterns; i++){
        clockFaceParts.push_back(projectionMask->newPattern(400, 400));
    }
}

void CityClockDrawing::update() {
    clock.update();
}

void CityClockDrawing::draw(string city) {
    if(city == "newyork"){
        drawNewYorkBuffers();
    } else if(city == "tokyo") {
        drawTokyoBuffers();
    }
}

void CityClockDrawing::drawNewYorkBuffers() {
    clockFace->begin();
    {
        ofBackground(ofColor::white);
        clock.drawClock();
    }
    clockFace->end();
}

void CityClockDrawing::drawTokyoBuffers() {
    clockFace->begin();
    {
        ofBackground(ofColor::white);
        clock.drawClock();
    }
    clockFace->end();
}

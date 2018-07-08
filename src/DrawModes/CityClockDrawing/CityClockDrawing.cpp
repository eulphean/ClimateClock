#include "CityClockDrawing.h"

void CityClockDrawing::setup(ofxProjectionMask* projectionMask) {
    clock.setup();
    clockFace = projectionMask->newPattern(1080, 860);
    for(int i = 0; i < numPatterns; i++){
        clockFaceParts.push_back(projectionMask->newPattern(80, 35));
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
        ofClear(0, 0, 0, 0);
    }
    clockFace->end();
    
    clockFaceParts.at(0)->begin();
    {
        ofBackground(ofColor::green);
        clock.drawDays(3, 30);
    }
    clockFaceParts.at(0)->end();

    clockFaceParts.at(1)->begin();
    {
        ofBackground(ofColor::green);
        clock.drawHrs(3, 30);
    }
    clockFaceParts.at(1)->end();

    clockFaceParts.at(2)->begin();
    {
        ofBackground(ofColor::green);
        clock.drawMins(3, 30);
    }
    clockFaceParts.at(2)->end();
}

void CityClockDrawing::drawTokyoBuffers() {
    clockFace->begin();
    {
        ofBackground(ofColor::white);
        clock.drawClock();
    }
    clockFace->end();
}

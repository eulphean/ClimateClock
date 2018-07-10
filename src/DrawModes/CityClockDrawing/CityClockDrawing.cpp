#include "CityClockDrawing.h"

void CityClockDrawing::setup(ofxProjectionMask* projectionMask) {
    nycClock.setup("newyork.xml");
    tokyoClock.setup("tokyo.xml");

    clockFace = projectionMask->newPattern(1080, 860);
    for(int i = 0; i < numFacePartsNYC; i++){
        clockFaceParts.push_back(projectionMask->newPattern(80, 35));
    }
}

void CityClockDrawing::update() {
    nycClock.update();
    tokyoClock.update();
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
        nycClock.drawDays(3, 30);
    }
    clockFaceParts.at(0)->end();

    clockFaceParts.at(1)->begin();
    {
        ofBackground(ofColor::green);
        nycClock.drawHrs(3, 30);
    }
    clockFaceParts.at(1)->end();

    clockFaceParts.at(2)->begin();
    {
        ofBackground(ofColor::green);
        nycClock.drawMins(3, 30);
    }
    clockFaceParts.at(2)->end();
}

void CityClockDrawing::drawTokyoBuffers() {
    clockFace->begin();
    {
        ofBackground(ofColor::white);
        tokyoClock.drawClock();
    }
    clockFace->end();
}

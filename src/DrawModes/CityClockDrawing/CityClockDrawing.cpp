#include "CityClockDrawing.h"

void CityClockDrawing::setup(ofxLayerMask* _layerMask) {
    layerMask = _layerMask;
    clock.setup();
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
    layerMask->begin();
    {
        ofBackground(ofColor::white);
        clock.drawClock();
    }
    layerMask->end();
}

void CityClockDrawing::drawTokyoBuffers() {
    layerMask->begin();
    {
        ofBackground(ofColor::white);
        clock.drawClock();
    }
    layerMask->end();
}

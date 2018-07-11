#include "CityClockDrawing.h"

void CityClockDrawing::setup(ofxProjectionMask* projectionMask) {
    nycClock.setup("newyork.xml", POSITION_MODE_CENTERED);
    tokyoClock.setup("tokyo.xml", POSITION_MODE_CENTERED);
    nycBgColor.setHex(0x515256);
    bufferSize = 200;
    halfBufferSize = bufferSize * 0.5;

    clockFace = projectionMask->newPattern(1080, 860);
    for(int i = 0; i < numFacePartsNYC; i++){
        clockFaceParts.push_back(projectionMask->newPattern(bufferSize, bufferSize));
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
    ofClear(0, 0, 0, 0);
    clockFace->end();
    
    clockFaceParts.at(0)->begin();
    drawNewYorkYears();
    clockFaceParts.at(0)->end();
    
    clockFaceParts.at(1)->begin();
    drawNewYorkYearsLabel();
    clockFaceParts.at(1)->end();
    
    clockFaceParts.at(2)->begin();
    drawNewYorkDays();
    clockFaceParts.at(2)->end();
    
    clockFaceParts.at(3)->begin();
    drawNewYorkDaysLabel();
    clockFaceParts.at(3)->end();
    
    clockFaceParts.at(4)->begin();
    drawNewYorkHours();
    clockFaceParts.at(4)->end();
    
    clockFaceParts.at(5)->begin();
    drawNewYorkHoursLabel();
    clockFaceParts.at(5)->end();
    
    clockFaceParts.at(6)->begin();
    drawNewYorkMinutes();
    clockFaceParts.at(6)->end();
    
    clockFaceParts.at(7)->begin();
    drawNewYorkMinutesLabel();
    clockFaceParts.at(7)->end();
    
    clockFaceParts.at(8)->begin();
    drawNewYorkSeconds();
    clockFaceParts.at(8)->end();
    
    clockFaceParts.at(9)->begin();
    drawNewYorkSecondsLabel();
    clockFaceParts.at(9)->end();
}

void CityClockDrawing::drawTokyoBuffers() {
    clockFace->begin();
    {
        ofBackground(ofColor::white);
        tokyoClock.drawClock();
    }
    clockFace->end();
}

void CityClockDrawing::drawNewYorkYears(){
    ofBackground(nycBgColor);
    nycClock.drawYears(halfBufferSize, halfBufferSize);
}

void CityClockDrawing::drawNewYorkYearsLabel(){
    ofClear(0, 0, 0, 0);
    nycClock.drawYearsTitle(halfBufferSize, halfBufferSize);
}

void CityClockDrawing::drawNewYorkDays(){
    ofBackground(nycBgColor);
    nycClock.drawDays(halfBufferSize, halfBufferSize);
}

void CityClockDrawing::drawNewYorkDaysLabel(){
    ofClear(0, 0, 0, 0);
    nycClock.drawDaysTitle(halfBufferSize, halfBufferSize);
}

void CityClockDrawing::drawNewYorkHours(){
    ofBackground(nycBgColor);
    nycClock.drawHrs(halfBufferSize, halfBufferSize);
}

void CityClockDrawing::drawNewYorkHoursLabel(){
    ofClear(0, 0, 0, 0);
    nycClock.drawHrsTitle(halfBufferSize, halfBufferSize);
}

void CityClockDrawing::drawNewYorkMinutes(){
    ofBackground(nycBgColor);
    nycClock.drawMins(halfBufferSize, halfBufferSize);
}

void CityClockDrawing::drawNewYorkMinutesLabel(){
    ofClear(0, 0, 0, 0);
    nycClock.drawMinsTitle(halfBufferSize, halfBufferSize);
}

void CityClockDrawing::drawNewYorkSeconds(){
    ofBackground(nycBgColor);
    nycClock.drawSecs(halfBufferSize, halfBufferSize);
}

void CityClockDrawing::drawNewYorkSecondsLabel(){
    ofClear(0, 0, 0, 0);
    nycClock.drawSecsTitle(halfBufferSize, halfBufferSize);
}

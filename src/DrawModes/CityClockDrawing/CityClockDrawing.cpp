#include "CityClockDrawing.h"

void CityClockDrawing::setup(ofxProjectionMask* projectionMask) {
    nycClock.setup("newyork.xml", POSITION_MODE_CENTERED);
    tokyoClock.setup("tokyo.xml", POSITION_MODE_CENTERED);
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
    ofClear(0, 0, 0, 0);
    nycClock.drawYears(halfBufferSize, halfBufferSize);
    nycClock.drawYears(halfBufferSize + 2, halfBufferSize);
    nycClock.drawYears(halfBufferSize, halfBufferSize + 2);
    nycClock.drawYears(halfBufferSize + 2, halfBufferSize + 2);
    ofSetColor(0, 0, 0, 64);
    ofDrawRectangle(0, 0, bufferSize, bufferSize);
}

void CityClockDrawing::drawNewYorkYearsLabel(){
    ofClear(0, 0, 0, 0);
    nycClock.drawYearsTitle(halfBufferSize, halfBufferSize);
    nycClock.drawYearsTitle(halfBufferSize + 2, halfBufferSize);
    nycClock.drawYearsTitle(halfBufferSize, halfBufferSize + 2);
    nycClock.drawYearsTitle(halfBufferSize + 2, halfBufferSize + 2);
    ofSetColor(0, 0, 0, 16);
    ofDrawRectangle(0, 0, bufferSize, bufferSize);
}

void CityClockDrawing::drawNewYorkDays(){
    ofClear(0, 0, 0, 0);
    nycClock.drawDays(halfBufferSize, halfBufferSize);
    nycClock.drawDays(halfBufferSize + 2, halfBufferSize);
    nycClock.drawDays(halfBufferSize, halfBufferSize + 2);
    nycClock.drawDays(halfBufferSize + 2, halfBufferSize + 2);
    ofSetColor(0, 0, 0, 64);
    ofDrawRectangle(0, 0, bufferSize, bufferSize);
}

void CityClockDrawing::drawNewYorkDaysLabel(){
    ofClear(0, 0, 0, 0);
    nycClock.drawDaysTitle(halfBufferSize, halfBufferSize);
    nycClock.drawDaysTitle(halfBufferSize + 2, halfBufferSize);
    nycClock.drawDaysTitle(halfBufferSize, halfBufferSize + 2);
    nycClock.drawDaysTitle(halfBufferSize + 2, halfBufferSize + 2);
    ofSetColor(0, 0, 0, 16);
    ofDrawRectangle(0, 0, bufferSize, bufferSize);
}

void CityClockDrawing::drawNewYorkHours(){
    ofClear(0, 0, 0, 0);
    nycClock.drawHrs(halfBufferSize, halfBufferSize);
    nycClock.drawHrs(halfBufferSize + 2, halfBufferSize);
    nycClock.drawHrs(halfBufferSize, halfBufferSize + 2);
    nycClock.drawHrs(halfBufferSize + 2, halfBufferSize + 2);
    ofSetColor(0, 0, 0, 64);
    ofDrawRectangle(0, 0, bufferSize, bufferSize);
}

void CityClockDrawing::drawNewYorkHoursLabel(){
    ofClear(0, 0, 0, 0);
    nycClock.drawHrsTitle(halfBufferSize, halfBufferSize);
    nycClock.drawHrsTitle(halfBufferSize + 2, halfBufferSize);
    nycClock.drawHrsTitle(halfBufferSize, halfBufferSize + 2);
    nycClock.drawHrsTitle(halfBufferSize + 2, halfBufferSize + 2);
    ofSetColor(0, 0, 0, 16);
    ofDrawRectangle(0, 0, bufferSize, bufferSize);
}

void CityClockDrawing::drawNewYorkMinutes(){
    ofClear(0, 0, 0, 0);
    nycClock.drawMins(halfBufferSize, halfBufferSize);
    nycClock.drawMins(halfBufferSize + 2, halfBufferSize);
    nycClock.drawMins(halfBufferSize, halfBufferSize + 2);
    nycClock.drawMins(halfBufferSize + 2, halfBufferSize + 2);
    ofSetColor(0, 0, 0, 64);
    ofDrawRectangle(0, 0, bufferSize, bufferSize);
}

void CityClockDrawing::drawNewYorkMinutesLabel(){
    ofClear(0, 0, 0, 0);
    nycClock.drawMinsTitle(halfBufferSize, halfBufferSize);
    nycClock.drawMinsTitle(halfBufferSize + 2, halfBufferSize);
    nycClock.drawMinsTitle(halfBufferSize, halfBufferSize + 2);
    nycClock.drawMinsTitle(halfBufferSize + 2, halfBufferSize + 2);
    ofSetColor(0, 0, 0, 16);
    ofDrawRectangle(0, 0, bufferSize, bufferSize);
}

void CityClockDrawing::drawNewYorkSeconds(){
    ofClear(0, 0, 0, 0);
    nycClock.drawSecs(halfBufferSize, halfBufferSize);
    nycClock.drawSecs(halfBufferSize + 2, halfBufferSize);
    nycClock.drawSecs(halfBufferSize, halfBufferSize + 2);
    nycClock.drawSecs(halfBufferSize + 2, halfBufferSize + 2);
    ofSetColor(0, 0, 0, 64);
    ofDrawRectangle(0, 0, bufferSize, bufferSize);
}

void CityClockDrawing::drawNewYorkSecondsLabel(){
    ofClear(0, 0, 0, 0);
    nycClock.drawSecsTitle(halfBufferSize, halfBufferSize);
    nycClock.drawSecsTitle(halfBufferSize + 2, halfBufferSize);
    nycClock.drawSecsTitle(halfBufferSize, halfBufferSize + 2);
    nycClock.drawSecsTitle(halfBufferSize + 2, halfBufferSize + 2);
    ofSetColor(0, 0, 0, 16);
    ofDrawRectangle(0, 0, bufferSize, bufferSize);
}

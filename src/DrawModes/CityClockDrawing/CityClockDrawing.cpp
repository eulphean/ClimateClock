#include "CityClockDrawing.h"

void CityClockDrawing::setup(ofxProjectionMask* projectionMask) {
    nycClock.setup("newyork.xml", POSITION_MODE_CENTERED);
    tokyoClock.setup("tokyo.xml", POSITION_MODE_CENTERED);
    parisClock.setup("paris.xml", POSITION_MODE_CENTERED);
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
    parisClock.update();
}

void CityClockDrawing::draw(string city) {
    if(city == "newyork"){
        drawNewYorkBuffers();
    } else if(city == "tokyo") {
        drawTokyoBuffers();
    } else if(city == "paris") {
        drawParisBuffers();
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

void CityClockDrawing::drawTokyoBuffers() {
    clockFace->begin();
    ofClear(0, 0, 0, 0);
    clockFace->end();
    
    clockFace->begin();
    ofClear(0, 0, 0, 0);
    clockFace->end();
    
    clockFaceParts.at(0)->begin();
    drawTokyoYears();
    clockFaceParts.at(0)->end();
    
    clockFaceParts.at(1)->begin();
    drawTokyoYearsLabel();
    clockFaceParts.at(1)->end();
    
    clockFaceParts.at(2)->begin();
    drawTokyoDays();
    clockFaceParts.at(2)->end();
    
    clockFaceParts.at(3)->begin();
    drawTokyoDaysLabel();
    clockFaceParts.at(3)->end();
    
    clockFaceParts.at(4)->begin();
    drawTokyoHours();
    clockFaceParts.at(4)->end();
    
    clockFaceParts.at(5)->begin();
    drawTokyoHoursLabel();
    clockFaceParts.at(5)->end();
    
    clockFaceParts.at(6)->begin();
    drawTokyoMinutes();
    clockFaceParts.at(6)->end();
    
    clockFaceParts.at(7)->begin();
    drawTokyoMinutesLabel();
    clockFaceParts.at(7)->end();
    
    clockFaceParts.at(8)->begin();
    drawTokyoSeconds();
    clockFaceParts.at(8)->end();
    
    clockFaceParts.at(9)->begin();
    drawTokyoSecondsLabel();
    clockFaceParts.at(9)->end();
}

void CityClockDrawing::drawTokyoYears(){
    ofClear(0, 0, 0, 0);
    tokyoClock.drawYears(halfBufferSize, halfBufferSize);
}

void CityClockDrawing::drawTokyoYearsLabel(){
    ofClear(0, 0, 0, 0);
    tokyoClock.drawYearsTitle(halfBufferSize, halfBufferSize);
}

void CityClockDrawing::drawTokyoDays(){
    ofClear(0, 0, 0, 0);
    tokyoClock.drawDays(halfBufferSize, halfBufferSize);
}

void CityClockDrawing::drawTokyoDaysLabel(){
    ofClear(0, 0, 0, 0);
    tokyoClock.drawDaysTitle(halfBufferSize, halfBufferSize);
}

void CityClockDrawing::drawTokyoHours(){
    ofClear(0, 0, 0, 0);
    tokyoClock.drawHrs(halfBufferSize, halfBufferSize);
}

void CityClockDrawing::drawTokyoHoursLabel(){
    ofClear(0, 0, 0, 0);
    tokyoClock.drawHrsTitle(halfBufferSize, halfBufferSize);
}

void CityClockDrawing::drawTokyoMinutes(){
    ofClear(0, 0, 0, 0);
    tokyoClock.drawMins(halfBufferSize, halfBufferSize);
}

void CityClockDrawing::drawTokyoMinutesLabel(){
    ofClear(0, 0, 0, 0);
    tokyoClock.drawMinsTitle(halfBufferSize, halfBufferSize);
}

void CityClockDrawing::drawTokyoSeconds(){
    ofClear(0, 0, 0, 0);
    tokyoClock.drawSecs(halfBufferSize, halfBufferSize);
}

void CityClockDrawing::drawTokyoSecondsLabel(){
    ofClear(0, 0, 0, 0);
    tokyoClock.drawSecsTitle(halfBufferSize, halfBufferSize);
}

void CityClockDrawing::drawParisBuffers() {
    clockFace->begin();
    ofClear(0, 0, 0, 0);
    clockFace->end();
    
    clockFace->begin();
    ofClear(0, 0, 0, 0);
    clockFace->end();
    
    clockFaceParts.at(0)->begin();
    drawParisYears();
    clockFaceParts.at(0)->end();
    
    clockFaceParts.at(1)->begin();
    drawParisYearsLabel();
    clockFaceParts.at(1)->end();
    
    clockFaceParts.at(2)->begin();
    drawParisDays();
    clockFaceParts.at(2)->end();
    
    clockFaceParts.at(3)->begin();
    drawParisDaysLabel();
    clockFaceParts.at(3)->end();
    
    clockFaceParts.at(4)->begin();
    drawParisHours();
    clockFaceParts.at(4)->end();
    
    clockFaceParts.at(5)->begin();
    drawParisHoursLabel();
    clockFaceParts.at(5)->end();
    
    clockFaceParts.at(6)->begin();
    drawParisMinutes();
    clockFaceParts.at(6)->end();
    
    clockFaceParts.at(7)->begin();
    drawParisMinutesLabel();
    clockFaceParts.at(7)->end();
    
    clockFaceParts.at(8)->begin();
    drawParisSeconds();
    clockFaceParts.at(8)->end();
    
    clockFaceParts.at(9)->begin();
    drawParisSecondsLabel();
    clockFaceParts.at(9)->end();
}

void CityClockDrawing::drawParisYears(){
    ofClear(0, 0, 0, 0);
    parisClock.drawYears(halfBufferSize, halfBufferSize);
}

void CityClockDrawing::drawParisYearsLabel(){
    ofClear(0, 0, 0, 0);
    parisClock.drawYearsTitle(halfBufferSize, halfBufferSize);
}

void CityClockDrawing::drawParisDays(){
    ofClear(0, 0, 0, 0);
    parisClock.drawDays(halfBufferSize, halfBufferSize);
}

void CityClockDrawing::drawParisDaysLabel(){
    ofClear(0, 0, 0, 0);
    parisClock.drawDaysTitle(halfBufferSize, halfBufferSize);
}

void CityClockDrawing::drawParisHours(){
    ofClear(0, 0, 0, 0);
    parisClock.drawHrs(halfBufferSize, halfBufferSize);
}

void CityClockDrawing::drawParisHoursLabel(){
    ofClear(0, 0, 0, 0);
    parisClock.drawHrsTitle(halfBufferSize, halfBufferSize);
}

void CityClockDrawing::drawParisMinutes(){
    ofClear(0, 0, 0, 0);
    parisClock.drawMins(halfBufferSize, halfBufferSize);
}

void CityClockDrawing::drawParisMinutesLabel(){
    ofClear(0, 0, 0, 0);
    parisClock.drawMinsTitle(halfBufferSize, halfBufferSize);
}

void CityClockDrawing::drawParisSeconds(){
    ofClear(0, 0, 0, 0);
    parisClock.drawSecs(halfBufferSize, halfBufferSize);
}

void CityClockDrawing::drawParisSecondsLabel(){
    ofClear(0, 0, 0, 0);
    parisClock.drawSecsTitle(halfBufferSize, halfBufferSize);
}


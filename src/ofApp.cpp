#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  // Load various fonts.
  fonts.push_back("betong.ttf");
  fonts.push_back("jmt.otf");
  fonts.push_back("perfect.otf");
  fonts.push_back("chengis.otf");
  fonts.push_back("schaeffer.ttf");
  fonts.push_back("keys.ttf");
  fonts.push_back("giovanni.ttf");
  
  // Load the first font.
  trueYears.load(fonts[1], 25);
  trueDays.load(fonts[1], 25);
  trueHours.load(fonts[1], 25);
  trueMinutes.load(fonts[1], 25);
  trueSeconds.load(fonts[1], 25); // Font, Size
  
  // Record first time.
  lastTimeMillis = ofGetElapsedTimeMillis();
}

//--------------------------------------------------------------
void ofApp::update(){
  // As this time increases, the carbon countdown time
  // decreases.
  if (ofGetElapsedTimeMillis() - lastTimeMillis > 1000) {
    // A second has passed, update carbon countdown clock
    updateCarbonClock();
    
    // Reset time
    lastTimeMillis = ofGetElapsedTimeMillis();
  }
}

void ofApp::updateCarbonClock() {
  // Decrement seconds (60) -> minutes (60) -> hours (24) -> days (365) -> years based on current time. 
  seconds = seconds - 1;
  minutes = (seconds < 0) ? minutes - 1 : minutes;
  seconds = (seconds < 0) ? 59 : seconds;
  hours = (minutes < 0) ? hours - 1: hours;
  minutes = (minutes < 0) ? 59 : minutes;
  days = (hours < 0) ? days - 1: days;
  hours = (hours < 0) ? 23 : hours;
  days = (days < 0) ? 364 : days; // Regular year - 365 days, Leap year - 366 days
  years = (days < 0) ? years - 1: years;
}

//--------------------------------------------------------------
void ofApp::draw(){
  ofPushMatrix();
    ofTranslate(ofGetWidth()/2 - 100, ofGetHeight()/2);
    trueYears.drawString(ofToString(years) + " years, ", 0, 0);
    trueDays.drawString(ofToString(days) + " days, ", 100, 0);
    trueHours.drawString(ofToString(hours) +  " hrs, ", 200, 0);
    trueMinutes.drawString(ofToString(minutes) + " mins, ", 250, 0);
    trueSeconds.drawString(ofToString(seconds) + " secs", 350, 0);
  ofPopMatrix();
}

void ofApp::keyPressed(int key) {}

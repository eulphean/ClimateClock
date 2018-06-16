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
  trueSeconds.load(fonts[1], 25); // Font, Size
  trueMinutes.load(fonts[1], 25);
}

//--------------------------------------------------------------
void ofApp::update(){
  minutes = ofGetMinutes();
  seconds = ofGetSeconds();
  // Get the current time from here in every frame.
  // Draw that time. 
}

//--------------------------------------------------------------
void ofApp::draw(){
  ofPushMatrix();
    ofTranslate(ofGetWidth()/2 - 100, ofGetHeight()/2);
    trueSeconds.drawString(ofToString(seconds), 0, 0);
    trueMinutes.drawString(ofToString(minutes), 30, 0);
  ofPopMatrix();
}

void ofApp::keyPressed(int key) {}

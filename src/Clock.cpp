#include "Clock.h"

void Clock::setup() {
  // Load various fonts.
  fonts.push_back("betong.ttf");
  fonts.push_back("jmt.otf");
  fonts.push_back("perfect.otf");
  fonts.push_back("chengis.otf");
  fonts.push_back("schaeffer.ttf");
  fonts.push_back("keys.ttf");
  fonts.push_back("giovanni.ttf");
  
  // Update clock array with clock characters. 
  for (int i = 0; i < numWords; i++) {
    ofTrueTypeFont word;
    word.load(fonts[0], fontSize);
    clock.push_back(word);
  }
}

void Clock::update() {
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

void Clock::draw() {
  // Draw the clock.
  ofPushMatrix();
    ofTranslate(xPosition, ofGetHeight()/2);
    currentX = 0;
    for (int i = 0; i < numWords; i++) {
      drawWords(i);
    }
  ofPopMatrix();
}

void Clock::drawWords(int idx) {
  switch (idx) {
    case 0: {
      clock[idx].drawString(ofToString(years), currentX, 0);
      currentX = clock[idx].stringWidth(ofToString(years)) + wordSpacing;
      break;
    }
    
    case 1: {
      clock[idx].drawString("years,", currentX, 0);
      currentX += clock[idx].stringWidth("years,") + wordSpacing;
      break;
    }
    
    case 2: {
      clock[idx].drawString(ofToString(days), currentX, 0);
      currentX += clock[idx].stringWidth(ofToString(days)) + wordSpacing;
      break;
    }
    
    case 3: {
      clock[idx].drawString("days,", currentX, 0);
      currentX += clock[idx].stringWidth("days,") + wordSpacing;
      break;
    }
    
    case 4: {
      clock[idx].drawString(ofToString(hours), currentX, 0);
      currentX += clock[idx].stringWidth(ofToString(hours)) + wordSpacing;
      break;
    }
    
    case 5: {
      clock[idx].drawString("hrs,", currentX, 0);
      currentX += clock[idx].stringWidth("hrs,") + wordSpacing;
      break;
    }
    
    case 6: {
      clock[idx].drawString(ofToString(minutes), currentX, 0);
      currentX += clock[idx].stringWidth(ofToString(minutes)) + wordSpacing;
      break;
    }
    
    case 7: {
      clock[idx].drawString("mins,", currentX, 0);
      currentX += clock[idx].stringWidth("mins,") + wordSpacing;
      break;
    }
    
    case 8: {
      clock[idx].drawString(ofToString(seconds), currentX, 0);
      currentX += clock[idx].stringWidth(ofToString(seconds)) + wordSpacing;
      break;
    }
    
    case 9: {
      clock[idx].drawString("secs", currentX, 0);
      break;
    }
    
    default: {
      break;
    }
  }
}

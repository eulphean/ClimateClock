#include "Clock.h"

void Clock::setup() {
  // Load various fonts.
  fonts.push_back("messages.ttf");
  fonts.push_back("philosopher.ttf");
  fonts.push_back("absender.ttf");
  fonts.push_back("monofur.ttf");
  fonts.push_back("instruction.otf");
  fonts.push_back("betong.ttf");
  fonts.push_back("jmt.otf");
  fonts.push_back("perfect.otf");
  fonts.push_back("chengis.otf");
  fonts.push_back("schaeffer.ttf");
  fonts.push_back("keys.ttf");
  fonts.push_back("giovanni.ttf");
  
  // Listeners
  fontSize.addListener(this, &Clock::updateFromGui);
  
  createFutureTime();
  
  createWords();
}

void Clock::update() {
  // FutureTime - CurrentTime
  auto futurePoint = std::chrono::system_clock::from_time_t(mktime(&futureTime));
  auto currentPoint = std::chrono::system_clock::now();
  auto millis = std::chrono::duration_cast<chrono::milliseconds>(futurePoint - currentPoint);
  auto distance = millis.count();
  
  // Formulaes to convert milliseconds to Days, Hours, Minutes, Seconds, and Milliseconds.
  days = floor(distance / (1000 * 60 * 60 * 24));
  hours = floor((distance % (1000 * 60 * 60 * 24)) / (1000 * 60 * 60));
  minutes = floor((distance % (1000 * 60 * 60)) / (1000 * 60));
  seconds = floor(distance % (1000 * 60) / 1000);
  milliseconds = 1000 - distance % 1000;
}

void Clock::draw() {
  // Draw the clock.
  ofPushMatrix();
    ofTranslate(xPosition, yPosition);
    currentX = 0;
    for (int i = 0; i < numWords; i++) {
      ofSetColor(textColor);
      drawWords(i);
    }
  ofPopMatrix();
}

void Clock::createFutureTime() {
  // January 5th, 2037, 12:00AM
  futureTime.tm_year = 2037 - 1900; // Years after year (1900)
  futureTime.tm_mon = 0;
  futureTime.tm_mday = 5; // Day of the month
  futureTime.tm_hour = 0; // Hours after midnight
  futureTime.tm_min = 0; // Minutes after 0
  futureTime.tm_sec = 0; // Seconds after 0
}

void Clock::createWords() {
  clock.clear();
  for (int i = 0; i < numWords; i++) {
    ofTrueTypeFont word;
    word.load(fonts[curFontIdx], fontSize);
    clock.push_back(word);
  }
}

void Clock::cycleFont(bool forward) {
  if (forward) {
    // Wrapp current font idx.
    curFontIdx = (curFontIdx + 1) % fonts.size();
    createWords();
  } else {
    // Wrap current font idx.
    if ((curFontIdx - 1) < 0) {
      curFontIdx = fonts.size() - 1;
    } else {
      curFontIdx--;
    }
    createWords();
  }
}

void Clock::drawWords(int idx) {
  switch (idx) {
    case 0: {
      clock[idx].drawString(ofToString(days), currentX, 0);
      currentX += clock[idx].stringWidth(ofToString(days)) + wordSpacing;
      break;
    }
    
    case 1: {
      clock[idx].drawString("days:", currentX, 0);
      currentX += clock[idx].stringWidth("days:") + wordSpacing;
      break;
    }
    
    case 2: {
      clock[idx].drawString(ofToString(hours), currentX, 0);
      currentX += clock[idx].stringWidth(ofToString(hours)) + wordSpacing;
      break;
    }
    
    case 3: {
      clock[idx].drawString("hrs:", currentX, 0);
      currentX += clock[idx].stringWidth("hrs:") + wordSpacing;
      break;
    }
    
    case 4: {
      clock[idx].drawString(ofToString(minutes), currentX, 0);
      currentX += clock[idx].stringWidth(ofToString(minutes)) + wordSpacing;
      break;
    }
    
    case 5: {
      clock[idx].drawString("mins:", currentX, 0);
      currentX += clock[idx].stringWidth("mins:") + wordSpacing;
      break;
    }
    
    case 6: {
      clock[idx].drawString(ofToString(seconds), currentX, 0);
      currentX += clock[idx].stringWidth(ofToString(seconds)) + wordSpacing;
      break;
    }
    
    case 7: {
      clock[idx].drawString("secs:", currentX, 0);
      currentX += clock[idx].stringWidth("secs:") + wordSpacing;
      break;
    }
    
    case 8: {
      clock[idx].drawString(ofToString(milliseconds), currentX, 0);
      currentX += clock[idx].stringWidth(ofToString(milliseconds)) + wordSpacing;
      break;
    }
    
    case 9: {
      clock[idx].drawString("msecs", currentX, 0);
      break;
    }
    
    default: {
      break;
    }
  }
}

string Clock::currentFont() {
  return fonts[curFontIdx];
}

void Clock::updateFromGui(int & val) {
  createWords();
}

void Clock::setCurrentFont(int idx) {
  curFontIdx = idx; 
 }

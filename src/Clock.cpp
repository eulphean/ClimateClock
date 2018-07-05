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
  
  // Listeners for GUI.
  fontSize.addListener(this, &Clock::updateFromGui);

  createWords();
}

void Clock::update() {
  // Future time in a zone.
  auto future = date::make_zoned(locate_zone("Asia/Calcutta"), date::local_days{2037_y / date::jan / 5}, date::choose::earliest);
  auto futureTime = future.get_sys_time();
  
  // Current time in a zone.
  auto now = date::make_zoned(locate_zone("Asia/Calcutta"), chrono::system_clock::now());
  auto nowTime = now.get_sys_time();

  // Time difference.
  auto diff = chrono::duration_cast<chrono::milliseconds>(futureTime - nowTime);
  auto distance = diff.count();

  // Days
  auto d = date::floor<date::days>(diff); //This might be negative if future is in the past
  days = d.count();
  
  // Hours
  auto hrs = date::floor<std::chrono::hours>(diff %= d);
  hours = hrs.count();
  
  // Minutes
  auto min = (date::floor<std::chrono::minutes>(diff -= hrs));
  minutes = min.count();
  
  // Seconds
  auto secs = (date::floor<std::chrono::seconds>(diff -= min));
  seconds = secs.count();
  
  // Milliseconds
  auto millis = diff - secs;
  milliseconds = millis.count();
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

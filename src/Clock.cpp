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
  fontSizeTime.addListener(this, &Clock::updateTimeFont);
  fontSizeTitle.addListener(this, &Clock::updateTitleFont);

  // Create ofTrueTypeFont time and title words.
  createTimeWords();
  createTitleWords();
}

void Clock::update() {
  updateTime();
}

void Clock::draw() {
  // Draw Time characters (Line 1)
  ofPushMatrix();
    ofTranslate(xPosition, yPositionTime);
    currentTimeX = 0;
    for (int i = 0; i < numWordsTime; i++) {
      ofSetColor(textColor);
      drawTime(i);
    }
  ofPopMatrix();
}

void Clock::createTimeWords() {
  // Create words for Time.
  time.clear();
  for (int i = 0; i < numWordsTime; i++) {
    ofTrueTypeFont word;
    word.load(fonts[curFontIdx], fontSizeTime);
    time.push_back(word);
  }
}

void Clock::createTitleWords() {
  // Create words for Title.
  title.clear();
  for (int i = 0; i < numWordsTitle; i++) {
    ofTrueTypeFont word;
    word.load(fonts[curFontIdx], fontSizeTitle - 10); // Title should be smaller than Time's font size.
    title.push_back(word);
  }
}


void Clock::cycleFont(bool forward) {
  if (forward) {
    // Wrapp current font idx.
    curFontIdx = (curFontIdx + 1) % fonts.size();
    createTimeWords();
    createTitleWords();
  } else {
    // Wrap current font idx.
    if ((curFontIdx - 1) < 0) {
      curFontIdx = fonts.size() - 1;
    } else {
      curFontIdx--;
    }
    createTimeWords();
    createTitleWords();
  }
}

void Clock::drawTime(int idx) {
  switch (idx) {
    case 0: {
      time[idx].drawString(ofToString(days), currentTimeX, 0);
      ofPushMatrix();
        ofTranslate(currentTimeX, yPositionTitle);
        int lengthTime = time[idx].stringWidth(ofToString(days));
        int lengthTitle = title[idx].stringWidth("Days");
        int xPos = abs(lengthTime-lengthTitle)/2;
        title[idx].drawString("Days", xPos, 0);
      ofPopMatrix();
      currentTimeX += time[idx].stringWidth(ofToString(days)) + wordSpacing;
      break;
    }
    
    case 1: {
      time[idx].drawString(ofToString(hours), currentTimeX, 0);
      ofPushMatrix();
        ofTranslate(currentTimeX, yPositionTitle);
        int lengthTime = time[idx].stringWidth(ofToString(hours));
        int lengthTitle = title[idx].stringWidth("Hrs");
        int xPos = abs(lengthTime-lengthTitle)/2;
        title[idx].drawString("Hrs", xPos, 0);
      ofPopMatrix();
      currentTimeX += time[idx].stringWidth(ofToString(hours)) + wordSpacing;
      break;
    }
    
    case 2: {
      time[idx].drawString(ofToString(minutes), currentTimeX, 0);
      ofPushMatrix();
        ofTranslate(currentTimeX, yPositionTitle);
        int lengthTime = time[idx].stringWidth(ofToString(minutes));
        int lengthTitle = title[idx].stringWidth("Mins");
        int xPos = abs(lengthTime-lengthTitle)/2;
        title[idx].drawString("Mins", xPos, 0);
      ofPopMatrix();
      currentTimeX += time[idx].stringWidth(ofToString(minutes)) + wordSpacing;
      break;
    }
    
    case 3: {
      time[idx].drawString(ofToString(seconds), currentTimeX, 0);
      ofPushMatrix();
        ofTranslate(currentTimeX, yPositionTitle);
        int lengthTime = time[idx].stringWidth(ofToString(seconds));
        int lengthTitle = title[idx].stringWidth("Secs");
        int xPos = abs(lengthTime-lengthTitle)/2;
        title[idx].drawString("Secs", xPos, 0);
      ofPopMatrix();
      currentTimeX += time[idx].stringWidth(ofToString(seconds)) + wordSpacing;
      break;
    }
    
    case 4: {
      time[idx].drawString(ofToString(milliseconds), currentTimeX, 0);
      ofPushMatrix();
        ofTranslate(currentTimeX, yPositionTitle);
        int lengthTime = time[idx].stringWidth(ofToString(milliseconds));
        int lengthTitle = title[idx].stringWidth("mSecs");
        int xPos = abs(lengthTime-lengthTitle)/2;
        title[idx].drawString("mSecs", xPos, 0);
      ofPopMatrix();
      currentTimeX += time[idx].stringWidth(ofToString(milliseconds)) + wordSpacing;
      break;
    }
    
    default: {
      break;
    }
  }
}

void Clock::updateTime() {
  // Future time in a zone.
  auto future = date::make_zoned(locate_zone("Asia/Calcutta"), date::local_days{2037_y / date::jan / 5}, date::choose::earliest);
  auto futureTime = floor<chrono::milliseconds>(future.get_sys_time());
  
  // Current time in a zone.
  auto now = date::make_zoned(locate_zone("Asia/Calcutta"), chrono::system_clock::now());
  auto nowTime = floor<chrono::milliseconds>(now.get_sys_time());

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

string Clock::currentFont() {
  return fonts[curFontIdx];
}

void Clock::updateTimeFont(int & val) {
  createTimeWords();
}

void Clock::updateTitleFont(int & val) {
  createTitleWords();
}


void Clock::setCurrentFont(int idx) {
  curFontIdx = idx; 
 }

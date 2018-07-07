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
  
  // Load certain timezones.
  // Pick a random timezone on load.
  // Add a new line on top of the clock for the city.
  // Put an option to not show that line. (Set that true for Andy's clock).
  // Every clock has a collection of all these random timezones.
  
  // Listeners for GUI.
  fontSizeTime.addListener(this, &Clock::updateTimeFont);
  fontSizeTitle.addListener(this, &Clock::updateTitleFont);

  // Create ofTrueTypeFont time and title words.
  createTimeWords();
  createTitleWords();
  
  // Default text color
  textColor = ofColor::black;
}

void Clock::update() {
  updateTime();
}

void Clock::draw() {
  // Draw Time characters (Line 1)
  ofPushMatrix();
    ofTranslate(xPosition, yPositionTime);
    currentX = 0;
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
      string yearsToPrint = placeValueTime(years, PlaceValue::Ten);
      drawTimeTitle(idx, yearsToPrint, "Years");
      currentX += time[idx].stringWidth(yearsToPrint) + wordSpacing;
      break;
    }
    
    case 1: {
      string daysToPrint = placeValueTime(days, PlaceValue::Hundred);
      drawTimeTitle(idx, daysToPrint, "Days");
      currentX += time[idx].stringWidth(daysToPrint) + wordSpacing;
      break;
    }
    
    case 2: {
      string hrsToPrint = placeValueTime(hours, PlaceValue::Ten);
      drawTimeTitle(idx, hrsToPrint, "Hrs");
      currentX += time[idx].stringWidth(hrsToPrint) + wordSpacing;
      break;
    }
    
    case 3: {
      string minsToPrint = placeValueTime(minutes, PlaceValue::Ten); // Minutes should be till 10th place.
      drawTimeTitle(idx, minsToPrint, "Mins");
      currentX += time[idx].stringWidth(minsToPrint) + wordSpacing;
      break;
    }
    
    case 4: {
      // Seconds (10th place precision)
      string secsToPrint = placeValueTime(seconds, PlaceValue::Ten);
      drawTimeTitle(idx, secsToPrint, "Secs");
      currentX += time[idx].stringWidth(secsToPrint) + wordSpacing;
      break;
    }
    
    default: {
      break;
    }
  }
}

void Clock::drawTimeTitle(int idx, string timeToPrint, string timeTitle) {
  time[idx].drawString(timeToPrint, currentX, 0);
  ofPushMatrix();
    ofTranslate(currentX, yPositionTitle);
    int lengthTime = time[idx].stringWidth(timeToPrint);
    int lengthTitle = title[idx].stringWidth(timeTitle);
    int xPos = abs(lengthTime-lengthTitle)/2;
    title[idx].drawString(timeTitle, xPos, 0);
  ofPopMatrix();
}

string Clock::placeValueTime(int time, PlaceValue place) {
  string s;
  switch (place) {
    case Ten: {
      s = ofToString(time);
      float d = time/10;
      if (d < 1.0) {
        s = "0" + ofToString(time);
      }
      break;
    }
    
    case Hundred: {
      s = ofToString(time);
      
      // Check for Hundred.
      float d = time/100;
      if (d < 1.0) {
        s = "0" + ofToString(time);
      }
      
      // Check for Ten.
      d = time/10;
      if (d < 1.0) {
        s = "00" + ofToString(time);
      }
      
      break;
    }
    
    case Thousand: {
      s = ofToString(time);
      
      // Check for Thousand/
      float d = time / 1000;
      if (d < 1.0) {
        s = "0" + ofToString(time);
      }
      
      // Check for Hundred.
      d = time/100;
      if (d < 1.0) {
        s = "00" + ofToString(time);
      }
      
      d = time/10;
      if (d < 1.0) {
        s = "000" + ofToString(time);
      }
      
      break;
    }
    
    default:
      break;
  }
  
  return s;
}

void Clock::updateTime() {
  using namespace date;
  
  // Future time in a zone.
  auto future = make_zoned(locate_zone(timeZone), local_days{2037_y / jan / 5}, choose::earliest);
  auto futureTime = date::floor<chrono::milliseconds>(future.get_sys_time());
  
  // Current time in a zone.
  auto now = make_zoned(date::locate_zone(timeZone), chrono::system_clock::now());
  auto nowTime = floor<chrono::milliseconds>(now.get_sys_time());

  // Time difference.
  auto diff = chrono::duration_cast<chrono::milliseconds>(futureTime - nowTime);
  auto distance = diff.count();

  // Years
  auto y = floor<date::years>(diff);
  years = y.count();
  
  // Days
  auto d = date::floor<date::days>(diff %= y);
  days = d.count();
  
  // Hours
  auto hrs = date::floor<std::chrono::hours>(diff %= d);
  hours = hrs.count();
  
  // Minutes
  auto min = (date::floor<std::chrono::minutes>(diff -= hrs));
  minutes = min.count();
  
  // Seconds (should be maintained till 10s, place value)
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

int Clock::getWidth() {
  return currentX;
}

int Clock::getHeight() {
 return (time[0].getLineHeight() + yPositionTitle + title[0].getLineHeight());
}

void Clock::setTextColor(ofColor c) {
  textColor = c;
}

void Clock::setPosition(float x, float y) {
  xPosition = x; yPositionTime = y;
}

void Clock::setTimeZone(string tz) {
  timeZone = tz;
}

#include "Clock.h"

void Clock::setup(string fileName, PositionMode _positionMode) {
  positionMode = _positionMode;
  if (fileName != " ") {
    // Load XML file.
    settings.loadFile("Clocks/" + fileName);
    fontSizeTime = settings.getValue("settings:fontSizeTime", 10.0);
    fontSizeTitle = settings.getValue("settings:fontSizeTitle", 10.0);
    font = settings.getValue("settings:font", "instruction.otf");
    timeZone = settings.getValue("settings:timeZone", "America/Chicago");
   
    // Construct color from XML.
    string color = settings.getValue("settings:fontColor", "255,255,255,255");
    auto c = ofSplitString(color, ",");
    fontColor = ofColor(ofToInt(c[0]), ofToInt(c[1]), ofToInt(c[2]), ofToInt(c[3]));
  }

  // Create ofTrueTypeFont time and title words.
  createTimeWords();
  createTitleWords();
}

void Clock::update() {
  updateTime();
}

void Clock::drawClock() {
  // Draw Time characters (Line 1)
  ofPushMatrix();
    ofTranslate(xPosition, yPosition);
    currentX = 0;
    for (int i = 0; i < numWordsTime; i++) {
      switch (i) {
        case 0: {
          string yearsToPrint = placeValueTime(years, PlaceValue::Ten);
          drawTimeTitle(i, yearsToPrint, "Years");
          currentX += time[i].stringWidth(yearsToPrint) + wordSpacing;
          break;
        }
        
        case 1: {
          string daysToPrint = placeValueTime(days, PlaceValue::Hundred);
          drawTimeTitle(i, daysToPrint, "Days");
          currentX += time[i].stringWidth(daysToPrint) + wordSpacing;
          break;
        }
        
        case 2: {
          string hrsToPrint = placeValueTime(hours, PlaceValue::Ten);
          drawTimeTitle(i, hrsToPrint, "Hrs");
          currentX += time[i].stringWidth(hrsToPrint) + wordSpacing;
          break;
        }
        
        case 3: {
          string minsToPrint = placeValueTime(minutes, PlaceValue::Ten); // Minutes should be till 10th place.
          drawTimeTitle(i, minsToPrint, "Mins");
          currentX += time[i].stringWidth(minsToPrint) + wordSpacing;
          break;
        }
        
        case 4: {
          string secsToPrint = placeValueTime(seconds, PlaceValue::Ten);
          drawTimeTitle(i, secsToPrint, "Secs");
          currentX += time[i].stringWidth(secsToPrint) + wordSpacing;
          break;
        }
        
        default: {
          break;
        }
      }
    }
  ofPopMatrix();
}

void Clock::drawTimeTitle(int idx, string timeToPrint, string timeTitle) {
  ofPushStyle();
    time[idx].drawString(timeToPrint, currentX, 0);
    ofPushMatrix();
      int lengthTime = time[idx].stringWidth(timeToPrint);
      int lengthTitle = title[idx].stringWidth(timeTitle);
      int xPos = abs(lengthTime-lengthTitle)/2;
      title[idx].drawString(timeTitle, xPos, 0);
    ofPopMatrix();
  ofPopStyle();
}

void Clock::drawYears(int x, int y) {
  string yearsToPrint = placeValueTime(years, PlaceValue::Ten);
  ofPushMatrix();
    translate(x, y, time[0], yearsToPrint);
    ofSetColor(fontColor);
    time[0].drawString(yearsToPrint, 0, 0);
  ofPopMatrix();
}

void Clock::drawYearsTitle(int x, int y) {
  ofPushMatrix();
    translate(x, y, title[0], "Years");
    ofSetColor(fontColor);
    title[0].drawString("Years", 0, 0);
  ofPopMatrix();
}

void Clock::drawDays(int x, int y) {
  string daysToPrint = placeValueTime(days, PlaceValue::Hundred);
  ofPushMatrix();
    translate(x, y, time[1], daysToPrint);
    ofSetColor(fontColor);
    time[1].drawString(daysToPrint, 0, 0);
  ofPopMatrix();
}

void Clock::drawDaysTitle(int x, int y) {
  ofPushMatrix();
    translate(x, y, title[1], "Days");
    ofSetColor(fontColor);
    title[1].drawString("Days", 0, 0);
  ofPopMatrix();
}

void Clock::drawHrs(int x, int y) {
  string hrsToPrint = placeValueTime(hours, PlaceValue::Ten);
  ofPushMatrix();
    translate(x, y, time[2], hrsToPrint);
    ofSetColor(fontColor);
    time[2].drawString(hrsToPrint, 0, 0);
  ofPopMatrix();
}

void Clock::drawHrsTitle(int x, int y) {
  ofPushMatrix();
    translate(x, y, title[2], "Hrs");
    ofSetColor(fontColor);
    title[2].drawString("Hrs", 0, 0);
  ofPopMatrix();
}

void Clock::drawMins(int x, int y) {
  string minsToPrint = placeValueTime(minutes, PlaceValue::Ten);
  ofPushMatrix();
    translate(x, y, time[3], minsToPrint);
    ofSetColor(fontColor);
    time[3].drawString(minsToPrint, 0, 0);
  ofPopMatrix();
}

void Clock::drawMinsTitle(int x, int y) {
  ofPushMatrix();
    translate(x, y, title[3], "Mins");
    ofSetColor(fontColor);
    title[3].drawString("Mins", 0, 0);
  ofPopMatrix();
}

void Clock::drawSecs(int x, int y) {
  string secsToPrint = placeValueTime(seconds, PlaceValue::Ten);
  ofPushMatrix();
    translate(x, y, time[4], secsToPrint);
    ofSetColor(fontColor);
    time[4].drawString(secsToPrint, 0, 0);
  ofPopMatrix();
}

void Clock::drawSecsTitle(int x, int y) {
  ofPushMatrix();
    translate(x, y, title[4], "Secs");
    ofSetColor(fontColor);
    title[4].drawString("Secs", 0, 0);
  ofPopMatrix();
}

void Clock::createTimeWords() {
  // Create words for Time.
  time.clear();
  for (int i = 0; i < numWordsTime; i++) {
    ofTrueTypeFont word;
    word.load("Fonts/" + font, fontSizeTime);
    time.push_back(word);
  }
}

void Clock::createTitleWords() {
  // Create words for Title.
  title.clear();
  for (int i = 0; i < numWordsTitle; i++) {
    ofTrueTypeFont word;
    word.load("Fonts/" + font, fontSizeTitle); // Title should be smaller than Time's font size.
    title.push_back(word);
  }
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

void Clock::setTextColor(ofColor c) {
  fontColor = c;
}

void Clock::setPosition(float x, float y) {
  xPosition = x; yPosition = y;
}

void Clock::setTimeZone(string tz) {
  timeZone = tz;
}

void Clock::translate(int x, int y, ofTrueTypeFont& font, string str){
    if(positionMode == POSITION_MODE_CENTERED){
        ofRectangle boundingBox = font.getStringBoundingBox(str, 0, 0);
        ofTranslate(x - boundingBox.width * 0.5, y + boundingBox.height * 0.5);
    } else {
        ofTranslate(x, y);
    }
}

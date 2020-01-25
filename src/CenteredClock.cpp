#include "CenteredClock.h"

void CenteredClock::setup() {
    // Setup the GUI.
    gui.setup("Centered Clock Params.");
    gui.setPosition(300, 250);
    gui.add(xPosition);
    gui.add(yPosition);
    gui.add(xScale);
    gui.add(yScale);
    gui.loadFromFile("CenterClock.xml");
  
    // populate timezones
    timezones.push_back("America/Chicago");
    timezones.push_back("America/New_York");
    timezones.push_back("Asia/Kolkata");
    timezones.push_back("Europe/Berlin");
    timezones.push_back("Europe/Copenhagen");
    timezones.push_back("America/Costa_Rica");
    timezones.push_back("Asia/Kuwait");
    timezones.push_back("Asia/Manila");
    timezones.push_back("Europe/Moscow");
    timezones.push_back("Africa/Nairobi");
    timezones.push_back("Asia/Shanghai");
    timezones.push_back("Africa/Djibouti");
    timezones.push_back("America/Anchorage");
    timezones.push_back("America/Buenos_Aires");
    timezones.push_back("America/Guatemala");
    timezones.push_back("Asia/Jakarta");
    timezones.push_back("Asia/Jerusalem");
    timezones.push_back("Asia/Macau");
    timezones.push_back("Asia/Saigon");
    timezones.push_back("Asia/Singapore");
    timezones.push_back("Asia/Istanbul");
    timezones.push_back("Atlantic/Bermuda");
    timezones.push_back("Canada/Saskatchewan");
    timezones.push_back("Europe/Paris");
    timezones.push_back("Europe/Sarajevo");
    timezones.push_back("Europe/Stockholm");
    timezones.push_back("Europe/Tallinn");
    timezones.push_back("Europe/Warsaw");
    timezones.push_back("Europe/Zagreb");
    timezones.push_back("Europe/Zurich");
    timezones.push_back("Indian/Maldives");
  
    // Initialize clock.
    timezoneIdx = 0;
    clock.setup(timezones[timezoneIdx], "CenterCoreClock.xml");
    clock.hideRoundedBorder = true;
    clock.guiXOffsetForCity = false;
  
}

void CenteredClock::update() {
    clock.update();
    clock.setPosition(xPosition, yPosition);
}

void CenteredClock::draw(bool hideGui) {
  // Apply scaling to the center clock.
  ofPushMatrix();
    ofScale(xScale, yScale, 0);
    clock.drawClock();
  ofPopMatrix();
  
  if (!hideGui) {
    ofShowCursor();
    clock.drawGui();
    gui.draw();
  } else {
    ofHideCursor();
  }
}

void CenteredClock::exit() {
   gui.saveToFile("CenterClock.xml");
   clock.exit();
}

void CenteredClock::nextTimezone() {
  timezoneIdx = (timezoneIdx + 1) % timezones.size();
  clock.setTimeZone(timezones[timezoneIdx]); 
}

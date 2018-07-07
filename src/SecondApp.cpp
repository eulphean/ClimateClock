#include "SecondApp.h"

//--------------------------------------------------------------
void SecondApp::setup() {
  // Load these timezones in memory.
  loadTimeZones();
  
  // Setup GUI.
  gui.setup();
  gui.setPosition(50, 65);
  gui.add(backgroundColor.setup("Background color", ofColor(255, 0, 0), ofColor(0), ofColor(255)));
  gui.add(clockWidth); gui.add(clockHeight);
  gui.add(xPadding); gui.add(yPadding);
  
  clockWidth.addListener(this, &SecondApp::updateFromGui);
  clockHeight.addListener(this, &SecondApp::updateFromGui);
  xPadding.addListener(this, &SecondApp::updateFromGui);
  yPadding.addListener(this, &SecondApp::updateFromGui);
  
  gui.loadFromFile("Grid.xml");
  
  // Create the grid. 
  createGrid();
}

//--------------------------------------------------------------
void SecondApp::update() {
  ofBackground(backgroundColor);
  
  if (recreateGrid) {
    createGrid();
    recreateGrid = false;
  }
  
  if (clocks.size() > 0) {
    // Update all the clocks.
    for (int i = 0; i < clocks.size(); i++) {
      clocks[i].update();
    }
  }
}

//--------------------------------------------------------------
void SecondApp::draw() {
  for (int i = 0; i < clocks.size(); i++) {
    clocks[i].drawClock();
  }

  if (!hideGui) {
    gui.draw();
  }
}

void SecondApp::createGrid() {
  clocks.clear();
  tzIndices.clear();
  
  // Create grid.
  for (int x = 10; x < ofGetWidth(); x += (clockWidth + xPadding)) {
    for (int y = clockHeight/2; y < ofGetHeight(); y += (clockHeight + yPadding)) {
      Clock clock;
      clock.setup();
      clock.setTimeZone(selectTimeZone());
      clock.setTextColor(ofColor::white);
      clock.setPosition(x, y);
      clocks.push_back(clock);
    }
  }
}

void SecondApp::updateFromGui(int & val) {
  recreateGrid = true;
}

void SecondApp::exit() {
  gui.saveToFile("Grid.xml");
}

void SecondApp::windowResized(int w, int h) {
  createGrid();
}

void SecondApp::keyPressed(int key) {
  if (key == 'h') {
    hideGui = !hideGui;
  }
}

string SecondApp::selectTimeZone() {
  // Maximum entries in the timezone array.
  int maxEntries = timeZones.size();
  
  // Find a unique entry from that vector.
  int randIdx = ofRandom(0, maxEntries - 1);
  while (ofContains(tzIndices, randIdx)) {
    randIdx = ofRandom(0, maxEntries - 1);
  }
  tzIndices.push_back(randIdx);
  
  // Return the timeZone to populate the clock with it.
  return timeZones[randIdx];
}

void SecondApp::loadTimeZones() {
  timeZones.push_back("America/Chicago");
  timeZones.push_back("America/New_York");
  timeZones.push_back("Asia/Kolkata");
  timeZones.push_back("Asia/Singapore");
  timeZones.push_back("Asia/Tokyo");
  timeZones.push_back("Atlantic/Reykjavik");
  timeZones.push_back("Australia/Adelaide");
  timeZones.push_back("Australia/Sydney");
  timeZones.push_back("Africa/Johannesburg");
  timeZones.push_back("Africa/Harare");
  timeZones.push_back("Africa/Djibouti");
  timeZones.push_back("America/Barbados");
  timeZones.push_back("America/Cancun");
  timeZones.push_back("America/Costa_Rica");
  timeZones.push_back("America/El_Salvador");
  timeZones.push_back("Asia/Seoul");
  timeZones.push_back("Asia/Shanghai");
  timeZones.push_back("Europe/Helsinki");
  timeZones.push_back("Europe/Istanbul");
  timeZones.push_back("Europe/Lisbon");
  timeZones.push_back("Europe/Luxembourg");
  timeZones.push_back("Europe/London");
  timeZones.push_back("Europe/Minsk");
  timeZones.push_back("Europe/Moscow");
  timeZones.push_back("Europe/Oslo");
  timeZones.push_back("Europe/Paris");
  timeZones.push_back("Europe/Prague");
  timeZones.push_back("Europe/Rome");
  timeZones.push_back("Europe/Tallinn");
  timeZones.push_back("Europe/Stockholm");
}

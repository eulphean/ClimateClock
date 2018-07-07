#include "SecondApp.h"

//--------------------------------------------------------------
void SecondApp::setup() {
  // Setup GUI.
  gui.setup();
  gui.setPosition(50, 65);
  //gui.add(clock.formatParams);
  //gui.add(clock.textColor.setup("Text color", ofColor(0), ofColor(0), ofColor(255)));
  gui.add(backgroundColor.setup("Background color", ofColor(255, 0, 0), ofColor(0), ofColor(255)));
  gui.loadFromFile("ClimateClockSecond.xml");
  
  createGrid();
}

//--------------------------------------------------------------
void SecondApp::update() {
  ofBackground(backgroundColor);
  
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
    clocks[i].draw();
  }
}

void SecondApp::createGrid() {
  clocks.clear();
  
  int xPadding = 10;
  
  // Create grid.
  for (int x = 10; x < ofGetWidth(); x += (clockWidth + xPadding)) {
    for (int y = clockHeight/2; y < ofGetHeight(); y += clockHeight) {
      Clock clock; clock.setup(); clock.setCurrentFont(4); clock.xPosition = x; clock.yPositionTime = y;
      clocks.push_back(clock);
    }
  }
}

void SecondApp::exit() {
  gui.saveToFile("ClimateClockSecond.xml");
}

void SecondApp::windowResized(int w, int h) {
  createGrid();
}

void SecondApp::keyPressed(int key) {
  if (key == 'h') {
    hideGui = !hideGui;
  }
  
  if (key == OF_KEY_RIGHT) {
    // clock.cycleFont(true);
  }
  
  if (key == OF_KEY_LEFT) {
    // clock.cycleFont(false);
  }
}

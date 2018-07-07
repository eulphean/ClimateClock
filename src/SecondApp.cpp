#include "SecondApp.h"

//--------------------------------------------------------------
void SecondApp::setup() {
  // Setup GUI.
  gui.setup();
  gui.setPosition(50, 65);
  //gui.add(clock.formatParams);
  gui.add(textColor.setup("Clock's text color", ofColor(0), ofColor(0), ofColor(255)));
  gui.add(backgroundColor.setup("Background color", ofColor(255, 0, 0), ofColor(0), ofColor(255)));
  gui.add(clockWidth); gui.add(clockHeight);
  gui.add(xPadding); gui.add(yPadding);
  
  clockWidth.addListener(this, &SecondApp::updateFromGui);
  clockHeight.addListener(this, &SecondApp::updateFromGui);
  xPadding.addListener(this, &SecondApp::updateFromGui);
  yPadding.addListener(this, &SecondApp::updateFromGui);
  
  gui.loadFromFile("ClimateClockSecond.xml");
  
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
    clocks[i].draw();
  }
  
  if (!hideGui) {
    gui.draw();
  }
}

void SecondApp::createGrid() {
  clocks.clear();
  
  // Create grid.
  for (int x = 10; x < ofGetWidth(); x += (clockWidth + xPadding)) {
    for (int y = clockHeight/2; y < ofGetHeight(); y += (clockHeight + yPadding)) {
      Clock clock; // TODO: Cleanup setup.
      clock.setup();
      clock.setTextColor(ofColor::white);
      clock.setCurrentFont(4);
      clock.setPosition(x, y);
      clocks.push_back(clock);
    }
  }
}

void SecondApp::updateFromGui(int & val) {
  recreateGrid = true;
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
}

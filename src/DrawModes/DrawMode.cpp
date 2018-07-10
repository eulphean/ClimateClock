#include "DrawMode.h"

void DrawMode::setup(){
    drawMode = CC_DRAW_VIDEO_OVERLAY;
    ofAddListener(ofEvents().keyPressed, this, &DrawMode::keyPressed);
}

void DrawMode::update(){
    if (isSequencing) {
      unsigned long elapsedTime = ofGetElapsedTimeMillis() - lastTime;
      if (elapsedTime > sequenceTime) { // Done showing current mode.
        next(); // Show next mode.
        lastTime = ofGetElapsedTimeMillis(); // Reset last time.
        sequenceTime = ofRandom(minSequenceTime, maxSequenceTime) * 1000;
      }
    }
}

void DrawMode::next(){
    drawMode = isVideoOverlay() ? CC_DRAW_CLOCK_GRID : CC_DRAW_VIDEO_OVERLAY;
}

bool DrawMode::isClockGrid(){
    return drawMode == CC_DRAW_CLOCK_GRID;
}

bool DrawMode::isVideoOverlay(){
    return drawMode == CC_DRAW_VIDEO_OVERLAY;
}

void DrawMode::keyPressed(ofKeyEventArgs& args) {
    if(args.key == OF_KEY_RETURN) {
        next();
    }
  
    // Sequence scenes.
    if (args.key == 'z') {
      isSequencing = !isSequencing;
      if (isSequencing) {
        lastTime = ofGetElapsedTimeMillis();
        sequenceTime = ofRandom(minSequenceTime, maxSequenceTime) * 1000;
        std::cout << "Start cycling scenes." << endl;
      } else {
        std:: cout << "Stop cycling scenes." << endl;
      }
    }
}

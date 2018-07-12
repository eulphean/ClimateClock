#include "DrawMode.h"

void DrawMode::setup(){
    drawMode = CC_DRAW_CLOCK_GRID;
    ofAddListener(ofEvents().keyPressed, this, &DrawMode::keyPressed);
}

void DrawMode::update(){
    if (isSequencing) {
      unsigned long elapsedTime = ofGetElapsedTimeMillis() - lastTime;
      if (elapsedTime > sequenceTime) { // Done showing current mode.
        next(); // Show next mode.
        lastTime = ofGetElapsedTimeMillis(); // Reset last time.
        if(drawMode == CC_DRAW_CLOCK_GRID){
          sequenceTime = 30 * 1000;
        } else if(drawMode == CC_DRAW_VIDEO_NEWYORK) {
          sequenceTime = 60 * 1000;
        } else if(drawMode == CC_DRAW_VIDEO_TOKYO){
          sequenceTime = 14 * 1000;
        } else if(drawMode == CC_DRAW_VIDEO_PARIS){
          sequenceTime = 14 * 1000;
        }
      }
    }
}

void DrawMode::next(){
    if(drawMode == CC_DRAW_CLOCK_GRID){
        drawMode = CC_DRAW_VIDEO_NEWYORK;
    } else if(drawMode == CC_DRAW_VIDEO_NEWYORK) {
        drawMode = CC_DRAW_VIDEO_TOKYO;
    } else if(drawMode == CC_DRAW_VIDEO_TOKYO){
        drawMode = CC_DRAW_VIDEO_PARIS;
    } else if(drawMode == CC_DRAW_VIDEO_PARIS){
        drawMode = CC_DRAW_CLOCK_GRID;
    }
}

bool DrawMode::isClockGrid(){
    return drawMode == CC_DRAW_CLOCK_GRID;
}

bool DrawMode::isNewYorkOverlay(){
    return drawMode == CC_DRAW_VIDEO_NEWYORK;
}

bool DrawMode::isTokyoOverlay(){
    return drawMode == CC_DRAW_VIDEO_TOKYO;
}

bool DrawMode::isParisOverlay(){
    return drawMode == CC_DRAW_VIDEO_PARIS;
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
        std::cout << "Start cycling scenes." << endl;
      } else {
        std:: cout << "Stop cycling scenes." << endl;
      }
    }
}

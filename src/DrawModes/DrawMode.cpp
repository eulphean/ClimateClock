#include "DrawMode.h"

void DrawMode::setup(){
    drawMode = CC_DRAW_VIDEO_OVERLAY;
    ofAddListener(ofEvents().keyPressed, this, &DrawMode::keyPressed);
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
}

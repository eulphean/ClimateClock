#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "Clock.h"
#include "ofxProjectionMask.h"
#include "ofxLayerMask.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();
    void exit();
    void keyPressed(int key);
  
private:
    bool hideGui = false;
    Clock clock;

    ofxPanel gui;
    ofxColorSlider backgroundColor;

    ofxProjectionMask projectionMask;
    ofxLayerMask *clockFace, *background;
    ofImage backgroundImage;
};

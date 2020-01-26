#pragma once

#include "ofMain.h"
#include "CenteredClock.h"

class Dip {
  public:
    Dip(glm::vec2 pos, ofColor col, int rad) {
      position = pos;
      color = col;
      radius = rad;
    }
  
    void draw() {
      ofPushStyle();
        ofPushMatrix();
          ofSetColor(color);
          ofTranslate(position);
          ofDrawCircle(0, 0, radius);
        ofPopMatrix();
      ofPopStyle();
    }
  
    glm::vec2 position;
    ofColor color;
    int radius;
};

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();
    void exit();
  
    void keyPressed(int key);
    void mousePressed(int x, int y, int button);
  
private:
    CenteredClock centeredClock;
    bool hideGui;
    ofImage bg;
    std::vector<Dip> dips; 
};

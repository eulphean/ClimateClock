#pragma once

#include "ofMain.h"
#include "Clock.h"

class CenteredClock {
    
public:
    void setup();
    void update();
    void drawThirdWindow();
protected:
    Clock clock;
};

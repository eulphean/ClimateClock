#pragma once

#include "ofMain.h"
#include "Clock.h"

class CenteredClock {
    
public:
    void setup(bool _isProductionMode);
    void update();
    void drawThirdWindow();
protected:
    void setupThirdWindow();
    Clock clock;
    bool isThirdWindowSetup, isProductionMode;
};

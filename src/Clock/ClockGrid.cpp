#include "ClockGrid.h"

void ClockGrid::setup() {
    loadTimeZones();

    gui.setup();
    gui.setPosition(50, 65);
    gui.add(backgroundColor.setup("Background color", ofColor(255, 0, 0), ofColor(0), ofColor(255)));
    gui.add(clockWidth); gui.add(clockHeight);
    gui.add(xPadding); gui.add(yPadding);
    
    clockWidth.addListener(this, &ClockGrid::updateFromGui);
    clockHeight.addListener(this, &ClockGrid::updateFromGui);
    xPadding.addListener(this, &ClockGrid::updateFromGui);
    yPadding.addListener(this, &ClockGrid::updateFromGui);
    
    gui.loadFromFile("Grid.xml");

    createGrid();
}

void ClockGrid::update() {
    if (recreateGrid) {
        createGrid();
        recreateGrid = false;
    }
    
    if (clocks.size() > 0) {
        for (int i = 0; i < clocks.size(); i++) {
            clocks[i].update();
        }
    }
}

void ClockGrid::draw() {
    ofBackground(backgroundColor);

    for (int i = 0; i < clocks.size(); i++) {
        clocks[i].drawClock();
    }

    if (!hideGui) {
        gui.draw();
    }
}

void ClockGrid::createGrid() {
    clocks.clear();
    tzIndices.clear();

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

void ClockGrid::updateFromGui(int &val) {
    recreateGrid = true;
}

void ClockGrid::exit() {
    gui.saveToFile("Grid.xml");
}

void ClockGrid::windowResized(int w, int h) {
    createGrid();
}

void ClockGrid::keyPressed(int key) {
    if (key == 'h') {
        hideGui = !hideGui;
    }
}

string ClockGrid::selectTimeZone() {
    /*int maxEntries = timeZones.size();

    int randIdx = ofRandom(0, maxEntries - 1);
    while (ofContains(tzIndices, randIdx)) {
        randIdx = ofRandom(0, maxEntries - 1);
    }
    tzIndices.push_back(randIdx);

    return timeZones[randIdx];*/
    return timeZones[ofRandom(0, timeZones.size() - 1)];
}

void ClockGrid::loadTimeZones() {
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

#include "ofMain.h"
#include "ofApp.h"
#include "ofAppGLFWWindow.h"

int main(){
  ofSetupOpenGL(800,480, OF_FULLSCREEN);      // <-------- setup the GL context
  ofRunApp(new ofApp());
}

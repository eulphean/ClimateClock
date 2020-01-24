#include "ofMain.h"
#include "ofApp.h"
#include "ofAppGLFWWindow.h"

int main(){
  ofSetupOpenGL(1600,900, OF_FULLSCREEN);      // <-------- setup the GL context
  ofRunApp(new ofApp());
}

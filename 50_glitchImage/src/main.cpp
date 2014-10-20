#include "ofApp.h"
#include "ofAppGlutWindow.h"

int main() {
	ofAppGlutWindow window;
	ofSetupOpenGL(&window, 400, 400, OF_WINDOW);
	ofRunApp(new ofApp());
}

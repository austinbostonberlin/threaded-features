#include "ofApp.h"
#include "ofAppRunner.h"
#include "ofMain.h"

//========================================================================
int main()
{
    ofGLFWWindowSettings settings;
    settings.setGLVersion(4, 6);
    settings.setSize(1920, 1080);
    ofCreateWindow(settings);

    ofRunApp(new ofApp());
}

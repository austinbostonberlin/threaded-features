#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "ofxOpenCv.h"
#include "threadedContourFinder.hpp"

class ofApp : public ofBaseApp {

public:
    void setup();
    void update();
    void draw();
    void audioOut(ofSoundBuffer& buffer);
    void exit();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    ofSoundStream soundStream;
    int sampleRate;
    int bufferSize;

    cv::Mat img, imgGray, imgBlur, imgblur, imgCanny, imgDilate, imgErode, kernel;
    ofImage image;

    ofVideoGrabber camera;

    threadedContourFinder find;
};

#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "ofxOpenCv.h"
#include "threadedContourFinder.hpp"
#include <vector>

//! A simple reference implementation of countour finder and corner detectors
//! It has a small extra feature to draw a rectangle to record the computer vision data from and interact with it.
//! This is useful to store the countours and reannimate them, or any prcedures that require the objects inside an image to be detected.
class ofApp : public ofBaseApp {

public:
    void setup();
    void update();
    void draw();
    void audioOut(ofSoundBuffer& buffer);
    void exit();

    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);

    // ofSoundStream soundStream;
    int sampleRate;
    int bufferSize;

    cv::Mat img;
    cv::UMat Uimg;
    ofImage image;

    //! An abstraction layer to interface with `GStreamer` API
    //! This is the method to get data from hardware camera.
    ofVideoGrabber camera;

    threadedContourFinder find;
    std::vector<glm::vec2> centroid, features;
    int x1, y1, x2, y2;
    bool rectDone;
    //! Dynamic interactable rectangle
    ofRectangle mouseRect;
};

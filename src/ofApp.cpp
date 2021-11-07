#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    sampleRate = 48000;
    bufferSize = 1024;

    ofSoundStreamSettings settings;
    settings.setOutListener(ofGetAppPtr());
    settings.sampleRate = sampleRate;
    settings.bufferSize = bufferSize;
    settings.numOutputChannels = 2;
    settings.numBuffers = 2;
    // soundStream.setup(settings);

    camera.initGrabber(640, 480);
    kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(5, 5));
}

//--------------------------------------------------------------
void ofApp::update()
{
    camera.update();

    float newX = ofMap(mouseX, 0, ofGetWidth(), 20, 240);
    float newY = ofMap(mouseY, 0, ofGetHeight(), 20, 240);

    find.hysterisisThresholds(newX, newY);

    if (camera.isFrameNew()) {
        img = ofxCv::toCv(camera.getPixels());
        find.createContours(img, img);
    }
}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofxCv::drawMat(img, 0, 0);
}

// void ofApp::getContours(cv::Mat imgErode, cv::Mat imgDraw)
// {
// std::vector<std::vector<cv::Point>> contours;
// std::vector<cv::Vec4i> hierarchy;

// cv::findContours(imgErode, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
// cv::drawContours(img, contours, -1, cv::Scalar(255, 0, 0), 2);

// std::vector<std::vector<cv::Point>> contPoly(contours.size());
// std::vector<cv::Rect> boundRect(contours.size());
// std::string objectType;

// for (int i = 0; i < contours.size(); i++) {
//     int area = cv::contourArea(contours[i]);
//     if (area > 10000) {
//         float peri = cv::arcLength(contours[i], true);
//         cv::approxPolyDP(contours[i], contPoly[i], 0.02 * peri, true);
//         cv::drawContours(imgDraw, contPoly, i, cv::Scalar(255, 0, 255), 2);
//         boundRect[i] = cv::boundingRect(contPoly[i]);
//         cv::rectangle(imgDraw, boundRect[i].tl(), boundRect[i].br(), cv::Scalar(0, 255, 0), 5);
//         int objectCorner = contPoly[i].size();
//         switch (objectCorner) {
//         case 3:
//             objectType = "Triangle";
//             break;
//         case 4:
//             float aspRatio = (float)boundRect[i].width / (float)boundRect[i].height;
//             if (aspRatio > 0.9 && aspRatio < 1.1) {
//                 objectType = "Square";
//             } else {
//                 objectType = "Rectanle";
//             }
//             break;
//         }
//         if (objectCorner > 5) {
//             objectType = "Circle";
//         }
//         cv::putText(imgDraw, objectType, { boundRect[i].x, boundRect[i].y - 5 }, cv::FONT_HERSHEY_COMPLEX, 0.75, cv::Scalar(0, 0, 0), 1);
//     }
// }
// }

//--------------------------------------------------------------
void ofApp::audioOut(ofSoundBuffer& buffer)
{
    float currentSample = 0;
    for (size_t i = 0; i < buffer.getNumFrames(); i++) {
        buffer[i * buffer.getNumChannels()] = currentSample;
        buffer[i * buffer.getNumChannels() + 1] = currentSample;
    }
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key) { }

//--------------------------------------------------------------
void ofApp::keyReleased(int key) { }

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) { }

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) { }

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) { }

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) { }

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) { }

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) { }

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) { }

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) { }

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) { }

//--------------------------------------------------------------
void ofApp::exit()
{
    // soundStream.close();
}

#include "ofApp.h"
#include "ofGraphics.h"
#include "ofxCv/Utilities.h"

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
    find.setThreadName("openCV");
    find.setNumCorners(200);
    find.setMinDistance(20);
}

//--------------------------------------------------------------
void ofApp::update()
{
    camera.update();

    float newX = ofMap(mouseX, 0, ofGetWidth(), 20, 240);
    float newY = ofMap(mouseY, 0, ofGetHeight(), 20, 240);

    // find.hysterisisThresholds(newX, newY);

    if (camera.isFrameNew()) {
        img = ofxCv::toCv(camera.getPixels());
        // find.createContours(img, img);
        find.createContours(img);
        centroid = find.getCentroids();
        features = find.getFeatures();
    }
}

//--------------------------------------------------------------
void ofApp::draw()
{
    find.drawContours(img);
    // find.drawBoundingRect(img);
    // find.drawContourPolygon(img);
    ofxCv::drawMat(img, 0, 0);
    // for (int i = 0; i < centroid.size(); i++) {
    //     ofDrawCircle(centroid[i], 5);
    // }
    for (int i = 0; i < features.size(); i++) {
        ofDrawCircle(features[i], 5);
    }

    std::vector<ofPolyline> lines = find.getContourShape();
    ofPushMatrix();
    ofTranslate(mouseX, mouseY);
    for (auto line : lines) {
        line.draw();
    }
    ofPopMatrix();
}

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
void ofApp::keyPressed(int key)
{
}

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

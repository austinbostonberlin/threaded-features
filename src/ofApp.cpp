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
    x1 = 0;
    x2 = 0;
    y1 = 0;
    y2 = 0;
    rectDone = false;
}

//--------------------------------------------------------------
void ofApp::update()
{
    camera.update();

    if (camera.isFrameNew()) {
        Uimg = ofxCv::toCv(camera.getPixels()).getUMat(cv::ACCESS_READ);
        // find.createContours(img, img);
        find.createContours(Uimg);
        centroid = find.getCentroids();
        features = find.tFeatures();
    }
}

//--------------------------------------------------------------
void ofApp::draw()
{
    find.drawContours(Uimg);
    // find.drawBoundingRect(img);
    // find.drawContourPolygon(img);
    ofxCv::drawMat(Uimg.getMat(cv::ACCESS_READ), 0, 0);
    // for (int i = 0; i < centroid.size(); i++) {
    //     ofDrawCircle(centroid[i], 5);
    // }
    for (int i = 0; i < features.size(); i++) {
        ofDrawCircle(features[i], 5);
    }

    std::vector<ofPolyline> lines = find.getContourShape();
    ofPolyline drawLines;
    if (rectDone) {
        ofDrawRectangle(mouseRect);
        ofPushMatrix();
        ofTranslate(mouseX, mouseY);
        for (auto line : lines) {
            for (size_t i = 0; i < line.size(); i++) {
                if (mouseRect.inside(line[i])) {
                    drawLines.addVertex(line[i]);
                }
            }
        }
        drawLines.draw();
        ofPopMatrix();
    }
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
void ofApp::mousePressed(int x, int y, int button)
{
    rectDone = false;
    x1 = x;
    y1 = y;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
    x2 = x;
    y2 = y;

    glm::vec2 l1(x1, y1), l2(x2, y1);
    glm::vec2 h1(x2, y1), h2(x2, y2);
    float len = glm::distance(l1, l2);
    float heigh = glm::distance(h1, h2);
    ofNoFill();
    mouseRect.set(x1, y1, len, heigh);
    rectDone = true;
}

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

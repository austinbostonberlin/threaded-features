#include "threadedContourFinder.hpp"
#include "ofxCv/Utilities.h"
#include "opencv2/imgproc.hpp"

void threadedContourFinder::createContours(cv::UMat img, cv::UMat imgDraw)
{
    this->m_img = img;
    this->m_Output = imgDraw;
    this->m_threadDone = false;
    startThread();
}

void threadedContourFinder::createContours(cv::UMat img)
{
    this->m_img = img;
    this->m_threadDone = false;
    startThread();
}

void threadedContourFinder::m_createContours()
{
    cv::cvtColor(m_img, m_greyScale, cv::COLOR_BGR2GRAY);
    cv::goodFeaturesToTrack(m_greyScale, m_Features, m_MaxCorners, m_Qualitylevel, m_MinDistance);
    cv::GaussianBlur(m_greyScale, m_Blur, cv::Size(m_KernelSize, m_KernelSize), m_SigmaX, m_SigmaY);
    cv::Canny(m_Blur, m_Canny, m_LowerBound, m_UpperBound);
    cv::dilate(m_Canny, m_Dilate, m_Kernel);
    cv::erode(m_Dilate, m_Erode, m_Kernel);

    cv::findContours(m_Erode, m_Contours, m_Hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    m_ContourPolygon.resize(m_Contours.size());
    m_BoundingRect.resize(m_Contours.size());
    m_Moments.resize(m_Contours.size());
    m_Centroid.resize(m_Contours.size());
}

void threadedContourFinder::m_createExtensions()
{
    for (int i = 0; i < m_Contours.size(); i++) {
        int area = cv::contourArea(m_Contours[i]);
        if (area > 1000) {
            float peri = cv::arcLength(m_Contours[i], true);
            m_Moments[i] = cv::moments(m_Contours[i]);
            m_Centroid[i] = cv::Point(m_Moments[i].m10 / m_Moments[i].m00, m_Moments[i].m01 / m_Moments[i].m00);
            cv::approxPolyDP(m_Contours[i], m_ContourPolygon[i], 0.02 * peri, true);
            m_BoundingRect[i] = cv::boundingRect(m_ContourPolygon[i]);
        }
    }
}

void threadedContourFinder::threadedFunction()
{
    this->m_threadRunning = true;
    this->m_createContours();
    this->m_createExtensions();
    this->m_threadDone = true;
    this->m_threadRunning = false;
}

void threadedContourFinder::drawContours(cv::UMat& img)
{
    if (!m_threadDone) {
        createContours(img);
    }
    cv::drawContours(img, m_Contours, -1, cv::Scalar(255, 0, 0), 2);
}

void threadedContourFinder::drawBoundingRect(cv::UMat& img)
{
    for (int i = 0; i < m_BoundingRect.size(); i++) {
        cv::rectangle(img, m_BoundingRect[i].tl(), m_BoundingRect[i].br(), cv::Scalar(0, 255, 0), 5);
    }
}

void threadedContourFinder::drawContourPolygon(cv::UMat& img)
{
    if (!m_threadDone) {
        createContours(img);
    }
    for (int i = 0; i < m_Contours.size(); i++) {
        cv::drawContours(img, m_ContourPolygon, i, cv::Scalar(255, 0, 255), 2);
    }
}

std::vector<glm::vec2> threadedContourFinder::getFeatures()
{
    vector<glm::vec2> temp;

    for (auto feature : m_Features) {
        temp.push_back(ofxCv::toOf(feature));
    }
    return temp;
}

std::vector<glm::vec2> threadedContourFinder::getContours()
{
    std::vector<glm::vec2> temp;
    for (std::vector<cv::Point> contour : m_Contours) {
        for (cv::Point point : contour) {
            temp.push_back(ofxCv::toOf(point));
        }
    }
    return temp;
}

std::vector<ofPolyline> threadedContourFinder::getContourShape()
{
    std::vector<ofPolyline> temp;
    for (std::vector<cv::Point> contour : m_Contours) {
        ofPolyline line;
        for (cv::Point shape : contour) {
            line.addVertex(glm::vec3 { ofxCv::toOf(shape), 0.f });
        }
        temp.push_back(line);
    }
    return temp;
}

std::vector<glm::vec2> threadedContourFinder::getCentroids()
{
    vector<glm::vec2> temp;

    for (auto centroid : m_Centroid) {
        temp.push_back(ofxCv::toOf(centroid));
    }
    return temp;
}

std::vector<glm::vec2> threadedContourFinder::tFeatures()
{
    std::future<std::vector<glm::vec2>> fu = std::async(
        std::launch::async, [this]() {
            vector<glm::vec2> temp;
            for (auto feature : m_Features) {
                temp.push_back(ofxCv::toOf(feature));
            }
            return temp;
        });
    return fu.get();
}

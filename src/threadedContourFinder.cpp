#include "threadedContourFinder.hpp"
#include "ofxCv/Utilities.h"
#include "opencv2/imgproc.hpp"

void threadedContourFinder::createContours(cv::Mat img, cv::Mat imgDraw)
{
    this->m_img = img;
    this->m_Output = imgDraw;
    startThread();
}

void threadedContourFinder::threadedFunction()
{
    // while (isThreadRunning()) {
    cv::cvtColor(m_img, m_greyScale, cv::COLOR_BGR2GRAY);
    cv::goodFeaturesToTrack(m_greyScale, m_Features, m_MaxCorners, m_Qualitylevel, m_MinDistance);
    cv::GaussianBlur(m_greyScale, m_Blur, cv::Size(m_KernelSize, m_KernelSize), m_SigmaX, m_SigmaY);
    cv::Canny(m_Blur, m_Canny, m_LowerBound, m_UpperBound);
    cv::dilate(m_Canny, m_Dilate, m_Kernel);
    cv::erode(m_Dilate, m_Erode, m_Kernel);

    cv::findContours(m_Erode, m_Contours, m_Hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
    // cv::drawContours(m_Output, m_Contours, -1, cv::Scalar(255, 0, 0), 2);

    m_ContourPolygon.resize(m_Contours.size());
    m_BoundingRect.resize(m_Contours.size());
    m_Moments.resize(m_Contours.size());
    m_Centroid.resize(m_Contours.size());

    for (int i = 0; i < m_Contours.size(); i++) {
        int area = cv::contourArea(m_Contours[i]);
        if (area > 1000) {
            float peri = cv::arcLength(m_Contours[i], true);
            m_Moments[i] = cv::moments(m_Contours[i]);
            m_Centroid[i] = cv::Point(m_Moments[i].m10 / m_Moments[i].m00, m_Moments[i].m01 / m_Moments[i].m00);
            cv::approxPolyDP(m_Contours[i], m_ContourPolygon[i], 0.02 * peri, true);
            cv::drawContours(m_Output, m_ContourPolygon, i, cv::Scalar(255, 0, 255), 2);
            // boundRect[i] = cv::boundingRect(contPoly[i]);
            // cv::rectangle(m_Output, boundRect[i].tl(), boundRect[i].br(), cv::Scalar(0, 255, 0), 5);
        }
    }
    // }
}

std::vector<std::vector<cv::Point>> threadedContourFinder::getContours()
{
    return m_Contours;
}

std::vector<glm::vec2> threadedContourFinder::getCentroids()
{
    vector<glm::vec2> temp;

    for (auto centroid : m_Centroid) {
        temp.push_back(ofxCv::toOf(centroid));
    }
    return temp;
}

void threadedContourFinder::setGaussian(int kernelSize, float sigmaX, float sigmaY)
{
    m_KernelSize = kernelSize;
    m_SigmaX = sigmaX;
    m_SigmaY = sigmaY;
}

void threadedContourFinder::hysterisisThresholds(int lower, int upper)
{
    m_LowerBound = lower;
    m_UpperBound = upper;
}

void threadedContourFinder::setkernel(cv::Mat newKernel)
{
    m_Kernel = newKernel;
}

std::vector<glm::vec2> threadedContourFinder::getFeatures()
{
    vector<glm::vec2> temp;

    for (auto feature : m_Features) {
        temp.push_back(ofxCv::toOf(feature));
    }
    return temp;
}

// void threadedContourFinder::createContours(cv::Mat img)
// {
//     this->m_img = img;
//     startThread();
// }

// void threadedContourFinder::drawOnImage(cv::Mat img)
// {
//     img = m_Output;
// }

// cv::Mat threadedContourFinder::drawOnImage()
// {
//     return m_Output;
// }

// bool threadedContourFinder::isThreadDone()
// {
//     return m_threadDone;
// }

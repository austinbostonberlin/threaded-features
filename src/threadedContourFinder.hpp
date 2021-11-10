#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "opencv2/opencv.hpp"
#include <vector>

class threadedContourFinder : public ofThread {
public:
    void createContours(cv::Mat img, cv::Mat imgDraw);

    // void createContours(cv::Mat img);

    void threadedFunction();

    std::vector<std::vector<cv::Point>> getContours();

    void setGaussian(int kernelSize, float sigmaX, float sigmaY);

    void hysterisisThresholds(int lower, int upper);

    void setkernel(cv::Mat newKernel);

    std::vector<glm::vec2> getCentroids();

    std::vector<glm::vec2> getFeatures();

    inline void setMinDistance(double distance)
    {
        m_MinDistance = distance;
    }

    inline void setQualityLevel(double quality)
    {
        m_Qualitylevel = quality;
    }

    inline void setNumCorners(int corners)
    {
        m_MaxCorners = corners;
    }

    // void drawOnImage(cv::Mat img);

    // cv::Mat drawOnImage();

    // bool isThreadDone();

private:
    cv::Mat m_img, m_greyScale, m_Blur, m_Canny, m_Dilate, m_Erode;
    cv::Mat m_Output;
    cv::Mat m_Kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(5, 5));

    int m_LowerBound = 50, m_UpperBound = 150;
    int m_MaxCorners = 150;
    double m_Qualitylevel = 0.4, m_MinDistance = 7, m_Coeffecient = 0.05;

    int m_KernelSize = 5;
    float m_SigmaX = 5, m_SigmaY = 2.5;

    bool m_threadDone;

    std::vector<std::vector<cv::Point>> m_Contours;
    std::vector<cv::Vec4i> m_Hierarchy;
    std::vector<std::vector<cv::Point>> m_ContourPolygon;
    std::vector<cv::Rect> m_BoundingRect;
    std::vector<cv::Moments> m_Moments;
    std::vector<cv::Point> m_Centroid;
    std::vector<cv::Point2f> m_Features;
};

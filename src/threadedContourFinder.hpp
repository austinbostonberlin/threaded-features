#pragma once

#include "ofMain.h"
#include "opencv2/opencv.hpp"
#include <vector>

class threadedContourFinder : public ofThread {
public:
    void createContours(cv::Mat img, cv::Mat imgDraw);

    void threadedFunction();

    std::vector<std::vector<cv::Point>> getContours();

    void setGaussian(int kernelSize, float sigmaX, float sigmaY);

    void hysterisisThresholds(int lower, int upper);

    void setkernel(cv::Mat newKernel);

private:
    cv::Mat m_img, m_greyScale, m_Blur, m_Canny, m_Dilate, m_Erode;
    cv::Mat m_Output;
    cv::Mat m_Kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(5, 5));

    int m_LowerBound = 50, m_UpperBound = 150;

    int m_KernelSize = 5;
    float m_SigmaX = 5, m_SigmaY = 2.5;

    std::vector<std::vector<cv::Point>> m_Contours;
    std::vector<cv::Vec4i> m_Hierarchy;
};

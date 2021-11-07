#include "threadedContourFinder.hpp"

void threadedContourFinder::createContours(cv::Mat img, cv::Mat imgDraw)
{
    this->m_img = img;
    this->m_Output = imgDraw;
    startThread();
}

void threadedContourFinder::threadedFunction()
{
    cv::cvtColor(m_img, m_greyScale, cv::COLOR_BGR2GRAY);
    cv::GaussianBlur(m_greyScale, m_Blur, cv::Size(m_KernelSize, m_KernelSize), m_SigmaX, m_SigmaY);
    cv::Canny(m_Blur, m_Canny, m_LowerBound, m_UpperBound);

    cv::dilate(m_Canny, m_Dilate, m_Kernel);
    cv::erode(m_Dilate, m_Erode, m_Kernel);

    cv::findContours(m_Erode, m_Contours, m_Hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
    cv::drawContours(m_Output, m_Contours, -1, cv::Scalar(255, 0, 0), 2);
}

std::vector<std::vector<cv::Point>> threadedContourFinder::getContours()
{
    return m_Contours;
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

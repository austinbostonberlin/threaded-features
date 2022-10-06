#pragma once

#include "future"
#include "ofMain.h"
#include "ofxCv.h"
#include "opencv2/opencv.hpp"
#include <vector>

//! A collection of extentions to `openCV` API with multithreading where relevant
class threadedContourFinder : public ofThread {
public:
    //! Create contours for the given image. Return it to a different image
    //! This call starts the thread specified by `threadedContourFinder::threadedFunction`.
    //! Both image matrix are parallelized by `OpenCL`
    //! @param img Input image in `cv` format.
    //! @param imgDraw Empty image to output contours in `cv` format.
    void createContours(cv::UMat img, cv::UMat imgDraw);

    //! Same as `threadedContourFinder::createContours(cv::UMat img, cv::UMat imgDraw)` but this function overrites the input image.
    //! @param img The image matrix containing the pixels. **WARNING**: The image will be overwritten
    void createContours(cv::UMat img);

    //! The threaded call to `cv::createContours`
    //! It uses the following steps:
    //! Gaussian blur, canny edge detection, dilation and erosion
    //! It additionally creates extensions such as calculating bounding rectangle for the contour, the center of mass for the contour and the approximate polygon to contain the contour.
    void threadedFunction();

    //! Convert and return `std::vector<cv::Point>` to `std::vector<glm::vec2>`
    std::vector<glm::vec2> getContours();

    //! Convert `std::vector<cv::point>` to `ofPolyline`.
    //! `ofPolyline` can be used to directly supply vertices ot `openGL`
    std::vector<ofPolyline> getContourShape();

    //! Return the center of mass for each blob as `glm::vec2` coordinates
    std::vector<glm::vec2> getCentroids();

    //! Returns the corner vertices calculated by *She & Thomasi* corner detectiona algorithm
    std::vector<glm::vec2> getFeatures();

    //! Async call to `threadedContourFinder::getFeatures` in a separate thread
    std::vector<glm::vec2> tFeatures();

    //! Set the kernel matrix to be used for convolution processes
    //! @param newKernel a `cv::Mat` matrix
    inline void setkernel(cv::Mat newKernel)
    {
        m_Kernel = newKernel;
    }

    //! Set the kernel size and standard deviation
    //! @param kernelSize length of rows and column for matrix
    //! @param sigmaX Standar deviation in X direction
    //! @param sigmaY Standar deviation in Y direction
    inline void setGaussian(int kernelSize, float sigmaX, float sigmaY)
    {
        m_KernelSize = kernelSize;
        m_SigmaX = sigmaX;
        m_SigmaY = sigmaY;
    }

    //! Set bounds for hysterisis thresholding
    //! @param lower 1st or lower threshold
    //! @param upper 2nd or upper threshold
    inline void hysterisisThresholds(int lower, int upper)
    {
        m_LowerBound = lower;
        m_UpperBound = upper;
    }

    //! Minimum possible euclidean distance between returned corners for the corner detection algorithm
    //! @param distance Minimum distance
    inline void setMinDistance(double distance)
    {
        m_MinDistance = distance;
    }

    //! Set the minimum quality level for determinant and trace operations for *Shi Tomasi* Corner detection algorithm
    //! @param quality The minimum eigen value
    inline void setQualityLevel(double quality)
    {
        m_Qualitylevel = quality;
    }

    //! Set maximum number of corners to return after successful corner detection
    inline void setNumCorners(int corners)
    {
        m_MaxCorners = corners;
    }

    //! Pipe the co-ordinates of the detected contours to `stdout`
    inline void printContours()
    {
        for (size_t i = 0; i < m_Contours.size(); i++) {
            std::cout << m_Contours[i] << std::endl;
        }
    }

    //! Draw contours over the supplied image.
    //! @param img An image to write or overwrite with contours
    void drawContours(cv::UMat& img);

    //! Draw bounding rectangle around the contours over the supplied image.
    //! @param img An image to write or overwrite with the bounding rectangle
    void drawBoundingRect(cv::UMat& img);

    //! Draw an approximate polygon around the contours over the supplied image.
    //! @param img An image to write or overwrite with the approximate polygon
    void drawContourPolygon(cv::UMat& img);

private:
    cv::UMat m_img, m_greyScale, m_Blur, m_Canny, m_Dilate, m_Erode;
    cv::UMat m_Output;
    cv::Mat m_Kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(5, 5));

    int m_LowerBound = 50, m_UpperBound = 150;
    int m_MaxCorners = 150;
    double m_Qualitylevel = 0.4, m_MinDistance = 7, m_Coeffecient = 0.05;

    int m_KernelSize = 5;
    float m_SigmaX = 5, m_SigmaY = 2.5;

    bool m_threadDone, m_threadRunning = false;

    std::vector<std::vector<cv::Point>> m_Contours;
    std::vector<cv::Vec4i> m_Hierarchy;
    std::vector<std::vector<cv::Point>> m_ContourPolygon;
    std::vector<cv::Rect> m_BoundingRect;
    std::vector<cv::Moments> m_Moments;
    std::vector<cv::Point> m_Centroid;
    std::vector<cv::Point2f> m_Features;

    void m_createContours();
    void m_createExtensions();
};

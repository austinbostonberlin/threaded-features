# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`ofApp`](#classofApp) | A simple reference implementation of countour finder and corner detectors It has a small extra feature to draw a rectangle to record the computer vision data from and interact with it. This is useful to store the countours and reannimate them, or any prcedures that require the objects inside an image to be detected.
`class `[`threadedContourFinder`](#classthreadedContourFinder) | A collection of extentions to `openCV` API with multithreading where relevant.

# class `ofApp` 

```
class ofApp
  : public ofBaseApp
```  

A simple reference implementation of countour finder and corner detectors It has a small extra feature to draw a rectangle to record the computer vision data from and interact with it. This is useful to store the countours and reannimate them, or any prcedures that require the objects inside an image to be detected.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public int `[`sampleRate`](#classofApp_1abd83953a5dcff8f0deabbfc2a0170d98) | 
`public int `[`bufferSize`](#classofApp_1af573fde175597807abfefd7b1c34c457) | 
`public cv::Mat `[`img`](#classofApp_1a1001f3ce9be388c3c98f12b7c24587ce) | 
`public cv::UMat `[`Uimg`](#classofApp_1a9b735d0daee97c4917cfa72dc0906ea4) | 
`public ofImage `[`image`](#classofApp_1af365e800662ba93c862351eddac0d6cd) | 
`public ofVideoGrabber `[`camera`](#classofApp_1ad5ddf6e5cb333a5c43a711dfe2f3973e) | An abstraction layer to interface with `GStreamer` API This is the method to get data from hardware camera.
`public `[`threadedContourFinder`](#classthreadedContourFinder)` `[`find`](#classofApp_1a97a40eab0565a80b0f3a88c072fd2266) | 
`public std::vector< glm::vec2 > `[`centroid`](#classofApp_1a48aeff8d4ba3a7d75c8e403a0b2d2799) | 
`public std::vector< glm::vec2 > `[`features`](#classofApp_1a70ddd9903335fcec0f9fd5bed93dd557) | 
`public int `[`x1`](#classofApp_1aa5bb391584f1c6aa2b115b3945780310) | 
`public int `[`y1`](#classofApp_1a06b137f4828ac559c55b5b65b2053262) | 
`public int `[`x2`](#classofApp_1a42d2dd733578a5f1fb6a55b786a9e7e2) | 
`public int `[`y2`](#classofApp_1ab1523270bd6a606b4dfa4d0128d7fb9c) | 
`public bool `[`rectDone`](#classofApp_1a5de78a3ba581b58c2553c879a4650f5b) | 
`public ofRectangle `[`mouseRect`](#classofApp_1a0b6ad2c9721f43b8f88ea691f6ce53cf) | Dynamic interactable rectangle.
`public void `[`setup`](#classofApp_1af68eaa1366244f7a541cd08e02199c12)`()` | 
`public void `[`update`](#classofApp_1afef41ea4aee5a22ea530afba33ae7a7b)`()` | 
`public void `[`draw`](#classofApp_1a75dd45437b9e317db73d8daef1ad49f8)`()` | Draw a rectanlge using `ofRect` to trace the openCV data within that rect The current properties of the world matrix are pushed by OpenGl to allow direct interaction with the rectangle 
`public void `[`audioOut`](#classofApp_1aae87e3581084ad5b4fa5584f0871092e)`(ofSoundBuffer & buffer)` | 
`public void `[`exit`](#classofApp_1a41588341bbe9be134f6abdc2eb7cfd4c)`()` | 
`public void `[`mousePressed`](#classofApp_1a2c2ea9c160231e55424dfd98466ef27d)`(int x,int y,int button)` | Start drawing the rectangle on left mouse press.
`public void `[`mouseReleased`](#classofApp_1aa3131f1554fc49eaa9ee0f284e48129b)`(int x,int y,int button)` | Stop drawing the rectangle on left mouse release.

## Members

#### `public int `[`sampleRate`](#classofApp_1abd83953a5dcff8f0deabbfc2a0170d98) 

#### `public int `[`bufferSize`](#classofApp_1af573fde175597807abfefd7b1c34c457) 

#### `public cv::Mat `[`img`](#classofApp_1a1001f3ce9be388c3c98f12b7c24587ce) 

#### `public cv::UMat `[`Uimg`](#classofApp_1a9b735d0daee97c4917cfa72dc0906ea4) 

#### `public ofImage `[`image`](#classofApp_1af365e800662ba93c862351eddac0d6cd) 

#### `public ofVideoGrabber `[`camera`](#classofApp_1ad5ddf6e5cb333a5c43a711dfe2f3973e) 

An abstraction layer to interface with `GStreamer` API This is the method to get data from hardware camera.

#### `public `[`threadedContourFinder`](#classthreadedContourFinder)` `[`find`](#classofApp_1a97a40eab0565a80b0f3a88c072fd2266) 

#### `public std::vector< glm::vec2 > `[`centroid`](#classofApp_1a48aeff8d4ba3a7d75c8e403a0b2d2799) 

#### `public std::vector< glm::vec2 > `[`features`](#classofApp_1a70ddd9903335fcec0f9fd5bed93dd557) 

#### `public int `[`x1`](#classofApp_1aa5bb391584f1c6aa2b115b3945780310) 

#### `public int `[`y1`](#classofApp_1a06b137f4828ac559c55b5b65b2053262) 

#### `public int `[`x2`](#classofApp_1a42d2dd733578a5f1fb6a55b786a9e7e2) 

#### `public int `[`y2`](#classofApp_1ab1523270bd6a606b4dfa4d0128d7fb9c) 

#### `public bool `[`rectDone`](#classofApp_1a5de78a3ba581b58c2553c879a4650f5b) 

#### `public ofRectangle `[`mouseRect`](#classofApp_1a0b6ad2c9721f43b8f88ea691f6ce53cf) 

Dynamic interactable rectangle.

#### `public void `[`setup`](#classofApp_1af68eaa1366244f7a541cd08e02199c12)`()` 

#### `public void `[`update`](#classofApp_1afef41ea4aee5a22ea530afba33ae7a7b)`()` 

#### `public void `[`draw`](#classofApp_1a75dd45437b9e317db73d8daef1ad49f8)`()` 

Draw a rectanlge using `ofRect` to trace the openCV data within that rect The current properties of the world matrix are pushed by OpenGl to allow direct interaction with the rectangle 
```cpp
if (rectDone) {
       ofDrawRectangle([mouseRect](#classofApp_1a0b6ad2c9721f43b8f88ea691f6ce53cf));
       ofPushMatrix();
       ofTranslate(mouseX, mouseY);
       // Do operations here
       ofPopMatrix();
   }
```
 After the interactions are executed, the matrix is popped back on to the stack

#### `public void `[`audioOut`](#classofApp_1aae87e3581084ad5b4fa5584f0871092e)`(ofSoundBuffer & buffer)` 

#### `public void `[`exit`](#classofApp_1a41588341bbe9be134f6abdc2eb7cfd4c)`()` 

#### `public void `[`mousePressed`](#classofApp_1a2c2ea9c160231e55424dfd98466ef27d)`(int x,int y,int button)` 

Start drawing the rectangle on left mouse press.

#### `public void `[`mouseReleased`](#classofApp_1aa3131f1554fc49eaa9ee0f284e48129b)`(int x,int y,int button)` 

Stop drawing the rectangle on left mouse release.

# class `threadedContourFinder` 

```
class threadedContourFinder
  : public ofThread
```  

A collection of extentions to `openCV` API with multithreading where relevant.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public void `[`createContours`](#classthreadedContourFinder_1a7fbfee65e409bfb7d3603f17e342d935)`(cv::UMat img,cv::UMat imgDraw)` | Create contours for the given image. Return it to a different image This call starts the thread specified by `[threadedContourFinder::threadedFunction](#classthreadedContourFinder_1ab5eb4e07311764d784c535747ac7af6a)`. Both image matrix are parallelized by `OpenCL`
`public void `[`createContours`](#classthreadedContourFinder_1a1e62834f555bed8fff52960076df0705)`(cv::UMat img)` | Same as `[threadedContourFinder::createContours(cv::UMat img, cv::UMat imgDraw)](#classthreadedContourFinder_1a7fbfee65e409bfb7d3603f17e342d935)` but this function overrites the input image. 
`public void `[`threadedFunction`](#classthreadedContourFinder_1ab5eb4e07311764d784c535747ac7af6a)`()` | The threaded call to `cv::createContours` It uses the following steps: Gaussian blur, canny edge detection, dilation and erosion It additionally creates extensions such as calculating bounding rectangle for the contour, the center of mass for the contour and the approximate polygon to contain the contour.
`public std::vector< glm::vec2 > `[`getContours`](#classthreadedContourFinder_1a6aa14406e627bb82c02eaa9f51687443)`()` | Convert and return `std::vector<cv::Point>` to `std::vector<glm::vec2>`
`public std::vector< ofPolyline > `[`getContourShape`](#classthreadedContourFinder_1a7d7ffb1a86876bb8de4f16d1d2b77af2)`()` | Convert `std::vector<cv::point>` to `ofPolyline`. `ofPolyline` can be used to directly supply vertices ot `openGL`
`public std::vector< glm::vec2 > `[`getCentroids`](#classthreadedContourFinder_1ab68c0ec1c77b867064ceb2a29e4389f5)`()` | Return the center of mass for each blob as `glm::vec2` coordinates.
`public std::vector< glm::vec2 > `[`getFeatures`](#classthreadedContourFinder_1ae55cb95507d867197f469d1d51adcdcc)`()` | Returns the corner vertices calculated by *She & Thomasi* corner detectiona algorithm.
`public std::vector< glm::vec2 > `[`tFeatures`](#classthreadedContourFinder_1a246a69a225e96317c370a6c999eb0831)`()` | Async call to `[threadedContourFinder::getFeatures](#classthreadedContourFinder_1ae55cb95507d867197f469d1d51adcdcc)` in a separate thread.
`public inline void `[`setkernel`](#classthreadedContourFinder_1ad0f114f84cb2b4d282a7507c6c4e4d45)`(cv::Mat newKernel)` | Set the kernel matrix to be used for convolution processes 
`public inline void `[`setGaussian`](#classthreadedContourFinder_1a2085f3e72dc4a24f6b218d4cf6b6131a)`(int kernelSize,float sigmaX,float sigmaY)` | Set the kernel size and standard deviation 
`public inline void `[`hysterisisThresholds`](#classthreadedContourFinder_1a80c9bdc429cf6b48545da0c7bb3f6fab)`(int lower,int upper)` | Set bounds for hysterisis thresholding 
`public inline void `[`setMinDistance`](#classthreadedContourFinder_1a1cf3afc5d6ea9ad84d705d4a670a4129)`(double distance)` | Minimum possible euclidean distance between returned corners for the corner detection algorithm 
`public inline void `[`setQualityLevel`](#classthreadedContourFinder_1aa3039c2c28785d9226795c2acde3f6d9)`(double quality)` | Set the minimum quality level for determinant and trace operations for *Shi Tomasi* Corner detection algorithm 
`public inline void `[`setNumCorners`](#classthreadedContourFinder_1aa4a729f1c2637b39025962def98d285e)`(int corners)` | Set maximum number of corners to return after successful corner detection.
`public inline void `[`printContours`](#classthreadedContourFinder_1a7bb67a8cee04e13c8752eeddfbfecbdb)`()` | Pipe the co-ordinates of the detected contours to `stdout`
`public void `[`drawContours`](#classthreadedContourFinder_1a6d4d0aaa6c06087c756ed2a981bbb28b)`(cv::UMat & img)` | Draw contours over the supplied image. 
`public void `[`drawBoundingRect`](#classthreadedContourFinder_1ac007880f5f324502cff1cf1b6e2efd6f)`(cv::UMat & img)` | Draw bounding rectangle around the contours over the supplied image. 
`public void `[`drawContourPolygon`](#classthreadedContourFinder_1ab90116e3a0096224d10168f07b79a93a)`(cv::UMat & img)` | Draw an approximate polygon around the contours over the supplied image. 

## Members

#### `public void `[`createContours`](#classthreadedContourFinder_1a7fbfee65e409bfb7d3603f17e342d935)`(cv::UMat img,cv::UMat imgDraw)` 

Create contours for the given image. Return it to a different image This call starts the thread specified by `[threadedContourFinder::threadedFunction](#classthreadedContourFinder_1ab5eb4e07311764d784c535747ac7af6a)`. Both image matrix are parallelized by `OpenCL`
#### Parameters
* `img` Input image in `cv` format. 

* `imgDraw` Empty image to output contours in `cv` format.

#### `public void `[`createContours`](#classthreadedContourFinder_1a1e62834f555bed8fff52960076df0705)`(cv::UMat img)` 

Same as `[threadedContourFinder::createContours(cv::UMat img, cv::UMat imgDraw)](#classthreadedContourFinder_1a7fbfee65e409bfb7d3603f17e342d935)` but this function overrites the input image. 
#### Parameters
* `img` The image matrix containing the pixels. **WARNING**: The image will be overwritten

#### `public void `[`threadedFunction`](#classthreadedContourFinder_1ab5eb4e07311764d784c535747ac7af6a)`()` 

The threaded call to `cv::createContours` It uses the following steps: Gaussian blur, canny edge detection, dilation and erosion It additionally creates extensions such as calculating bounding rectangle for the contour, the center of mass for the contour and the approximate polygon to contain the contour.

#### `public std::vector< glm::vec2 > `[`getContours`](#classthreadedContourFinder_1a6aa14406e627bb82c02eaa9f51687443)`()` 

Convert and return `std::vector<cv::Point>` to `std::vector<glm::vec2>`

#### `public std::vector< ofPolyline > `[`getContourShape`](#classthreadedContourFinder_1a7d7ffb1a86876bb8de4f16d1d2b77af2)`()` 

Convert `std::vector<cv::point>` to `ofPolyline`. `ofPolyline` can be used to directly supply vertices ot `openGL`

#### `public std::vector< glm::vec2 > `[`getCentroids`](#classthreadedContourFinder_1ab68c0ec1c77b867064ceb2a29e4389f5)`()` 

Return the center of mass for each blob as `glm::vec2` coordinates.

#### `public std::vector< glm::vec2 > `[`getFeatures`](#classthreadedContourFinder_1ae55cb95507d867197f469d1d51adcdcc)`()` 

Returns the corner vertices calculated by *She & Thomasi* corner detectiona algorithm.

#### `public std::vector< glm::vec2 > `[`tFeatures`](#classthreadedContourFinder_1a246a69a225e96317c370a6c999eb0831)`()` 

Async call to `[threadedContourFinder::getFeatures](#classthreadedContourFinder_1ae55cb95507d867197f469d1d51adcdcc)` in a separate thread.

#### `public inline void `[`setkernel`](#classthreadedContourFinder_1ad0f114f84cb2b4d282a7507c6c4e4d45)`(cv::Mat newKernel)` 

Set the kernel matrix to be used for convolution processes 
#### Parameters
* `newKernel` a `cv::Mat` matrix

#### `public inline void `[`setGaussian`](#classthreadedContourFinder_1a2085f3e72dc4a24f6b218d4cf6b6131a)`(int kernelSize,float sigmaX,float sigmaY)` 

Set the kernel size and standard deviation 
#### Parameters
* `kernelSize` length of rows and column for matrix 

* `sigmaX` Standar deviation in X direction 

* `sigmaY` Standar deviation in Y direction

#### `public inline void `[`hysterisisThresholds`](#classthreadedContourFinder_1a80c9bdc429cf6b48545da0c7bb3f6fab)`(int lower,int upper)` 

Set bounds for hysterisis thresholding 
#### Parameters
* `lower` 1st or lower threshold 

* `upper` 2nd or upper threshold

#### `public inline void `[`setMinDistance`](#classthreadedContourFinder_1a1cf3afc5d6ea9ad84d705d4a670a4129)`(double distance)` 

Minimum possible euclidean distance between returned corners for the corner detection algorithm 
#### Parameters
* `distance` Minimum distance

#### `public inline void `[`setQualityLevel`](#classthreadedContourFinder_1aa3039c2c28785d9226795c2acde3f6d9)`(double quality)` 

Set the minimum quality level for determinant and trace operations for *Shi Tomasi* Corner detection algorithm 
#### Parameters
* `quality` The minimum eigen value

#### `public inline void `[`setNumCorners`](#classthreadedContourFinder_1aa4a729f1c2637b39025962def98d285e)`(int corners)` 

Set maximum number of corners to return after successful corner detection.

#### `public inline void `[`printContours`](#classthreadedContourFinder_1a7bb67a8cee04e13c8752eeddfbfecbdb)`()` 

Pipe the co-ordinates of the detected contours to `stdout`

#### `public void `[`drawContours`](#classthreadedContourFinder_1a6d4d0aaa6c06087c756ed2a981bbb28b)`(cv::UMat & img)` 

Draw contours over the supplied image. 
#### Parameters
* `img` An image to write or overwrite with contours

#### `public void `[`drawBoundingRect`](#classthreadedContourFinder_1ac007880f5f324502cff1cf1b6e2efd6f)`(cv::UMat & img)` 

Draw bounding rectangle around the contours over the supplied image. 
#### Parameters
* `img` An image to write or overwrite with the bounding rectangle

#### `public void `[`drawContourPolygon`](#classthreadedContourFinder_1ab90116e3a0096224d10168f07b79a93a)`(cv::UMat & img)` 

Draw an approximate polygon around the contours over the supplied image. 
#### Parameters
* `img` An image to write or overwrite with the approximate polygon

Generated by [Moxygen](https://sourcey.com/moxygen)
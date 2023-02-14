# Frames substraction motion detection

This project uses OpenCV video capture (from standard video input stream) and frame filtering to detect ant difference in the picture. Refreshing (comparing) rate is at each second frame. Difference is calculated in this formula: `difference = (current frame) - (previous frame)`. 

Each frame is processed to set every pixel to white if sum of its RGB values is more than some value and to black if not. Additionally a few methods of noise reduction are applied to substracted image. In this filtered image a k-means clustering is applied and drawn on the input image. 

Output video:

![](https://github.com/korzck/motion-detection/blob/main/example2.gif)

Filtered substracted image with k-means:

![](https://github.com/korzck/motion-detection/blob/main/example1.gif)


## TODO:

- Apply Gaussian Mixture Models to cluster detections (somehow)

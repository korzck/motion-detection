# Frames substraction motion detection

This project uses OpenCV video capture (from standard video input stream) and frame filtering to detect ant difference in the picture. Refreshing (comparing) rate is at each second frame. Difference is calculated in this formula: `difference = (current frame) - (previous frame)`. 

Each frame is processed to set every pixel to white if sum of its RGB values is more than 50 and to black if not. In this filtered image a k-means clustering is applied. But for now its only one centroid calculated in


![](https://github.com/korzck/motion-detection/blob/main/example1.gif)


## TODO:

- Apply k-means method to draw rectangles around detections
- Apply Gaussian Mixture Models to cluster detections (somehow)
- Compare these two

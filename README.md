# Frames substraction motion detection

This project uses OpenCV video capture (from standard video input stream) and frame filtering to detect ant difference in the picture. Refreshing (comparing) rate is at each second frame. Difference is calculated in this formula: `difference = (current frame) - (previous frame)`. 

Amplifying matrix for example 1:
```
-1 -1 -1
-1 50 -1
-1 -1 -1
```

![](https://github.com/korzck/motion-detection/blob/main/example1.gif)

Blacking matrix for example 2:
```
-1 1 -1
-1 1 -1
-1 1 -1
```

![](https://github.com/korzck/motion-detection/blob/main/example2.gif)


## TODO:

- Apply k-means method to draw rectangles around detections
- Apply Gaussian Mixture Models to cluster detections (somehow)
- Compare these two

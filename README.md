# Frames substraction motion detection

This project uses OpenCV video capture (from `/dev/video0` stream) and frame filtering to detect ant difference in the picture. Refreshing (comparing) rate is at each second frame, in other wirds difference is calculated by this matrix formula: `difference = (current frame) - (previous frame)`. 

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

compilation: camera_input.cpp
	g++ camera_input.cpp -I /usr/local/include/opencv4/ \
	-lopencv_core \
	-lopencv_highgui \
	-lopencv_imgcodecs \
	-lopencv_imgproc \
	-I /usr/local/include/opencv4/ \
	-I /usr/local/include/opencv4/opencv2/ \
	-L /usr/local/lib/*.so \
	-L /usr/local/bin/
	
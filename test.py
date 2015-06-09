#!/usr/bin/env python2

import cv2
import signal
import pyfreenect2

# This is pretty much a straight port of the Protonect program bundled with
# libfreenect2.

# Initialize device
serialNumber = pyfreenect2.getDefaultDeviceSerialNumber()
kinect = pyfreenect2.Freenect2Device(serialNumber)

# Set up signal handler
shutdown = False
def sigint_handler(signum, frame):
	print "Got SIGINT, shutting down..."
	shutdown = True
signal.signal(signal.SIGINT, sigint_handler)

# Set up frame listener
frameListener = pyfreenect2.SyncMultiFrameListener(pyfreenect2.Frame.COLOR,
	pyfreenect2.Frame.IR,
	pyfreenect2.Frame.DEPTH)
kinect.setColorFrameListener(frameListener)
kinect.setIrAndDepthFrameListener(frameListener)

# Start recording
kinect.start()

# Print useful info
print "Kinect serial: %s" % kinect.serial_number
print "Kinect firmware: %s" % kinect.firmware_version

# What's a registration?
registration = pyfreenect2.Registration(kinect.ir_camera_params, kinect.color_camera_params)

# Initialize OpenCV stuff
cv2.startWindowThread()
cv2.namedWindow("RGB")
# cv2.namedWindow("IR")
# cv2.namedWindow("Depth")

# Main loop
while not shutdown:
	frames = frameListener.waitForNewFrame()
	rgbFrame = frames.getFrame(pyfreenect2.Frame.COLOR)
	irFrame = frames.getFrame(pyfreenect2.Frame.IR)
	depthFrame = frames.getFrame(pyfreenect2.Frame.DEPTH)

	# TODO Display the frames w/ OpenCV
	cv2.imshow("RGB", rgbFrame.getData())
    # cv::imshow("rgb", cv::Mat(rgb->height, rgb->width, CV_8UC3, rgb->data));
    # cv::imshow("ir", cv::Mat(ir->height, ir->width, CV_32FC1, ir->data) / 20000.0f);
    # cv::imshow("depth", cv::Mat(depth->height, depth->width, CV_32FC1, depth->data) / 4500.0f);

    # if (!registered) registered = new unsigned char[depth->height*depth->width*rgb->bytes_per_pixel];
    # registration->apply(rgb,depth,registered);
    # cv::imshow("registered", cv::Mat(depth->height, depth->width, CV_8UC3, registered));

    # int key = cv::waitKey(1);
    # protonect_shutdown = protonect_shutdown || (key > 0 && ((key & 0xFF) == 27)); // shutdown on escape

kinect.stop()
kinect.close()

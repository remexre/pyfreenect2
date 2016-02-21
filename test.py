#!/usr/bin/env python

import cv2
import scipy.misc
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

print frameListener
kinect.setColorFrameListener(frameListener)
kinect.setIrAndDepthFrameListener(frameListener)

# Start recording
kinect.start()

# Print useful info
print "Kinect serial: %s" % kinect.serial_number
print "Kinect firmware: %s" % kinect.firmware_version

# What's a registration?
print kinect.ir_camera_params

registration = pyfreenect2.Registration(kinect.ir_camera_params, kinect.color_camera_params)
#registration = pyfreenect2.Registration(kinect.color_camera_params, kinect.ir_camera_params)
#registration = pyfreenect2.Registration()

# Initialize OpenCV stuff
cv2.namedWindow("RGB")
# cv2.namedWindow("IR")
cv2.namedWindow("Depth")

# Main loop
while not shutdown:
	frames = frameListener.waitForNewFrame()
	rgbFrame = frames.getFrame(pyfreenect2.Frame.COLOR)
#	irFrame = frames.getFrame(pyfreenect2.Frame.IR)
        depthFrame = frames.getFrame(pyfreenect2.Frame.DEPTH)

        rgb_frame = rgbFrame.getRGBData()
        bgr_frame = rgb_frame.copy()
        bgr_frame[:,:,0] = rgb_frame[:,:,2]
        bgr_frame[:,:,2] = rgb_frame[:,:,0]

        depth_frame = depthFrame.getDepthData()
#        depth_frame = frames.getFrame(pyfreenect2.Frame.DEPTH).getData()

        bgr_frame_resize = scipy.misc.imresize(bgr_frame, size = .5)
        depth_frame_resize = scipy.misc.imresize(depth_frame, size = .5)

	# TODO Display the frames w/ OpenCV
	cv2.imshow("RGB", bgr_frame_resize)
	cv2.imshow("Depth", depth_frame_resize)
        cv2.waitKey(20)

kinect.stop()
kinect.close()

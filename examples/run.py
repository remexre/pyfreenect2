import pyfreenect2
import cv2
import scipy.misc
import signal
import numpy as np

pf = pyfreenect2.PyFreeNect2()

cv2.startWindowThread()
cv2.namedWindow("RGB")
while True:
    extracted_frame = pf.get_new_frame()
    resized = scipy.misc.imresize(extracted_frame.RGB, size = 0.5)
    cv2.imshow("RGB", resized)
    cv2.waitKey(20)
print "done"
    

#include "pyfreenect2.hpp"
#include <iostream>

static PyMethodDef pyfreenect2Methods[] = {
	// Freenect2
	{ "numberOfDevices", py_numberOfDevices, METH_VARARGS, NULL },
	{ "getDefaultDeviceSerialNumber", py_getDefaultDeviceSerialNumber, METH_VARARGS, NULL },
	// Freenect2Device
	{ "Freenect2Device_new", py_Freenect2Device_new, METH_VARARGS, NULL },
	{ "Freenect2Device_start", py_Freenect2Device_start, METH_VARARGS, NULL },
	{ "Freenect2Device_stop", py_Freenect2Device_stop, METH_VARARGS, NULL },
	{ "Freenect2Device_setColorFrameListener", py_Freenect2Device_setColorFrameListener, METH_VARARGS, NULL },
	{ "Freenect2Device_setIrAndDepthFrameListener", py_Freenect2Device_setIrAndDepthFrameListener, METH_VARARGS, NULL },
	{ "Freenect2Device_getSerialNumber", py_Freenect2Device_getSerialNumber, METH_VARARGS, NULL },
	{ "Freenect2Device_getFirmwareVersion", py_Freenect2Device_getFirmwareVersion, METH_VARARGS, NULL },
	{ "Freenect2Device_getColorCameraParams", py_Freenect2Device_getColorCameraParams, METH_VARARGS, NULL },
	{ "Freenect2Device_getIRCameraParams", py_Freenect2Device_getIRCameraParams, METH_VARARGS, NULL },
	// SyncMultiFrameListener
	{ "SyncMultiFrameListener_new", py_SyncMultiFrameListener_new, METH_VARARGS, NULL },
	{ "SyncMultiFrameListener_waitForNewFrame", py_SyncMultiFrameListener_waitForNewFrame, METH_VARARGS, NULL },
	{ "SyncMultiFrameListener_release", py_SyncMultiFrameListener_release, METH_VARARGS, NULL },
	// Registration
	{ "Registration_new", py_Registration_new, METH_VARARGS, NULL },
	{ "Registration_apply", py_Registration_apply, METH_VARARGS, NULL },
	// FrameMap
	{ "FrameMap_getFrame", py_FrameMap_getFrame, METH_VARARGS, NULL },
	// Frame
	{ "Frame_getHeight", py_Frame_getHeight, METH_VARARGS, NULL },
	{ "Frame_getWidth", py_Frame_getWidth, METH_VARARGS, NULL },
	{ "Frame_getData", py_Frame_getData, METH_VARARGS, NULL },
	{ "Frame_getDepthData", py_Frame_getDepthData, METH_VARARGS, NULL },
	// Sentinel
	{ NULL, NULL, 0, NULL}
};

PyMODINIT_FUNC init_pyfreenect2() {

  /// enables debug of libfreenect2
  ///libfreenect2::setGlobalLogger(libfreenect2::createConsoleLogger(libfreenect2::Logger::Debug));

  import_array();
  Py_InitModule("_pyfreenect2", pyfreenect2Methods);
  import_array();
}

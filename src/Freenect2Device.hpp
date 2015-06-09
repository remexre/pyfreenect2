#pragma once

#include <Python.h>

PyObject *py_Freenect2Device_new(PyObject *self, PyObject *args);
void py_Freenect2Device_destroy(PyObject *deviceCapsule);

PyObject *py_Freenect2Device_start(PyObject *self, PyObject *args);
PyObject *py_Freenect2Device_stop(PyObject *self, PyObject *args);

PyObject *py_Freenect2Device_setColorFrameListener(PyObject *self, PyObject *args);
PyObject *py_Freenect2Device_setIrAndDepthFrameListener(PyObject *self, PyObject *args);

PyObject *py_Freenect2Device_getSerialNumber(PyObject *self, PyObject *args);
PyObject *py_Freenect2Device_getFirmwareVersion(PyObject *self, PyObject *args);
PyObject *py_Freenect2Device_getColorCameraParams(PyObject *self, PyObject *args);
PyObject *py_Freenect2Device_getIRCameraParams(PyObject *self, PyObject *args);

void py_Freenect2Device_ColorCameraParams_destroy(PyObject *colorCameraParamsCapsule);
void py_Freenect2Device_IRCameraParams_destroy(PyObject *irCameraParamsCapsule);

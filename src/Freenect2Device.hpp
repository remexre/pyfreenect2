#pragma once

#include <Python.h>

PyObject *py_Freenect2Device_new(PyObject *self, PyObject *args);
PyObject *py_Freenect2Device_delete(PyObject *self, PyObject *args);

PyObject *py_Freenect2Device_start(PyObject *self, PyObject *args);
PyObject *py_Freenect2Device_stop(PyObject *self, PyObject *args);
PyObject *py_Freenect2Device_close(PyObject *self, PyObject *args);

PyObject *py_Freenect2Device_setColorFrameListener(PyObject *self, PyObject *args);
PyObject *py_Freenect2Device_setIrAndDepthFrameListener(PyObject *self, PyObject *args);

PyObject *py_Freenect2Device_getSerialNumber(PyObject *self, PyObject *args);
PyObject *py_Freenect2Device_getFirmwareVersion(PyObject *self, PyObject *args);
PyObject *py_Freenect2Device_getIRCameraParams(PyObject *self, PyObject *args);
PyObject *py_Freenect2Device_getColorCameraParams(PyObject *self, PyObject *args);

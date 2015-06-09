#pragma once

#include <Python.h>

#include <string>
#include <libfreenect2/libfreenect2.hpp>

libfreenect2::Freenect2& getGlobalFreenect2();
PyObject *py_numberOfDevices(PyObject *self, PyObject *args);
PyObject *py_getDefaultDeviceSerialNumber(PyObject *self, PyObject *args);

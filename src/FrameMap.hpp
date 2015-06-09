#pragma once

#include <Python.h>

PyObject *py_FrameMap_new(PyObject *self, PyObject *args);
PyObject *py_FrameMap_delete(PyObject *self, PyObject *args);

PyObject *py_FrameMap_getFrame(PyObject *self, PyObject *args);

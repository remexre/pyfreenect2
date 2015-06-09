#pragma once

#include <Python.h>

PyObject *py_FrameMap_new(PyObject *self, PyObject *args);
void py_FrameMap_destroy(PyObject *object);

PyObject *py_FrameMap_getFrame(PyObject *self, PyObject *args);

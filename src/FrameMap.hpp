#pragma once

#include <Python.h>

void py_FrameMap_destroy(PyObject *object);

PyObject *py_FrameMap_getFrame(PyObject *self, PyObject *args);

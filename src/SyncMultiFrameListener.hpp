#pragma once

#include <Python.h>

PyObject *py_SyncMultiFrameListener_new(PyObject *self, PyObject *args);
void py_SyncMultiFrameListener_destroy(PyObject *object);

PyObject *py_SyncMultiFrameListener_waitForNewFrame(PyObject *self, PyObject *args);

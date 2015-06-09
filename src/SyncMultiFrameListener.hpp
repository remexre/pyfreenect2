#pragma once

#include <Python.h>

PyObject *py_SyncMultiFrameListener_new(PyObject *self, PyObject *args);
PyObject *py_SyncMultiFrameListener_delete(PyObject *self, PyObject *args);

PyObject *py_SyncMultiFrameListener_waitForNewFrame(PyObject *self, PyObject *args);

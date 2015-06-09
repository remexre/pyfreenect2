#pragma once

#include <Python.h>

PyObject *py_Registration_new(PyObject *self, PyObject *args);
void py_Registration_destroy(PyObject *object);

PyObject *py_Registration_apply(PyObject *self, PyObject *args);

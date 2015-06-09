#include "Frame.hpp"

#include <string>
#include <libfreenect2/libfreenect2.hpp>

using libfreenect2::Frame;

void py_Frame_destroy(PyObject *frameCapsule) {
	delete ((Frame*) PyCapsule_GetPointer(frameCapsule, "Frame"));
}

// PyObject *py_Frame_getHeight(PyObject *self, PyObject *args);
// PyObject *py_Frame_getWidth(PyObject *self, PyObject *args);
// PyObject *py_Frame_getData(PyObject *self, PyObject *args);

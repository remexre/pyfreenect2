#include "Frame.hpp"

#include <string>
#include <libfreenect2/libfreenect2.hpp>

using libfreenect2::Frame;

void py_Frame_destroy(PyObject *frameCapsule) {
	delete ((Frame*) PyCapsule_GetPointer(frameCapsule, "Frame"));
}

PyObject *py_Frame_getHeight(PyObject *self, PyObject *args) {
	PyObject *frameCapsule = NULL;
	if(!PyArg_ParseTuple(args, "O", &frameCapsule))
		return NULL;
	Frame *frame = (Frame*) PyCapsule_GetPointer(frameCapsule, "Frame");
	return PyInt_FromSize_t(frame->height);
}
PyObject *py_Frame_getWidth(PyObject *self, PyObject *args) {
	PyObject *frameCapsule = NULL;
	if(!PyArg_ParseTuple(args, "O", &frameCapsule))
		return NULL;
	Frame *frame = (Frame*) PyCapsule_GetPointer(frameCapsule, "Frame");
	return PyInt_FromSize_t(frame->width);
}
// PyObject *py_Frame_getData(PyObject *self, PyObject *args);

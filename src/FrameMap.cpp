#include "../pyfreenect2.hpp"

using libfreenect2::Frame;
using libfreenect2::FrameMap;

void py_FrameMap_destroy(PyObject *frameMapCapsule) {
	delete ((FrameMap*) PyCapsule_GetPointer(frameMapCapsule, "FrameMap"));
}

PyObject *py_FrameMap_getFrame(PyObject *self, PyObject *args) {
	Frame::Type type = (Frame::Type) 0;
	PyObject *frameMapCapsule = NULL;
	if(!PyArg_ParseTuple(args, "OI", &frameMapCapsule, &type))
		return NULL;
	FrameMap *frameMap = (FrameMap*) PyCapsule_GetPointer(frameMapCapsule, "FrameMap");
	return PyCapsule_New((*frameMap)[type], "Frame", py_Frame_destroy);
}

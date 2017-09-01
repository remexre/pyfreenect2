#include "../pyfreenect2.hpp"
#include <iostream>
#include "SmartFrame.h"

using libfreenect2::Frame;
using libfreenect2::FrameMap;

void py_FrameMap_destroy(PyObject *frameMapCapsule) {
	delete ((SPFrameMap*) PyCapsule_GetPointer(frameMapCapsule, "FrameMap"));
}

PyObject *py_FrameMap_getFrame(PyObject *self, PyObject *args) {
	Frame::Type type = (Frame::Type) 0;
	PyObject *frameMapCapsule = NULL;
	if(!PyArg_ParseTuple(args, "OI", &frameMapCapsule, &type))
		return NULL;
	SPFrameMap *frameMap = (SPFrameMap*) PyCapsule_GetPointer(frameMapCapsule, "FrameMap");
	SPFrameMap::iterator it = frameMap->find(type);
	return PyCapsule_New(new SPFrame(it->second), "Frame", py_Frame_destroy);
}

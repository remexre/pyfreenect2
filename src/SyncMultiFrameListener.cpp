#include "SyncMultiFrameListener.hpp"
#include "FrameMap.hpp"

#include <libfreenect2/frame_listener_impl.h>

using libfreenect2::FrameMap;
using libfreenect2::SyncMultiFrameListener;

PyObject *py_SyncMultiFrameListener_new(PyObject *self, PyObject *args) {
	unsigned int frame_types = 0;
	if(!PyArg_ParseTuple(args, "I", &frame_types))
		return NULL;
	SyncMultiFrameListener *listener = new SyncMultiFrameListener(frame_types);
	return PyCapsule_New(listener, "SyncMultiFrameListener", py_SyncMultiFrameListener_destroy);
}
void py_SyncMultiFrameListener_destroy(PyObject *listenerCapsule) {
	delete ((SyncMultiFrameListener*) PyCapsule_GetPointer(listenerCapsule, "SyncMultiFrameListener"));
}

PyObject *py_SyncMultiFrameListener_waitForNewFrame(PyObject *self, PyObject *args) {
	PyObject *listenerCapsule = NULL;
	if(!PyArg_ParseTuple(args, "O", &listenerCapsule))
		return NULL;
	SyncMultiFrameListener *listener = (SyncMultiFrameListener*) PyCapsule_GetPointer(listenerCapsule, "SyncMultiFrameListener");
	FrameMap *frames = new FrameMap;
	listener->waitForNewFrame(*frames);
	return PyCapsule_New(frames, "FrameMap", py_FrameMap_destroy);
}

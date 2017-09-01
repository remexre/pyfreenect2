#include "../pyfreenect2.hpp"
#include <iostream>
#include "SmartFrame.h"

using libfreenect2::FrameMap;
using libfreenect2::SyncMultiFrameListener;

void py_SyncMultiFrameListener_destroy(PyObject *listenerCapsule) {
	delete ((SyncMultiFrameListener*) PyCapsule_GetPointer(listenerCapsule, 
							       "SyncMultiFrameListener"));
}

PyObject *py_SyncMultiFrameListener_new(PyObject *self, PyObject *args) {
	unsigned int frame_types = 0;
	if(!PyArg_ParseTuple(args, "I", &frame_types))
		return NULL;
	SyncMultiFrameListener *listener = new SyncMultiFrameListener(frame_types);
	std::cout << "listener in ext: " << listener << std::endl;
	return PyCapsule_New(listener, 
			     "SyncMultiFrameListener", 
			     py_SyncMultiFrameListener_destroy);
}

PyObject *py_SyncMultiFrameListener_waitForNewFrame(PyObject *self, PyObject *args) {
	PyObject *listenerCapsule = NULL;
	if(!PyArg_ParseTuple(args, "O", &listenerCapsule))
		return NULL;
	SyncMultiFrameListener *listener = (SyncMultiFrameListener*) PyCapsule_GetPointer(listenerCapsule, "SyncMultiFrameListener");
	FrameMap* frames = new FrameMap();
	listener->waitForNewFrame(*frames);
	SPFrameMap * spFrames = getSPFrameMapFromFrameMap(frames);
	delete frames;
	PyObject * pyObj = PyCapsule_New(spFrames, "FrameMap", py_FrameMap_destroy);
	//std::cout << "waitForNewFrame: " << (void*)pyObj << "::" << (void*)listenerCapsule << std::endl;
	return pyObj;
}

/*
void SyncMultiFrameListener::release(FrameMap &frame)
{
  for(FrameMap::iterator it = frame.begin(); it != frame.end(); ++it)
  {
    delete it->second;
    it->second = 0;
  }

  frame.clear();

  {
    libfreenect2::lock_guard l(impl_->mutex_);
    impl_->current_frame_released_ = true;
  }
}
*/
/** Shortcut to delete all frames 
* There is a lock ,if not call release we will only get one frame
*/
PyObject * py_SyncMultiFrameListener_release(PyObject *self, PyObject *args) {
	PyObject *listenerCapsule = NULL;
	PyObject *framesCapsule = NULL;
	if(PyArg_ParseTuple(args, "OO", &listenerCapsule,&framesCapsule)){
		SyncMultiFrameListener *listener = (SyncMultiFrameListener*) PyCapsule_GetPointer(listenerCapsule, "SyncMultiFrameListener");
		//std::cout << "release: " << (void*)framesCapsule << "::" << (void*)listenerCapsule << std::endl;
		SPFrameMap *spFrames = (SPFrameMap *) PyCapsule_GetPointer(framesCapsule,"FrameMap");
		spFrames->clear();
		if((NULL != listener)&&(NULL != spFrames)){
			FrameMap* frames = new FrameMap();
			listener->release(*frames);
			delete frames;
		}
	}
	Py_INCREF(Py_None);
	return Py_None;
}

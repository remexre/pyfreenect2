#include "Freenect2Device.hpp"

#include "Freenect2.hpp"

using libfreenect2::Freenect2Device;
using libfreenect2::FrameListener;

PyObject *py_Freenect2Device_new(PyObject *self, PyObject *args) {
	char *serialNumber = NULL;
	if(!PyArg_ParseTuple(args, "s", &serialNumber))
		return NULL;

	// TODO Pipeline support
	Freenect2Device *device = getGlobalFreenect2().openDevice(serialNumber);
	return PyCapsule_New(device, "Freenect2Device", py_Freenect2Device_destroy);
}
void py_Freenect2Device_destroy(PyObject *capsule) {
	((Freenect2Device*) PyCapsule_GetPointer(capsule, "Freenect2Device"))->close();
}

PyObject *py_Freenect2Device_start(PyObject *self, PyObject *args) {
	PyObject *capsule = NULL;
	if(!PyArg_ParseTuple(args, "O", &capsule))
		return NULL;
	((Freenect2Device*) PyCapsule_GetPointer(capsule, "Freenect2Device"))->start();
	Py_INCREF(Py_None);
	return Py_None;
}
PyObject *py_Freenect2Device_stop(PyObject *self, PyObject *args) {
	PyObject *capsule = NULL;
	if(!PyArg_ParseTuple(args, "O", &capsule))
		return NULL;
	((Freenect2Device*) PyCapsule_GetPointer(capsule, "Freenect2Device"))->stop();
	Py_INCREF(Py_None);
	return Py_None;
}

PyObject *py_Freenect2Device_setColorFrameListener(PyObject *self, PyObject *args) {
	PyObject *deviceCapsule = NULL;
	PyObject *listenerCapsule = NULL;
	if(!PyArg_ParseTuple(args, "OO", &deviceCapsule, &listenerCapsule))
		return NULL;
	Freenect2Device *device = (Freenect2Device*) PyCapsule_GetPointer(deviceCapsule, "Freenect2Device");
	Py_INCREF(listenerCapsule);
	FrameListener *listener = (FrameListener*) PyCapsule_GetPointer(listenerCapsule, "FrameListener");
	device->setColorFrameListener(listener);
	Py_INCREF(Py_None);
	return Py_None;
}
PyObject *py_Freenect2Device_setIrAndDepthFrameListener(PyObject *self, PyObject *args) {
	PyObject *deviceCapsule = NULL;
	PyObject *listenerCapsule = NULL;
	if(!PyArg_ParseTuple(args, "OO", &deviceCapsule, &listenerCapsule))
		return NULL;
	Freenect2Device *device = (Freenect2Device*) PyCapsule_GetPointer(deviceCapsule, "Freenect2Device");
	Py_INCREF(listenerCapsule);
	FrameListener *listener = (FrameListener*) PyCapsule_GetPointer(listenerCapsule, "FrameListener");
	device->setIrAndDepthFrameListener(listener);
	Py_INCREF(Py_None);
	return Py_None;
}

// PyObject *py_Freenect2Device_getSerialNumber(PyObject *self, PyObject *args);
// PyObject *py_Freenect2Device_getFirmwareVersion(PyObject *self, PyObject *args);
// PyObject *py_Freenect2Device_getIRCameraParams(PyObject *self, PyObject *args);
// PyObject *py_Freenect2Device_getColorCameraParams(PyObject *self, PyObject *args);

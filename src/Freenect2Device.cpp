#include "Freenect2Device.hpp"

#include "Freenect2.hpp"

using libfreenect2::Freenect2Device;

PyObject *py_Freenect2Device_new(PyObject *self, PyObject *args) {
	char *serialNumber = NULL;
	if(!PyArg_ParseTuple(args, "s", &serialNumber))
		return NULL;

	// TODO Pipeline support
	Freenect2Device *device = getGlobalFreenect2().openDevice(serialNumber);
	return PyCapsule_New(device, "Freenect2Device", py_Freenect2Device_destroy);
}
void py_Freenect2Device_destroy(PyObject *object) {
	((Freenect2Device*) PyCapsule_GetPointer(object, "Freenect2Device"))->close();
}

// PyObject *py_Freenect2Device_start(PyObject *self, PyObject *args);
// PyObject *py_Freenect2Device_stop(PyObject *self, PyObject *args);

// PyObject *py_Freenect2Device_setColorFrameListener(PyObject *self, PyObject *args);
// PyObject *py_Freenect2Device_setIrAndDepthFrameListener(PyObject *self, PyObject *args);

// PyObject *py_Freenect2Device_getSerialNumber(PyObject *self, PyObject *args);
// PyObject *py_Freenect2Device_getFirmwareVersion(PyObject *self, PyObject *args);
// PyObject *py_Freenect2Device_getIRCameraParams(PyObject *self, PyObject *args);
// PyObject *py_Freenect2Device_getColorCameraParams(PyObject *self, PyObject *args);

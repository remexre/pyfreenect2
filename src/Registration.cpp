#include "Registration.hpp"

#include <string>
#include <libfreenect2/libfreenect2.hpp>
#include <libfreenect2/registration.h>

using libfreenect2::Freenect2Device;
using libfreenect2::Registration;

PyObject *py_Registration_new(PyObject *self, PyObject *args) {
	PyObject *irCameraParamsCapsule = NULL;
	PyObject *colorCameraParamsCapsule = NULL;
	if(!PyArg_ParseTuple(args, "OO", &irCameraParamsCapsule, &colorCameraParamsCapsule))
		return NULL;
	Freenect2Device::IrCameraParams *irCameraParams = (Freenect2Device::IrCameraParams*) PyCapsule_GetPointer(irCameraParamsCapsule, "IRCameraParams");
	Freenect2Device::ColorCameraParams *colorCameraParams = (Freenect2Device::ColorCameraParams*) PyCapsule_GetPointer(colorCameraParamsCapsule, "ColorCameraParams");
	Registration *registration = new Registration(*irCameraParams, *colorCameraParams);
	return PyCapsule_New(registration, "Registration", py_Registration_destroy);
}
void py_Registration_destroy(PyObject *registrationCapsule) {
	delete (Registration*) PyCapsule_GetPointer(registrationCapsule, "Registration");
}

PyObject *py_Registration_apply(PyObject *self, PyObject *args) {
	PyObject *registrationCapsule = NULL;
	if(!PyArg_ParseTuple(args, "O", &registrationCapsule))
		return NULL;
	// TODO
	Py_INCREF(Py_NotImplemented);
	return Py_NotImplemented;
}

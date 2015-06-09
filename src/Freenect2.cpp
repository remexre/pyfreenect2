#include "Freenect2.hpp"

#include <string>

#include <libfreenect2/libfreenect2.hpp>

libfreenect2::Freenect2 freenect2;

PyObject *py_numberOfDevices(PyObject *self, PyObject *args) {
	if(!PyArg_ParseTuple(args, ""))
		return NULL;
	return PyInt_FromLong(freenect2.enumerateDevices());
}

PyObject *py_getDefaultDeviceSerialNumber(PyObject *self, PyObject *args) {
	if(!PyArg_ParseTuple(args, ""))
		return NULL;
	std::string serialNumber = freenect2.getDefaultDeviceSerialNumber();
	return PyString_FromString(serialNumber.c_str());
}

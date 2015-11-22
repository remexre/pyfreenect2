#pragma once

#include <Python.h>
#include <string>
#include <libfreenect2/libfreenect2.hpp>
#include <libfreenect2/logger.h>
#include <libfreenect2/frame_listener_impl.h>
#include <libfreenect2/registration.h>
#include <numpy/arrayobject.h>

////////////////////////////////////////////////////////////////////////////////
//                              GLOBAL FUNCTIONS                              //
////////////////////////////////////////////////////////////////////////////////

libfreenect2::Freenect2& getGlobalFreenect2();

PyObject *py_numberOfDevices(PyObject *self, PyObject *args);
PyObject *py_getDefaultDeviceSerialNumber(PyObject *self, PyObject *args);

////////////////////////////////////////////////////////////////////////////////
//                               Freenect2Device                              //
////////////////////////////////////////////////////////////////////////////////

PyObject *py_Freenect2Device_new(PyObject *self, PyObject *args);
void py_Freenect2Device_destroy(PyObject *deviceCapsule);

PyObject *py_Freenect2Device_start(PyObject *self, PyObject *args);
PyObject *py_Freenect2Device_stop(PyObject *self, PyObject *args);

PyObject *py_Freenect2Device_setColorFrameListener(PyObject *self, PyObject *args);
PyObject *py_Freenect2Device_setIrAndDepthFrameListener(PyObject *self, PyObject *args);

PyObject *py_Freenect2Device_getSerialNumber(PyObject *self, PyObject *args);
PyObject *py_Freenect2Device_getFirmwareVersion(PyObject *self, PyObject *args);
PyObject *py_Freenect2Device_getColorCameraParams(PyObject *self, PyObject *args);
PyObject *py_Freenect2Device_getIRCameraParams(PyObject *self, PyObject *args);

void py_Freenect2Device_ColorCameraParams_destroy(PyObject *colorCameraParamsCapsule);
void py_Freenect2Device_IRCameraParams_destroy(PyObject *irCameraParamsCapsule);

////////////////////////////////////////////////////////////////////////////////
//                           SyncMultiFrameListener                           //
////////////////////////////////////////////////////////////////////////////////

PyObject *py_SyncMultiFrameListener_new(PyObject *self, PyObject *args);
void py_SyncMultiFrameListener_destroy(PyObject *object);

PyObject *py_SyncMultiFrameListener_waitForNewFrame(PyObject *self, PyObject *args);

////////////////////////////////////////////////////////////////////////////////
//                                  FrameMap                                  //
////////////////////////////////////////////////////////////////////////////////

void py_FrameMap_destroy(PyObject *object);

PyObject *py_FrameMap_getFrame(PyObject *self, PyObject *args);

////////////////////////////////////////////////////////////////////////////////
//                                   Frame                                    //
////////////////////////////////////////////////////////////////////////////////

void py_Frame_destroy(PyObject *object);

PyObject *py_Frame_getHeight(PyObject *self, PyObject *args);
PyObject *py_Frame_getWidth(PyObject *self, PyObject *args);
PyObject *py_Frame_getData(PyObject *self, PyObject *args);
PyObject *py_Frame_getDepthData(PyObject *self, PyObject *args);

////////////////////////////////////////////////////////////////////////////////
//                                Registration                                //
////////////////////////////////////////////////////////////////////////////////

PyObject *py_Registration_new(PyObject *self, PyObject *args);
void py_Registration_destroy(PyObject *object);

PyObject *py_Registration_apply(PyObject *self, PyObject *args);

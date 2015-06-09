import _pyfreenect2

class PyFreenect2Error(Exception):
	def __init__(self, message):
		super(PyFreenect2Error, self).__init__(message)
class DeveloperIsALazyBastardError(Exception):
	def __init__(self, message):
		super(DeveloperIsALazyBastardError, self).__init__(message)

################################################################################
#                               GLOBAL FUNCTIONS                               #
################################################################################

def numberOfDevices():
	return _pyfreenect2.numberOfDevices()
def getDefaultDeviceSerialNumber():
	if numberOfDevices() == 0:
		raise PyFreenect2Error("Could not find a Kinect v2")
	else:
		return _pyfreenect2.getDefaultDeviceSerialNumber()

################################################################################
#                                Freenect2Device                               #
################################################################################

class Freenect2Device:
	def __init__(self, serialNumber, pipeline=None):
		if pipeline is not None:
			raise DeveloperIsALazyBastardError("pyfreenect2.PacketPipeline is not yet implemented")
		self._capsule = _pyfreenect2.Freenect2Device_new(serialNumber)
	def start(self):
		_pyfreenect2.Freenect2Device_start(self._capsule)
	def stop(self):
		_pyfreenect2.Freenect2Device_stop(self._capsule)
	def setColorFrameListener(self, listener):
		if not type(listener) is FrameListener:
			raise TypeError("Argument to Freenect2Device.setColorFrameListener must be of type Freenect2Device.FrameListener")
		else:
			_pyfreenect2.Freenect2Device_setColorFrameListener(self._capsule, listener._capsule)
	def setIrAndDepthFrameListener(self, listener):
		if not type(listener) is FrameListener:
			raise TypeError("Argument to Freenect2Device.setIrAndDepthFrameListener must be of type Freenect2Device.FrameListener")
		else:
			_pyfreenect2.Freenect2Device_setIrAndDepthFrameListener(self._capsule, listener._capsule)
	@property
	def serial_number(self):
		return _pyfreenect2.Freenect2Device_getSerialNumber(self._capsule)
	@property
	def firmware_version(self):
		return _pyfreenect2.Freenect2Device_getFirmwareVersion(self._capsule)
	@property
	def color_camera_params(self):
		return _pyfreenect2.Freenect2Device_getColorCameraParams(self._capsule)
	@property
	def ir_camera_params(self):
		return _pyfreenect2.Freenect2Device_getIRCameraParams(self._capsule)

################################################################################
#                            SyncMultiFrameListener                            #
################################################################################

class SyncMultiFrameListener:
	def __init__(self, *args):
		types = 0
		for arg in args:
			types |= int(arg)
		self._capsule = _pyfreenect2.SyncMultiFrameListener_new(types)
	def waitForNewFrame(self):
		return FrameMap(_pyfreenect2.SyncMultiFrameListener_waitForNewFrame(self._capsule))

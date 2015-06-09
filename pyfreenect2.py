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
		self._blob = _pyfreenect2.Freenect2Device_new(serialNumber)
	def start(self):
		_pyfreenect2.Freenect2Device_start(self._blob)
	def stop(self):
		_pyfreenect2.Freenect2Device_stop(self._blob)
	def setColorFrameListener(self, listener):
		if not type(listener) is FrameListener:
			raise TypeError("Argument to Freenect2Device.setColorFrameListener must be of type Freenect2Device.FrameListener")
		else:
			_pyfreenect2.Freenect2Device_setColorFrameListener(self._blob, listener._blob)
	def setIrAndDepthFrameListener(self, listener):
		if not type(listener) is FrameListener:
			raise TypeError("Argument to Freenect2Device.setIrAndDepthFrameListener must be of type Freenect2Device.FrameListener")
		else:
			_pyfreenect2.Freenect2Device_setIrAndDepthFrameListener(self._blob, listener._blob)

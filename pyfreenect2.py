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
		self._state = _pyfreenect2.new_freenect2Device(serialNumber)
		if pipeline is not None:
			raise DeveloperIsALazyBastardError("pyfreenect2.PacketPipeline is not yet implemented")

from setuptools import setup, Extension

libfreenect2_module = Extension("_pyfreenect2",
	libraries=["freenect2"],
	sources=["pyfreenect2.cpp",
		"src/Frame.cpp",
		"src/FrameMap.cpp",
		"src/Freenect2.cpp",
		"src/Freenect2Device.cpp",
		"src/Registration.cpp",
		"src/SyncMultiFrameListener.cpp"])

setup(name="pyfreenect2",
	ext_modules=[libfreenect2_module],
	py_modules=["pyfreenect2"])

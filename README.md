pyfreenect2
===========

Python bindings to [libfreenect2](https://github.com/OpenKinect/libfreenect2).

Requirements
---------

- Python2 (python3 support : https://github.com/LovelyHorse/py3freenect2)
- Numpy
- Scipy (as appropriated by python version) : 
- Python Imaging Library (used for scipy.misc.im* functions) : http://www.pythonware.com/products/pil/
- OpenCV

Installation
---------

To install, run `sudo python setup.py install`.

Usage
---------

For usage, see `test.py`.


TODO List
---------

__ * Make `test.py` actually display the frames __
 * Implement Registration.apply (in py_Registration_apply)
 * Make the pipeline argument of Freenect2Device's constructor actually do something
 * Test everything

You can probably find more TODOs in [Issues](https://github.com/tikiking1/pyfreenect2/issues) or by `grep -R TODO .`.

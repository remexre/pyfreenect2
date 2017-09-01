#ifndef _SMARTFRAM_H_ 
#define _SMARTFRAM_H_ 

#include "../pyfreenect2.hpp"
#include "SmartPtr.hpp"

using libfreenect2::Frame;
using libfreenect2::FrameMap;

typedef SmartPtr<Frame> SPFrame;
typedef std::map<Frame::Type, SPFrame> SPFrameMap;

SPFrameMap* getSPFrameMapFromFrameMap(FrameMap* frames);

#endif

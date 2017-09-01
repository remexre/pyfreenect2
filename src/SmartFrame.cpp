#include "SmartFrame.h"

SPFrameMap* getSPFrameMapFromFrameMap(FrameMap* frames){
	SPFrameMap * spFrames = new SPFrameMap;
	for(FrameMap::iterator it = frames->begin() ; it!= frames->end() ; ++it){
		spFrames->insert(std::make_pair(it->first,SPFrame(it->second)));
	}
	return spFrames;
}

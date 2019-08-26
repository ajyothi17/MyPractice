#ifndef __STORYTEL_CODEC__
#define __STORYTEL_CODEC__

#include <IAudioCodec.h>

using namespace AudioCodec;

class StorytelCodec : public IAudioCodec
{
	public:
		virtual void createAudio();
		virtual void attachAudio();
};

#endif

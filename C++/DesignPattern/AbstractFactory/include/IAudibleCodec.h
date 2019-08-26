#ifndef __AUDIBLE_CODEC__
#define __AUDIBLE_CODEC__

#include <IAudioCodec.h>

using namespace AudioCodec;

class AudibleCodec : public IAudioCodec
{
	public:
		virtual void createAudio();
		virtual void attachAudio();
};
#endif

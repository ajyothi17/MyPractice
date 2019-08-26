#ifndef __AUDIO_CODEC__
#define __AUDIO_CODEC__
namespace AudioCodec
{
	class IAudioCodec
	{
		public:
			virtual void createAudio() = 0;
			virtual void attachAudio() = 0;
	};
}
#endif

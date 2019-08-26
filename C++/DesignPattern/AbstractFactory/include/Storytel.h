#ifndef __STORYTEL__
#define __STORYTEL__

#include <IListenStorytel.h>
#include <IStorytelCodec.h>
#include <BookApp.h>

using namespace BookAppp;

namespace storytel
{
	class Storytel : public BookApp
	{
		public:
			IListenBook* listenAudioBook()
			{
				return new ListenStorytel();
			}

			IAudioCodec* createAudio()
			{
				return new StorytelCodec();
			}
	};
}

#endif

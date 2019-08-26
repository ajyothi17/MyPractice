#ifndef __AUDIBLE__
#define __AUDIBLE__

#include <IListenAudible.h>
#include <IAudibleCodec.h>
#include <BookApp.h>

using namespace BookAppp;

namespace audible
{
	class Audible : public BookApp
	{
		public:
			IListenBook* listenAudioBook()
			{
				return new ListenAudible();
			}

			IAudioCodec* createAudio()
			{
				return new AudibleCodec();
			}
	};
}

#endif

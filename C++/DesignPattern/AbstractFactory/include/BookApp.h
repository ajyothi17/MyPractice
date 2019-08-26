#ifndef __BOOK_APP__
#define __BOOK_APP__

#include <IListenBook.h>
#include <IAudioCodec.h>

using namespace ListenBook;
using namespace AudioCodec;

namespace BookAppp
{
	class BookApp
	{
		public:
			virtual IListenBook* listenAudioBook() = 0;
			virtual IAudioCodec* createAudio() = 0;
	};
}
#endif

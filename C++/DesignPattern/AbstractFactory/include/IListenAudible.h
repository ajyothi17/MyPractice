#ifndef __LISTEN_AUDIBLE__
#define __LISTEN_AUDIBLE__

#include <IListenBook.h>

using namespace ListenBook;

class ListenAudible : public IListenBook
{
	public:
		virtual void startListening();
		virtual void stopListening();
};

#endif

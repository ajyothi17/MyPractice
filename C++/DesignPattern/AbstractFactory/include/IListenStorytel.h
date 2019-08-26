#ifndef __LISTEN_STORYTEL__
#define __LISTEN_STORYTEL__

#include <IListenBook.h>

using namespace ListenBook;

class ListenStorytel : public IListenBook
{
	public:
		virtual void startListening();
		virtual void stopListening();
};
#endif

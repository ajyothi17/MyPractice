#ifndef __LISTEN_BOOK__
#define __LISTEN_BOOK__
namespace ListenBook
{
	class IListenBook
	{
		public:
			virtual void startListening() = 0;
			virtual void stopListening() = 0;
	};
}
#endif

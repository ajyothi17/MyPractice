#include <Application.h>
#include <Audible.h>
#include <Storytel.h>

using namespace audible;
using namespace storytel;
using namespace application;

int main(void)
{
	BookApp *obj = Application::createBookApp(App::Audible);
//	BookApp *obj = Application::createBookApp(App::Storytel);

	IListenBook *listen = obj->listenAudioBook();	
	IAudioCodec *audio = obj->createAudio();

	listen->startListening();
	audio->createAudio();
	audio->attachAudio();
	listen->stopListening();

	return 0;
}

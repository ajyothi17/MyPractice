#ifndef __APPLICATION__
#define __APPLICATION__

#include <BookApp.h>
#include <Audible.h>
#include <Storytel.h>

using namespace BookAppp;
using namespace audible;
using namespace storytel;

namespace application
{
	enum class App
	{
		Audible, Storytel
	};

	class Application
	{
		public:
			static BookApp* createBookApp(App app)
			{
				switch(app)
			    {
        			case App::Audible:
            			return new Audible();

        			case App::Storytel:
            			return new Storytel();

        			default:
            			return nullptr;
    			}

			}
	};
}

#endif

#include "header.h"

int main(int argc, char *argv[])
{
	if(argc != 3){
		HANDLE_ERROR("invalid args: expecting ../obj/app <file1> <file2>");
	}

	replaceSpace(*++argv, *++argv);

	return EXIT_SUCCESS;
}

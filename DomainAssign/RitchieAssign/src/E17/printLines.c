#include "header.h"

int getLine(char buf[], int lim)
{
	int index;

	for(index = ZERO; (buf[index] != LINE); index++);

	return index; 
}

int main(int argc, char *argv[])
{
	int len = ZERO;
	char *line = NULL;
	int fSize;
	FILE *fp = NULL;

	if(argc != 2){
		HANDLE_ERROR("invalid arguments, expecting: ../obk/app <inputfile>");
	}

	if(NULL == (fp = fopen(*++argv, "r"))){
		HANDLE_ERROR("couldn't open file");
	}
	
	if(NULL == (line = malloc(sizeof(char *) * MAX))){
		HANDLE_ERROR("no memory available");
	}

	while(fgets(line, MAX, fp)){

		if((len = getLine(line, MAXLINE))){
			if(len > MAXLINE){
				printf("%s", line);
			}
		}
	}

	free(line);
	line = NULL;
}

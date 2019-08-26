#include "header.h"


int getLine(char buf[], int lim)
{
	int index;

	for(index = ZERO; (buf[index] != LINE); index++);
	//	buf[index] = ch;

//	buf[index] = NUL;
	return index; 
}

void copy(char dest[], char src[])
{
	int index = ZERO;

	while((dest[index] = src[index]) != NUL){
		index++;
	}
}

void printLines(void)
{
	int len = ZERO;
	char *line = NULL;
	int fSize;
	FILE *fp = NULL;

	if(NULL == (fp = fopen("test.txt", "r"))){
		HANDLE_ERROR("couldn't open file");
	}
	
	if(-1 == (fSize = ftell(fp))){
		HANDLE_ERROR("ftell() failed");
	}
	
	rewind(fp);

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

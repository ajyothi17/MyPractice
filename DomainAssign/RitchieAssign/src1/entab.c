#include "header.h"

void entab(void)
{
	char *input = NULL;
	int index;
	int noOfSpace;

	if(NULL == (input = malloc(sizeof(char*) * MAX))){
		HANDLE_ERROR("no memory available");
	}

	if(NULL == fgets(input, MAX, stdin)){
		HANDLE_ERROR("couldn't read input");
	}
	
	index = ZERO;

	while(*(input + index) != LINE){
		
		noOfSpace = ZERO;
		while((*(input + index) == SPACE) && (noOfSpace != TABSPACE)){
			noOfSpace++;
			index++;
		}
		
		if(noOfSpace == TABSPACE){
			printf("\t");

		}else if(noOfSpace < TABSPACE){
			while(--noOfSpace)
				printf("%c", *(input + index - noOfSpace));
		}else{

			printf("%c", *(input + index));
			index++;	
		}
	}

//	printf("%s", input);

	free(input);
	input = NULL;
}

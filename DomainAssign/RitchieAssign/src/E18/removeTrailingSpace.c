#include "header.h"

int main(void)
{
	char *input = NULL;
	int index;
	int flag = 0;

	if(NULL == (input = malloc(sizeof(char*) * MAX))){
		HANDLE_ERROR("no memory available");
	}
	
	printf("enter string:");
	if(NULL == fgets(input, MAX, stdin)){
		HANDLE_ERROR("couldn't read input");
	}
	
	index = 0;

	while(*(input + index) != LINE){
		
		while((*(input + index) == TAB) || (*(input + index) == SPACE)){
			index++;
		}

		flag = 1;
		
		if(flag)
			break;

		index++;	
	}

	printf("%s", (input + index));

	free(input);
	input = NULL;
}

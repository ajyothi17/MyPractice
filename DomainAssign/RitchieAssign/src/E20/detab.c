#include "header.h"

int main(void)
{
	char *input = NULL;
	int index;
	int noOfTabs;
	int flag = 0;

	if(NULL == (input = malloc(sizeof(char*) * MAX))){
		HANDLE_ERROR("no memory available");
	}

	printf("enter string:");
	if(NULL == fgets(input, MAX, stdin)){
		HANDLE_ERROR("couldn't read input");
	}
	
	printf("enter the no. of tabs to be replaced:");
	noOfTabs = readInput();

	index = 0;

	while((*(input + index) != LINE) && noOfTabs){

		if(*(input + index) == TAB){
			*(input + index) = SPACE;
			noOfTabs--;
		}
		
		index++;	
	}

	printf("%s", input);

	free(input);
	input = NULL;

	return EXIT_SUCCESS;
}

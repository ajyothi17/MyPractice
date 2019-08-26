#include "header.h"

int readInput(void)
{
	char *input = NULL;

	if(NULL == (input = malloc(sizeof(char *) * MAX))){
		HANDLE_ERROR("no memory available");
	}

	if(NULL == fgets(input, MAX, stdin)){
		HANDLE_ERROR("couldn't read user input");
	}
	
	long long num = 0;

	while(*(input + num) != '\0')
		num++;

	*(input + num - 1) = '\0';

	if(INT_MAX < (num = myAtoi(input))){
		HANDLE_ERROR("invalid input");
	}
	
	free(input);
	input = NULL;

	return num;
}

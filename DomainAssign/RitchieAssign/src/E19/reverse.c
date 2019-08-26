//function to reverse a string

#include "header.h"

int main(void)
{
	int len;
	int index;
	char temp;
	char *input = NULL;
	
	if(NULL == (input = malloc(sizeof(char*) * MAX))){
		HANDLE_ERROR("no memory available");
	}

	printf("enter a string:");
	if(NULL == fgets(input, MAX, stdin)){
		HANDLE_ERROR("couldn't read input");
	}
	
	len = ZERO;
	while(*(input + len) != NUL){
		len++;
	}

	len--;
	*(input + len) = NUL;

	if(len == ONE){
		printf("%s\n", input);
		return;
	}

	for(index = ZERO; index < (len / TWO); index++){
		temp  = *(input + index);
        *(input + index) = *(input + len - ONE - index);
        *(input + len - ONE - index) = temp;
	}

	printf("%s\n", input);

	free(input);
	input = NULL;

	return EXIT_SUCCESS;
}

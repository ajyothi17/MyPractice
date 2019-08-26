#include <stdio.h>
#include <stdlib.h>
#define MAX 128

int pop3(int top3)
{
	if(top3 == -1){
		printf("invalid braces");
		exit(EXIT_FAILURE);
	}

	return --top3;
}

#include <stdio.h>
#include <stdlib.h>
#define MAX 128

int pop2(int top2)
{
	if(top2 == -1){
		printf("invalid braces");
		exit(EXIT_FAILURE);
	}

	return --top2;
}

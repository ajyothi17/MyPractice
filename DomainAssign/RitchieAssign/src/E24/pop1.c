#include <stdio.h>
#include <stdlib.h>
#define MAX 128

int pop1(int top1)
{
	if(top1 == -1){
		printf("invalid braces");
		exit(EXIT_FAILURE);
	}

	return --top1;
}

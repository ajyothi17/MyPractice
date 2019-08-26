#include <stdio.h>
#include <stdlib.h>
#define MAX 128

extern int arr[MAX];

int push1(int top1, int data)
{
	if(top1 == MAX){
		printf("stack full");
		exit(EXIT_FAILURE);
	}

	arr[++top1] = data;

	return top1;	
}

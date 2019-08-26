#include <stdio.h>
#include <stdlib.h>
#define MAX 128

extern int arr[MAX];

int push2(int top2, int data)
{
	if(top2 == MAX){
		printf("stack full");
		exit(EXIT_FAILURE);
	}

	arr[++top2] = data;

	return top2;	
}

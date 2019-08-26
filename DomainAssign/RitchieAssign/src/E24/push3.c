#include <stdio.h>
#include <stdlib.h>
#define MAX 128

extern int arr[MAX];

int push3(int top3, int data)
{
	if(top3 == MAX){
		printf("stack full");
		exit(EXIT_FAILURE);
	}

	arr[++top3] = data;

	return top3;	
}

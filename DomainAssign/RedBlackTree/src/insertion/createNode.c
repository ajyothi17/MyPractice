#include "header.h"

NODE* createNode(NODE *par, int data, int color)
{
	NODE *newNode = NULL;

	if(NULL == (newNode = (NODE*)malloc(sizeof(NODE)))){
		printf("no memory available");
		return NULL;
	}

	newNode -> data = data;
	newNode -> color = color;
	newNode -> left = nullNode;
	newNode -> right = nullNode;
	newNode -> parent = par;

	return newNode;
}

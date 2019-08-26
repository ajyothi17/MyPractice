#include "header.h"

NODE* insertNode(int data)
{
	NODE *prev = NULL;
	NODE *cur = NULL;
	
	if((root == nullNode) || (root == NULL)){
		if(NULL == (root = createNode(nullNode, data, BLACK))){
			printf("node creation failed\n");
			return NULL;
		}	

		if(checkViolation(root)){
			printf("couldn't balance RBTree");
			return NULL;
		}

		return root; 
	}

	prev = nullNode;
	cur = root;

	while(cur != nullNode){
		prev = cur;
		
		if(data < (cur -> data))
			cur = cur -> left;
		
		else
			cur = cur -> right;
	}

	cur = createNode(prev, data, RED);

	if((cur -> data) < (prev -> data))
		prev -> left = cur;

	else
		prev -> right = cur;
	
	if(checkViolation(cur)){
		printf("couldn't balance RBTree");
		return NULL;
	}

	return root;
}

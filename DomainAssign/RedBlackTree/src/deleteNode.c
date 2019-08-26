#include "header.h"

NODE* deleteNode(int data)
{
	NODE *temp = NULL;
	int flag = 0;

	temp = root;

	while(temp != nullNode){
		if(data == temp -> data){
			flag = 1;
			break;
		}

		if(data < (temp -> data))
			temp = temp -> left;				

		else
			temp = temp -> right;
	}

	if(flag == 0){
		return NULL;
	}

	else if((temp -> left == nullNode) && (temp -> right == nullNode)){
//		root = case3(temp -> parent, temp);
	}

	else if(temp -> left == nullNode){
//		root = case2(temp -> parent, temp);
	}

	else if(temp -> right == nullNode){
//		root = case2(temp -> parent, temp);
	}
	
	else{
//		root = case1(temp -> parent, temp);
	}

	return root;
}

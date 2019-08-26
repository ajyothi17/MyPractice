#include "header.h"

NODE *case1(NODE *par, NODE *delNode)
{
	if(par == nullNode){
		root = nullNode;

	}

	if(delNode -> color == RED){
		if((par -> left) == delNode){
			par -> left = nullNode;

		}else{
			par -> right = nullNode;

		}
	}

	else{
		
	}

	free(delNode);
	return root;
}

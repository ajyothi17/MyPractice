#include "header.h"

NODE* checkViolation(NODE *newNode, NODE *par)
{
	int flag = 0;

	if((par == NULL) && (newNode -> color == 0)){
		return newNode;
	}

	else{
		if(par -> color == 0)
			return par;

		else{
			if((par -> parent -> left == par) && (par -> parent -> right != NULL) && (par -> parent -> right -> color == 1))
					flag = 1;
				
			else if((par -> parent -> right == par) && (par -> parent -> left != NULL) && (par -> parent -> left -> color == 1))
					flag = 1;

			if(flag){
				if(par -> parent -> parent == NULL){
					par -> parent -> right -> color = 1 ^ (par -> parent -> right -> color);
					par -> parent -> left -> color = 1 ^ (par -> parent -> left -> color);
				
				}else{
					par -> parent -> right -> color = 1 ^ (par -> parent -> right -> color);
                    par -> parent -> left -> color = 1 ^ (par -> parent -> left -> color);

					checkViolation(par, par -> parent);
				}
	
			}else{
				printf("%d\n", par -> parent -> data);
				if((par -> left == newNode) && (par -> parent -> left == par)){
					par -> parent -> left = rotateRight(par, par -> parent);
				printf("%d\n", par -> parent -> data);
				
				}else if((par -> left == newNode) && (par -> parent -> right == par)){
					par -> left = rotateRight(newNode, par);
					par -> parent -> right = rotateLeft(par, par -> parent);
				
				}else if((par -> right == newNode) && (par -> parent -> left == par)){
					par -> right = rotateLeft(newNode, par);
					par -> parent -> left = rotateRight(par, par -> parent);
				
				}else if((par -> right == newNode) && (par -> parent -> right == par)){
					par -> parent -> right = rotateLeft(par, par -> parent);
				}

			//	return par;
			}
		}
	}

	return par;
}

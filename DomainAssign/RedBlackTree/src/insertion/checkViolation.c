#include "header.h"

void swapColor(NODE *par, NODE *ppar)
{
	ppar -> color = (par -> color) ^ (ppar -> color);
	par -> color = (par -> color) ^ (ppar -> color);
	ppar -> color = (par -> color) ^ (ppar -> color);
}

int checkViolation(NODE *newNode)
{
	int flag = 0;
	NODE *par = NULL;
	NODE *ppar = NULL;

	if((newNode -> parent == nullNode) && (newNode -> color == BLACK)){
		return 0;
	}

	else{
		if(newNode -> parent -> color == BLACK)
			return 0;

		else{
			par = newNode -> parent;
			ppar = par -> parent;

			if((ppar -> left == par) && (ppar -> right != NULL) && (ppar -> right -> color == RED))
					flag = 1;
				
			else if((ppar -> right == par) && (ppar -> left != NULL) && (ppar -> left -> color == RED))
					flag = 1;

			if(flag){
				if(ppar -> parent == nullNode){
					ppar -> right -> color = 1 ^ (ppar -> right -> color);
					ppar -> left -> color = 1 ^ (ppar -> left -> color);
				
				}else{
					ppar -> right -> color = 1 ^ (ppar -> right -> color);
                   	ppar -> left -> color = 1 ^ (ppar -> left -> color);
					ppar -> color = 1 ^ (ppar -> color);	

					if(checkViolation(ppar))
						return 1;
				}
	
			}else{
				if((par -> left == newNode) && (ppar -> left == par)){
					if(ppar -> parent == nullNode)
						root = rotateRight(par, ppar);

					else
						ppar -> parent -> left = rotateRight(par, ppar);
					
					swapColor(ppar, par);					
				
				}else if((par -> left == newNode) && (ppar -> right == par)){
					ppar -> right = rotateRight(newNode, par);
					par = ppar -> right;
					ppar -> parent -> left = rotateLeft(par, ppar);
				
					swapColor(ppar, par);					
				
				}else if((par -> right == newNode) && (ppar -> left == par)){
					ppar -> left = rotateLeft(newNode, par);
					par = ppar -> left;
					ppar -> parent -> right = rotateRight(par, ppar);
					
					swapColor(ppar, par);					
				
				}else if((par -> right == newNode) && (ppar -> right == par)){
					if(ppar -> parent == nullNode)
						root = rotateLeft(par, ppar);

					else
						ppar -> parent -> right = rotateLeft(par, ppar);
					
					swapColor(ppar, par);					
				}
			}
		}
	}

	return 0;
}

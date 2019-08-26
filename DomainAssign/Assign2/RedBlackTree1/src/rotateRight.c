#include "header.h"

NODE* rotateRight(NODE *par, NODE *ppar)
{
//	if(ppar -> parent != NULL)
//		ppar -> parent -> left = par;
	
	par -> parent = ppar -> parent;	
	ppar -> left = par -> right;
	
	if(par -> right != NULL)
		par -> right -> parent = ppar;

	ppar -> parent = par;
	par -> right = ppar;

	return par;
}

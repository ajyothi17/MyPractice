#include "header.h"

NODE* rotateLeft(NODE *par, NODE *ppar)
{
	if(par -> parent != NULL)
		ppar -> parent -> right = par;

	par -> parent = ppar -> parent;
	ppar -> right = par -> left;

	if(par -> left != NULL)
		par -> left -> parent = ppar;

	ppar -> parent = par;
	par -> left = ppar;

	return 0;
}

#include "header.h"
#if 0
NODE* checkViolation1(NODE *root)
{
	if(root == NULL)
		return root;

	root = checkViolation(root, root -> parent);
	checkViolation1(root -> left);
	checkViolation1(root -> right);

	return root;
}
#endif
NODE* insert(NODE *root, const int data)
{
	if(NULL == (root = insertNode(root, root, data))){
		printf("node insertion failed\n");
		return NULL;
	}

//	root = checkViolation1(root);

	return root;
}

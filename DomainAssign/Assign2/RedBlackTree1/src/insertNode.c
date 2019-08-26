#include "header.h"
#if 0
NODE *insertNode(NODE *root, NODE *par, int data)
{
	if((root == NULL) && (par == NULL)){
		if(NULL == (root = createNode(par, data, 0))){
			printf("node creation error\n");
			return NULL;
		}
		
	//	checkViolation(root, par);
		return root;

	}else if((root == NULL) && (par != NULL)){
		if(NULL == (root = createNode(par, data, 1))){
			printf("node creation error\n");
			return NULL;
		}		

	//	checkViolation(root, par);
		return root;
	}

	if(data < (root -> data)){
			root -> left = insertNode(root -> left, root, data);

/*		if((root -> parent != NULL) && (root -> parent -> parent == NULL))
			root -> parent -> left = checkViolation(root -> left, root);

		if((root -> parent != NULL) && (root -> parent -> parent != NULL)){	
		printf("root%d\n", root -> parent -> left -> data);	
			root -> parent -> parent -> left = checkViolation(root -> left, root);
		printf("root%d\n", root -> parent -> left -> data);	
		return NULL;
	}*/
	}
	else{
		root -> right = insertNode(root -> right, root, data);
		
	/*	if(root -> parent != NULL)
			root -> parent -> right = checkViolation(root -> right, root);*/
	}


	return root;
}
#endif

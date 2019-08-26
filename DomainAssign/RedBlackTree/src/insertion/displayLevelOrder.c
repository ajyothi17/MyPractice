#include "header.h"

int heightOfTree(NODE* root)
{
	if(root == NULL){
		return 0;
	}	

	int lheight = heightOfTree(root -> left);
	int rheight = heightOfTree(root -> right);

	if(lheight > rheight)
		return lheight + 1;

	return rheight + 1;
}

void levelOrder(NODE* root, int level)
{
	if(root == NULL || (level < 1))
		return;

	if(level == 1)
		printf("%d(%d)\n", root -> data, root -> color);

	levelOrder(root -> left, level - 1);
	levelOrder(root -> right, level - 1);
}

void displayLevelOrder(NODE* root)
{
	int height = heightOfTree(root);
	int index;

	for(index = 1; index <= height; index++)
		levelOrder(root, index);

	return;
}

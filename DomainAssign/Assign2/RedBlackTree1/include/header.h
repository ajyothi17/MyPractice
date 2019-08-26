#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 256
#define ONE 1
#define TWO 2
#define THREE 3
#define FOUR 4
#define HANDLE_ERROR(msg) \
	do{ perror(msg); exit(EXIT_FAILURE);}while(0)

typedef struct node{
	int data;
	int color; //0 -> black, 1 -> red
	struct node *right;
	struct node *left;
	struct node *parent;
}NODE;

NODE *createNode(NODE *par, int data, int color);
NODE *insert(NODE *root, const int data);
int readInput(void);
int heightOfTree(NODE *root);
void levelOrder(NODE *root, int level);
void displayLevelOrder(NODE *root);
NODE *insertNode(NODE *root, NODE *par, int data);
long long myAtoi(char *input);
NODE* checkViolation(NODE *newNode, NODE *par);
NODE* rotateRight(NODE*, NODE*);
NODE* rotateLeft(NODE*, NODE*);

/**
 *this header file consist of the following
 *includes headers 
 *macros
 *structure for RBtree
 *function prototypes
*/

#ifndef __HEADER__
	#define __HEADER__  

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

	///structure for RBTree
	typedef struct node{
		enum {BLACK, RED}color;
		int data;
		struct node *left;
		struct node *right;
		struct node *parent;
	}NODE;

	NODE *root;	///root node of RBTree
	NODE *nullNode; ///null node of RBTree

	int readInput(void); ///function to read input
	long long myAtoi(char *input); ///function to convert ascii to integer
	NODE* createNode(NODE *par, int data, int color); ///func to create node
	NODE* insertNode(int);///func to insert data
	NODE* rotateRight(NODE *par, NODE *ppar);
	NODE* rotateLeft(NODE *par, NODE *ppar);
	void swapColor(NODE *par, NODE *ppar);
	NODE *deleteNode(int data);
	int checkViolation(NODE *newNode);
	NODE *case1(NODE *, NODE *);
	NODE *case2(NODE *, NODE *);
	NODE *case3(NODE *, NODE *);
	void displayLevelOrder(NODE* root);
#endif

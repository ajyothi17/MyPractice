///main function to take user inputs

#include "header.h"

int main(void)
{
	int data; ///to read data
	int ch; ///to read user choice
	char status = 'y';
//	NODE *root = NULL;
//	NODE *temp = NULL;

	if(NULL == (nullNode = malloc(sizeof(NODE))))
	{
		printf("no memory available\n");
		return EXIT_FAILURE;
	}

	nullNode -> color = BLACK;
	nullNode -> left = NULL;
	nullNode -> right = NULL;
	nullNode -> parent = NULL;	
	root = nullNode;

	while(status != 'n')
	{
		printf("1. insert\n"
				"2. delete\n"
				"3. display\n"
				"4. exit\n"
				"enter your choice: ");

		ch = readInput();

		switch(ch){
			case ONE: ///to insert elements to tree
						printf("enter the data to be inserted: ");
						data = readInput();
					
						if(NULL == insertNode(data))
						{
							printf("insertion failed\n");
					
						}
						else
						{
							printf("insertion success\n");
						}

						break;
					
/*			case TWO: printf("enter the data to be deleted: ");
					  data = readInput();

					  if(NULL == deleteNode(data)){
						printf("element not found\n");

					  }else{
						printf("deletion success\n");

					  }

					  break;
*/
			case THREE: displayLevelOrder(root);
					//	my_display(root)
					break;

			case FOUR: 	status = 'n';
					break;

			default: printf("invalid choice\n");
		}
	}

	return EXIT_SUCCESS;
}

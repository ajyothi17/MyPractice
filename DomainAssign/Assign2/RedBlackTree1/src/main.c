///main function to take user inputs

#include "header.h"

int main(void)
{
	int data; ///to read data
	int ch; ///to read user choice
	char status = 'y';
	NODE *root = NULL;
	NODE *temp = NULL;

	while(status != 'n'){
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
					
						if(NULL == (temp = insert(root, data))){
							printf("insertion failed\n");
					
						}else{
							root = temp;
							printf("insertion success\n");
						}

						break;
					
			case TWO: break;

			case THREE: displayLevelOrder(root);
					break;

			case FOUR: 	status = 'n';
					break;

			default: printf("invalid choice\n");
		}
	}

	return EXIT_SUCCESS;
}

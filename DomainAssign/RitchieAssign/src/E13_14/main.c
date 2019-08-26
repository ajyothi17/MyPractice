#include "header.h"

int main(void)
{
	int ch;
	
	while(TRUE){
		printf("1. vertical histogram of words\n"
				"2. vertical histogram of frequency of characters\n"
				"3. exit\n"
				"enter your choice:");
		ch = readInput();

		switch(ch){
			case 1: verticalHistograms();
					break;

			case 2: verticalHistogramsFreq();
					break;

			case 3: exit(EXIT_SUCCESS);

			default: printf("invalid choice");
		}
	}
}

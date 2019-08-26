#include "header.h"

int main(void)
{
	int c;
	int noOfBlanks  = 0;
	int noOfTabs = 0;
	int noOfLines = 0;

	printf("enter input(press <Ctrl + D> to exit):");
	while((c = getc(stdin)) != EOF){
		if(c == '\n')
			noOfLines++;
	
		if(c == '\t')
			noOfTabs++;
		
		if(c == ' ')
			noOfBlanks++;	
	}

	printf("no of blanks:%d\n"
			"no of tabs:%d\n"
			"no of lines:%d\n", noOfBlanks, noOfTabs, noOfLines);

	return EXIT_SUCCESS;
}

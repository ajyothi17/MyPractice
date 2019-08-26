#include "header.h"

void replace(char *file1)
{
	FILE *fpIn = NULL;
	int curChar;

	if(NULL == (fpIn = fopen(file1, "r"))){
		HANDLE_ERROR("couldn't open file");
	}

	while((curChar = getc(fpIn)) != EOF){
		if(curChar == LINE)
			printf("\\n");

		else if(curChar == TAB)
			printf("\\t");

		else if(curChar == '\\')
			printf("\\\\");
		
		else	
			printf("%c",curChar);
	
	}

	printf("\n");

	if(fclose(fpIn)){
		HANDLE_ERROR("couldn't close file");
	}
}

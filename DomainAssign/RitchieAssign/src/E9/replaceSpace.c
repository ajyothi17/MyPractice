#include "header.h"

void replaceSpace(char *file1, char *file2)
{
	FILE *fpIn = NULL;
	FILE *fpOut = NULL;
	int curChar;
	int prevChar = EOF;

	if(NULL == (fpIn = fopen(file1, "r"))){
		HANDLE_ERROR("couldn't open file");
	}

	if(NULL == (fpOut = fopen(file2, "w"))){
		HANDLE_ERROR("couldn't open file");
	}

	while((curChar = getc(fpIn)) != EOF){
		if((curChar == TAB) && (prevChar != TAB))
			putc(SPACE, fpOut);

		else if((curChar == SPACE) && (prevChar != SPACE))
			putc(SPACE, fpOut);
	
		else if((curChar != SPACE) && (curChar != TAB))	
			putc(curChar, fpOut);
	
		prevChar = curChar;
	}

	if(fclose(fpIn)){
		HANDLE_ERROR("couldn't close file");
	}

	if(fclose(fpOut)){
		HANDLE_ERROR("couldn't close file");
	}
}

#include "header.h"

void getChar(void)
{
	int c;

	while(c = (getchar() != EOF)){
		printf("%d\n", c);
	}
	
	printf("%d\n", c);
}

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

	if((argc != 4) || ((*argv[1] < '0') && (*argv[1] > '9')) || ((*argv[2] < '0') && (*argv[2] > '9')))
	{
		printf("Invalid arguments, expecting ./a.out num1 num2 operator\n");
		return EXIT_FAILURE;
	}

	switch(*argv[3])	
	{
		case '&': printf("%d\n", atoi(argv[1]) & atoi(argv[2]));
				  break;

		case '|': printf("%d\n", atoi(argv[1]) | atoi(argv[2]));
				  break;

		case '^': printf("%d\n", atoi(argv[1]) ^ atoi(argv[2]));
				  break;

		default : printf("ivalid operator");
	}

	return EXIT_SUCCESS;
}

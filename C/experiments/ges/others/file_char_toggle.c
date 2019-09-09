#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *input_file = NULL;
	FILE *output_file = NULL;
	char ch;

	if(3 != argc)
	{
		printf("invalid arguments, expecting ./a.out <input_file> <output_file>\n");
		return EXIT_FAILURE;
	}

	input_file = fopen(argv[1], "r");	
	output_file = fopen(argv[2], "w");

	if((NULL == input_file) || (NULL == output_file))
	{
		printf("file doesn't exist\n");
		return EXIT_FAILURE;
	}

	ch = fgetc(input_file);

	while(EOF != ch)
	{
		if((ch != '\n' ) && (ch != '\t') && (ch != ' '))
			ch ^= 32;

		fprintf(output_file, "%c", ch);

		ch = fgetc(input_file);
	}

	fclose(input_file);
	fclose(output_file);

	return EXIT_SUCCESS;
}

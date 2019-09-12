#include <stdio.h>
#include <stdlib.h>

#define LITTLE_TO_BIG(num) ((num >> 24) & 0x000000ff) | ((num >> 8) & 0x0000ff00) | ((num << 8) & 0x00ff0000) | ((num << 24) & 0xff000000)

int check_endianess(char *c)
{
	if(*c)
	{
		return 1;
	}

	return 0;
}

int main(void)
{
	unsigned int i = 1;
	char *c = (char*)&i;

	if(check_endianess(c))
	{
		printf("Little endian\n");
	}

	else
	{
		printf("Big endian\n");
	}

	i = 0x12345678;

	printf("Little endian - 0x%x\n", i);
	printf("Big endian - 0x%x\n", LITTLE_TO_BIG(i));

	return EXIT_SUCCESS;
}

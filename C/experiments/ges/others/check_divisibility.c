#include <stdio.h>
#include <stdlib.h>

#define SIZE 256

/*
If there is consecutive stream of bits coming(0's and 1's), at any point of time, we need to determine if the number is divisible by n(n maybe any valid integer >= 2). The numbers of bits can be infinitely large as well
 */

void check_divisibility(int divisibility)
{
	int num = 0;
	int input_bit;

	while(1)
	{
		scanf("%d", &input_bit);
		if(1 == input_bit)
		{
			num = (num * 2 + 1) % divisibility; 
		}

		else if(0 == input_bit)
		{
			num = (num * 2) % divisibility;
		}
		
		else
		{
			printf("invalid input - should be either 1 or 0\n");
			break;
		}		
	
		if(0 == (num % divisibility))
		{
			printf("divisible by %d\n", divisibility);
		}

		else
		{
			printf("not divisible by %d\n", divisibility);
		}
	}
}

int main(void)
{
	char *input = NULL;
	int divisibility = 0;

	if(NULL == (input = (char*)malloc(sizeof(char*))))
	{
		printf("no space available\n");
		return EXIT_FAILURE;
	}

	printf("check divisibility:\n");
	if(NULL == fgets(input, SIZE, stdin))
	{
		printf("couldn't read the input\n");
		return EXIT_FAILURE;
	}

	divisibility = atoi(input);

	if(divisibility < 2)
	{
		printf("invalid input -> should be greater than or equal to 2");
		return EXIT_FAILURE;
	}

	check_divisibility(divisibility);

	return EXIT_SUCCESS;
}

#include <stdio.h>
#include <stdlib.h>

#define SIZE 256

//count set bits
int countSetBits(int num)
{
	int count = 0;

	while(num)
	{
		num &= (num - 1);
		count++;
	}

	return count;
}

//count cleat bits
int countClearBits(int num)
{
	int count = 0;

	while(num)
	{
		if(!(num &= (num - 1)))
			count++;
	}

	return count;
}

//flipped bits between 2 nums
int flippedBits(int num1, int num2)
{
	return countSetBits(num1 ^ num2);
}

//dec to bin
void bin(int num)
{
	if(num > 1)
		bin(num >> 1);

	printf("%d", num & 1);
}

/*
 * given number is power of 2 or not
 */
int powerOfTwo(int num)
{
	if((0 != num) && (num & (num - 1)))
		return 1;

	return 0;
}

//set a bit in given number
void set(int num, int bitPos)
{
	num |= (1 << bitPos);

	bin(num);

	printf("\n");
}

//clear a bit in given number
void clear(int num, int bitPos)
{
	num &= (~(1 << bitPos));

	bin(num);

	printf("\n");
}

//toggle a bit in given number
void toggle(int num, int bitPos)
{
	num ^= (1 << bitPos);

	bin(num);

	printf("\n");
}

//take a byte and return a bit
int bitAtPos(int num, int bitPos)
{
	return (num >> bitPos) & 1;
}

#if 1
int main(void)
{
//	int num = 0;
	int num1 = 0;
	int num2 = 0;
	char *input = NULL;
//	int bitPos = -1;
	
	if(NULL == (input = malloc(sizeof(char*))))
	{
		printf("no space");
		return 0;
	}	
/*
	printf("enter a num : ");
	if(NULL == (fgets(input, SIZE, stdin)))
	{
		printf("read failed");
		return 0;
	}

	num = atoi(input);
*/
/*
	if(powerOfTwo(num))
		printf("%d is not a power of 2\n", num);

	else
		printf("%d is a power of 2\n", num);
*/
/*
	printf("enter bit position : ");
	if(NULL == (fgets(input, SIZE, stdin)))
    {
        printf("read failed");
        return 0;
    }
	bitPos = atoi(input);
*/		
/*	
	set(num, bitPos);
	clear(num, bitPos);
	toggle(num, bitPos);
*/

//	bin(bitAtPos(num, bitPos));

	printf("enter num1 : ");
	if(NULL == (fgets(input, SIZE, stdin)))
	{
		printf("read failed");
		return 0;
	}

	num1 = atoi(input);
  
	printf("enter num2 : ");
	if(NULL == (fgets(input, SIZE, stdin)))
	{
		printf("read failed");
		return 0;
	}

	num2 = atoi(input);

	printf("number of set bits in %d - %d\n", num1, countSetBits(num1));
	printf("number of set bits in %d - %d\n", num2, countSetBits(num2));
	printf("number of clear bits in %d - %d\n", num1, countClearBits(num1));
	printf("number of clear bits in %d - %d\n", num2, countClearBits(num2));

	printf("number of flipped bits in %d and %d - %d\n", num1, num2, flippedBits(num1, num2));

	free(input);
	input = NULL;

	return 0;
}
#endif

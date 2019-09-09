#include <stdio.h>
#include <stdlib.h>

#define MSIZE (sizeof(int) * 8)
#define BIT_AT_POS(num, bit_pos) (num >> bit_pos) & 1  //to find the bit at given pos
#define FLIPPED_BITS(num1, num2) countSetBits(num1 ^ num2) //to find the count of flipped bits
#define MAX(num1, num2) num1 ^ ((num1 ^ num2) & -(num1 < num2)) // maximum of two nums
#define MIN(num1, num2) num2 ^ ((num1 ^ num2) & -(num1 < num2)) // minimum of two nums
#define CLEAR_RIGHT_SET_BIT(num) num & (num - 1) //clear the rightmost set bit

//to print in binary
void print_binary(int num)
{
	int itr;

	for(itr = MSIZE - 1; itr >= 0; itr--)
	{
		(num & (1 << itr)) ? printf("1") : printf("0");
	}

	printf("\n");
}

//count set bits
static inline int countSetBits(int num)
{
    int count = 0;

    while(num)
    {
        num &= (num - 1);
        count++;
    }

    return count;
}

//count clear bits
static inline int countClearBits(int num)
{
    int count = 0;

    while(num)
    {
        num &= (num - 1);
        count++;
    }

    return MSIZE - count;
}

//to set all the bits from pos1 to pos2
int set_bits_pos1_pos2(int num, int pos1, int pos2)
{
	if(pos1 == pos2)
	{
		return num | (1 << pos1);
	}

	else if(pos1 > pos2)
	{
		while(pos1 >= pos2)
		{
			num |= (1 << pos2);
			pos2++;
		}
	}

	else
	{
		while(pos2 >= pos1)
        {
            num |= (1 << pos1);
            pos1++;
        }
	}

	return num;
}

//to toggle all the bits from pos1 to pos2
int toggle_bits_pos1_pos2(int num, int pos1, int pos2)
{
	if(pos1 == pos2)
	{
		return num ^ (1 << pos1);
	}

	else if(pos1 > pos2)
	{
		while(pos1 >= pos2)
		{
			num ^= (1 << pos2);
			pos2++;
		}
	}

	else
	{
		while(pos2 >= pos1)
        {
            num ^= (1 << pos1);
            pos1++;
        }
	}

	return num;
}

//reverse the bits in a num
int reverse_bits(int num)
{
	int temp_num = num;
	int count = MSIZE - 1;

	num >>= 1;

	while(num)
	{
		temp_num <<= 1;

		temp_num |= (num & 1);

		num >>= 1;

		count--;
	}

	temp_num <<= count;

	return temp_num;
}

//returns x with n bits that begins with at position p set to the rightmost n bits of y, leaving the other bits nuchanged 
int set_bit(int x, int p, int n, int y)
{
	int shift = p - n + 1;
	int mask = (1 << n) - 1;

	return (x & ~(mask << shift)) | ((y & mask) << shift);
}

int main(void)
{
	printf("bit at pos %d\n", BIT_AT_POS(8, 3));	
	printf("bit at pos %d\n", BIT_AT_POS(25, 4));	
	printf("bit at pos %d\n", BIT_AT_POS(1111, 6));	
	printf("bit at pos %d\n", BIT_AT_POS(0xffffffff, 7));	
	printf("bit at pos %d\n", BIT_AT_POS(0x00000000, 7));	

	printf("flipped bits - %d\n", FLIPPED_BITS(10, 25));
	printf("flipped bits - %d\n", FLIPPED_BITS(100, 225));
	printf("flipped bits - %d\n", FLIPPED_BITS(150, 125));
	printf("flipped bits - %d\n", FLIPPED_BITS(110, 112));
	printf("flipped bits - %d\n", FLIPPED_BITS(9, 8));

	printf("MAX(10, 20) : %d\n", MAX(10, 20));
	printf("MAX(112, -5) : %d\n", MAX(112, -5));
	printf("MAX(10, 0) : %d\n", MAX(10, 0));
	printf("MAX(-10, -20) : %d\n", MAX(-10, -20));
	printf("MAX(0, -20) : %d\n", MAX(0, -20));

	printf("MIN(10, 20) : %d\n", MIN(10, 20));
	printf("MIN(112, -5) : %d\n", MIN(112, -5));
	printf("MIN(10, 0) : %d\n", MIN(10, 0));
	printf("MIN(-10, -20) : %d\n", MIN(-10, -20));
	printf("MIN(0, -20) : %d\n", MIN(0, -20));

	printf("after CLEAR_RIGHT_SET_BIT(100) - %d\n", CLEAR_RIGHT_SET_BIT(100));
	printf("after CLEAR_RIGHT_SET_BIT(9) - %d\n", CLEAR_RIGHT_SET_BIT(9));
	printf("after CLEAR_RIGHT_SET_BIT(12) - %d\n", CLEAR_RIGHT_SET_BIT(12));
	printf("after CLEAR_RIGHT_SET_BIT(18) - %d\n", CLEAR_RIGHT_SET_BIT(18));
	printf("after CLEAR_RIGHT_SET_BIT(22) - %d\n", CLEAR_RIGHT_SET_BIT(22));

	printf("set_bits_pos1_pos2(10, 2, 7) : %d\n", set_bits_pos1_pos2(10, 2, 7));
	printf("set_bits_pos1_pos2(0, 5, 17) : %d\n", set_bits_pos1_pos2(0, 5, 17));
	printf("set_bits_pos1_pos2(100, 2, 27) : %d\n", set_bits_pos1_pos2(100, 2, 27));
	printf("set_bits_pos1_pos2(111, 12, 12) : %d\n", set_bits_pos1_pos2(111, 12, 12));
	printf("set_bits_pos1_pos2(10, 25, 15) : %d\n", set_bits_pos1_pos2(10, 25, 15));

	printf("toggle_bits_pos1_pos2(10, 2, 7) : %d\n", toggle_bits_pos1_pos2(10, 2, 7));
	printf("toggle_bits_pos1_pos2(0, 5, 17) : %d\n", toggle_bits_pos1_pos2(0, 5, 17));
	printf("toggle_bits_pos1_pos2(100, 2, 27) : %d\n", toggle_bits_pos1_pos2(100, 2, 27));
	printf("toggle_bits_pos1_pos2(111, 12, 12) : %d\n", toggle_bits_pos1_pos2(111, 12, 12));
	printf("toggle_bits_pos1_pos2(10, 25, 15) : %d\n", toggle_bits_pos1_pos2(10, 25, 15));

	printf("reverse_bits(1) : ");
	print_binary(reverse_bits(1));
	printf("reverse_bits(10) : ");
	print_binary(reverse_bits(10));
	printf("reverse_bits(15) : ");
	print_binary(reverse_bits(15));

	printf("binary of 45 : ");
	print_binary(45);
	printf("binary of 15 : ");
	print_binary(15);
	printf("after set_bit(45, 3, 4, 15) : ");
	print_binary(set_bit(45, 3, 4, 15));

	return EXIT_SUCCESS;
}
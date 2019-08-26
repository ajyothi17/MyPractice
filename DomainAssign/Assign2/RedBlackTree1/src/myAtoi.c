#include "header.h"

long long myAtoi(char *input)
{
	if(input == NULL || input[0] == '\0'){
		perror("invalid input");
		return 0xFFFFFFFFF;
	}

	long long num = 0;
	short int index = 0;
	
	if((input[0] == '-') || (input[0] == '+')){
		index = 1;	
	}
	
	while((input[index] >= '0') && (input[index] <= '9')){
		num = (num * 10) + (input[index] - '0');
		index++;
	}

	if(input[index] != '\0'){
		perror("invalid input");
		return 0xFFFFFFFFF;
	}

	if(input[0] == '-')
		num = 0 - num;

	if((num < INT_MIN) || (num > INT_MAX)){
		perror("out of range");
		return 0xFFFFFFFFF;
	}

	return num;
}

#include <stdio.h>
#include <stdlib.h>
#define MAX 128

int arr[MAX];

int main(int argc, char *argv[])
{
	FILE *fp = NULL;
	int ch;
	int top1 = -1;
	int top2 = -1;
	int top3 = -1;

	if(argc != 2){
		printf("invalid arguments: expecting ../obj/app <filename>");
		return EXIT_FAILURE;
	}
	
	if(NULL == (fp = fopen(*++argv, "r"))){
		printf("couldn't open file");
		return EXIT_FAILURE;
	}

	while(EOF != (ch = getc(fp))){
		switch(ch){
			case '[': top1 = push1(top1, ch);
					  break;
			
			case ']': top1 = pop1(top1);
					  break;

			case '(': top2 = push2(top2, ch);
					  break;

			case ')': top2 = pop2(top2);
					  break;

			case '{': top3 = push3(top3, ch);
					  break;

			case '}': top3 = pop3(top3);
					  break;

		}
	}

	if((top1 != -1) || (top2 != -1) || (top3 != -1)){
		printf("invalid braces\n");

	}else{
		printf("valid braces\n");
	}

	return EXIT_SUCCESS;
}

#ifndef __MY_HEADER__
	#define __MY_HEADER__  

	#include <stdio.h>
	#include <stdlib.h>
	#include <limits.h>
	#include <string.h>

	#define TRUE 1
	#define MAX 256
	#define FAILURE 0xfffffffff
	#define LOW 0
	#define HIGH 300
	#define STEP 20
	#define ISIZE 32
	#define CSIZE 128
	#define FIVE 5
	#define NINE 9
	#define SPACE ' '
	#define TAB '\t'
	#define LINE '\n'
	#define TWO 2
	#define ONE 1
	#define ZERO 0
	#define NUL '\0'
	#define SBRACE_OPEN '['
	#define SBRACE_CLOSE ']'
	#define CBRACE_OPEN '('
	#define CBRACE_CLOSE ')'
	#define FBRACE_CLOSE '}'
	#define FBRACE_OPEN '{'
	#define MAXLINE 80
	#define TABSPACE 8
	#define HANDLE_ERROR(msg) \
		do{ perror(msg); exit(EXIT_FAILURE);}while(0)

	int readInput(void);
	long long myAtoi(char*);
	
#endif

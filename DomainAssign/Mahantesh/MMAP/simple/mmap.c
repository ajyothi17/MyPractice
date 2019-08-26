#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>

#define MAX 256
#define PATH "./my_mem.txt"
#define PERM 0666
#define ERR -1
#define ZERO 0
//#define FILE_SIZE (MAX * sizeof(int *))
#define FILE_SIZE 256

void my_err_msg(char* msg)
{
	perror(msg);
	return;
}

int main(void)
{
	char *buf = NULL;
	char *map;
	int shm;

	if(NULL == (buf = (char *) malloc(sizeof(MAX)))){
		my_err_msg("malloc failed");
		return EXIT_FAILURE;
	}
	
	if(ERR == (shm = open(PATH, O_CREAT | O_RDWR, PERM))){
		my_err_msg("open() failed");
		return EXIT_FAILURE;
	}
	
	printf("open successful\n");

	if(MAP_FAILED == (map = (char *) mmap( ZERO, FILE_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm, ZERO))){
		my_err_msg("mmap() failed");
		printf("b\n");
		exit(1);	
//		if(close(shm)){
//			my_err_msg("close() failed");
//		}

//		return EXIT_FAILURE;
	}

	printf("a\n");
	buf = "Hello world!";
	printf("buf = %s\n", buf);
	buf = strcpy(map, buf);
	
	printf("map = %s\n", map);
	printf("c\n");
	printf("%s\n", buf);
	printf("d\n");
	if(munmap(ZERO, FILE_SIZE)){
		my_err_msg("munmap() failed");
/*		
		if(close(shm)){
			my_err_msg("close() failed");
		}
qq*/

		
		printf("f\n");
		return EXIT_FAILURE;
	}
	printf("e\n");

//	free(buf);

	printf("g\n");

	buf = NULL;

	if(close(shm)){
		my_err_msg("close() failed");
	}

	printf("close success\n");

	return EXIT_SUCCESS;
}

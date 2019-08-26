#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define ERR -1
#define ZERO 0
#define ONE 1

int main(void)
{
	int fd;
	char data;
	short count = 0x0100;

	fd = open("/dev/ParallelPort", O_RDWR);

	if(fd < ZERO){

		printf("Unable to open device\n");
		return EXIT_FAILURE;
	}
	
	printf("file opened successfully %d\n", fd);

	data = 0x01;
	
	while((data & count) == 0){
		if(write(fd, &data, ZERO) == ERR)
			printf("error!");

		data <<= ONE;
	}
	
	data = 0x0;
	write(fd, &data, ZERO);
	
/*	data = 0x0f;
	if(write(fd, &data, ZERO) == ERR)
		printf("error!");
*/
	return EXIT_SUCCESS;
}

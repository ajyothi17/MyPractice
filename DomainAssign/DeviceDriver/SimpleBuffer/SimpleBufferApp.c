#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

#define ZERO 0
#define ARR_SIZE 25
#define BUF_SIZE (1024 * 1024)

int main( void )
{
	int fd ;
	char wbuf[ARR_SIZE] = "Hello World";
	char rbuf[BUF_SIZE];
	int res = ZERO;
	int index = ZERO;

	fd = open( "/dev/simple_driver",  O_RDWR );
	if( fd < ZERO ) {	
		printf(" Cannot open file\n");
		return ZERO;
	}

	
	while(1){
		res = write(fd, wbuf, (strlen(wbuf)));
		if(!res){
			printf("Write failure\n");
			break;
//			return EXIT_FAILURE;
		} 
		else {
			printf("%s written\n",wbuf);

		}

	}

	if( (res = lseek(fd, ZERO, SEEK_SET)) < ZERO) {
		printf("ERROR : lseek error\n");
		return EXIT_FAILURE;
	}

	sleep(10);
//	for(index = 0; index < 2; index++){
	while(1){
		res = read(fd, rbuf, (strlen(wbuf)));
		if( !res) {
			printf("Read failure\n");
			break;
//			return EXIT_FAILURE;
		}	
		else { 
			printf("%d bytes read \"%s\"\n",res,rbuf);

		}
	}

	close(fd);

	return EXIT_SUCCESS;
}


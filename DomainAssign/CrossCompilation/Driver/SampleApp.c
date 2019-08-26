#include <stdio.h>
#include <fcntl.h>

int main( void )
{
    int fd;
    
    fd = open("dev/sample",O_RDWR);
    
    if(fd < 0)
        perror("Unable to open the device\n");
    else
        printf("File opened successfully %d\n", fd);

    close(fd);

    return 0;

}

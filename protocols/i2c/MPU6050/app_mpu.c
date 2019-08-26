#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main(void)
{
	int fd;
	int buf[6];	
	int index;
	char axis[3] = {'X', 'Y', 'Z'};

	fd = open("/dev/mpu6050", O_RDWR);

	if(fd < 0)
		perror("Unable to open the device \n");
	else
	{
		printf("file opened successfully\n");
		if(read(fd, buf, NULL) < 0)
		{
			perror("Read failed in user application\n");
			exit(EXIT_FAILURE);
		}

		for(index = 0; index <= 6; index++)	
		{
			if(index >= 0 && index <= 3)
			{	
				if(buf[index] <= -32750 ||  buf[index] >= 32750)
				{
					perror("Gyrometer reading out of range\n");
					exit(EXIT_FAILURE);
				}
				else
					printf("Gyro = %c --> %d\n", axis[index], buf[index]);
			}
			else
			{
				if(buf[index] <= -32768 || buf[index] >= 32768)
				{
					perror("Accelerometer reading out of range\n");
					exit(EXIT_FAILURE);
				}
				else
					printf("Acc = %c --> %d\n", axis[index - 3], buf[index]);
			}
		}
	
	}

	write(fd,buf,1);
	close(fd);
	return 0;
}

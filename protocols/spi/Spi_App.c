/*****************************************************************************/
/*****************************************************************************/
/*                 Linux SPI Driver Application for ADC                      */
/*****************************************************************************/
/******************************************************************************

		            Interfacing ADC with Raspberry Pi
                Model  : Raspberry Pi 3 - B
                ADC    : MCP3202 (12bit, SPI Support)

                Author : Aditya Nandkumar Hambar
                         Software Engineer,
                         GlobalEdge Software Limited, Bangalore

                Date   : 7th March 2018

******************************************************************************/
/******************************************************************************

		This is a Linux SPI driver application for interfacing ADC MCP3202
        with Raspberry Pi Board. This program opens SPI device and reads
   	    the conversion value given by the ADC chip.
                                                                   
******************************************************************************/
/*****************************************************************************/


// Header includes
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>

// Function for printing integer in binary format
void bitprint(int n)
{
	int i = 31;
	while(i >= 0)
	{
		if(n & 1 << i)
			printf("1");
		else
			printf("0");
	i--;
	}
}

// Main function
int main()
{
	int fd, i = 0, val = 0;
	float voltage = 0;
	// Opening of SPI device
	fd = open("/dev/SPI_ADC",O_RDWR);

	if(fd < 0)
		perror("Unable to open the Device");
	else{
		// Printing value read from ADC
		printf("File opened successfully %d\n",fd);
		printf("\n\n\t ____________________________________\n");
		printf("\t|------------------------------------|\n");
		printf("\t|      Linux SPI Driver for ADC      |\n");
		printf("\t|------------------------------------|\n");

		for(i = 0; i < 20; i++){
			read(fd, &val, sizeof(val));
			printf("\t|          Digital output :          |\n");
			printf("\t|  ");
			bitprint(val);
			printf("  |\n");
			printf("\t|------------------------------------|\n");
			printf("\t|      Voltage applied to ADC :      |\n");
			voltage = 0;
			voltage = ((val * 4.8) / 4095);
			printf("\t|\t    %f volt\t     |\n", voltage);
			printf("\t|------------------------------------|\n");
		}
		// Closing of SPI device
		close(fd);
	}
	return 0;
}



#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int myRead(void);
void myWrite(int);

int main(void)
{
	int num = 20;

	printf("writing...");
	myWrite(num);

	printf("reading...");
	printf("%d\n", myRead());

	return EXIT_SUCCESS;
}

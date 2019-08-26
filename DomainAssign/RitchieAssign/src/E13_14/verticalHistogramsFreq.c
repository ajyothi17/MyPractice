// function to print vertical histograms of the lengths of words

#include"header.h"

void verticalHistogramsFreq(void)
{
	int charArray[CSIZE];
	int ch;
	int max = ZERO;
  	int index1 = ZERO;
	int index2 = ZERO;
  	char *str = NULL;

	if(NULL == (str = malloc(sizeof(char *) * MAX))){
		HANDLE_ERROR("no memory available");
	}

	printf("enter the string:");
	if(NULL == fgets(str, MAX, stdin)){
		HANDLE_ERROR("couldn't read input");
	}

	for(index1 = ZERO; index1 < CSIZE; index1++){
		charArray[index1] = ZERO;
	}

	ch = ZERO;
	index1 = ZERO;
	
  	while(*(str + index1) != LINE){
		if(*(str + index1) > max)
			max = *(str + index1);

      	charArray[*(str + index1)] += ONE; 

		index1++;  
		ch++;
  	}

	for(index1 = ZERO; index1 < CSIZE; index1++){
		if(charArray[index1])
			printf("%c", index1);
		
		else
			printf(" ");
	}
	printf("\n");

  	for(index1 = ch; index1 > ZERO; --index1){
    	for(index2 = ZERO; index2 <= max; ++index2){
      		if( index1 <= charArray[index2])
        		printf("*");
      		
			else  
        		printf(" ");
      	}

		printf("\n");
  	}

	free(str);
	str = NULL;
}

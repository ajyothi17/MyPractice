// function to print vertical histograms of the lengths of words

#include"header.h"

void verticalHistograms(void)
{
	int word[MAX];
	int no_of_char;
	int no_of_words;
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
	
	while(*(str + index1) != NUL){
		index1++;	
	}

	*(str + index1 - ONE) = NUL;
	no_of_char = ZERO;
	no_of_words = ZERO;
	index1 = 0;

  	while(*(str + index1) != '\0'){
    	++no_of_char;

    	if(*(str + index1) == SPACE || *(str + index1) == LINE || *(str + index1) == TAB || *(str + index1 + ONE) == NUL){
			if(no_of_char > max)
				max = no_of_char;

			if(*(str + index1 + ONE) == NUL)
				no_of_char++;

      		word[no_of_words] = no_of_char - ONE; 
      		++no_of_words;
      		no_of_char = ZERO; 
    	}

		index1++;  
  	}

  	for(index1 = max; index1 > ZERO; --index1){
    	for(index2 = ZERO; index2 < no_of_words; ++index2){
      		if( index1 <= word[index2])
        		printf("*");
      		
			else  
        		printf(" ");
      	}

		printf("\n");
  	}

	free(str);
	str = NULL;
}

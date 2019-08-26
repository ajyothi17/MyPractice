#include "header.h"

int main(int argc, char *argv[])
{
	int c;
	int flag = ZERO;
	FILE *fp = NULL;

	if(argc != 2){
		HANDLE_ERROR("invalid args, expecting : ../obj/app <input_file>");
	}

	if(NULL == (fp = fopen(*++argv, "r"))){
		HANDLE_ERROR("couldn't open file\n");
	}

	while((c = getc(fp)) != EOF){
		if((c == LINE) || (c == TAB) || (c == SPACE)){
			if(flag){
				flag = ZERO;
				printf("\n");
			}
		}

		else if(flag == ZERO){
			flag = ONE;
			printf("%c", c);
		}			
		else{
			printf("%c",c);
		}	
	}

	if(fclose(fp)){
		HANDLE_ERROR("couldn't close file");
	}

	return EXIT_SUCCESS;
}

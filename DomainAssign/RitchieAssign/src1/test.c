/**
 *test program which accepts input for each module
*/

#include "header.h"

int main(void)
{
	int ch;

	while(TRUE){
		printf("1. print Hello World\n"
				"2. printf argument \'\\c\'\n"
				"3. print Fahrenheit- Celsius Table\n"
				"4. print Celsius - Fahrenheit Table\n"
				"5. print temperature in reverse order(300 - 0)\n"
				"6. getchar() != EOF\n"
				"7. value of EOF\n"
				"8. count blanks, tabs, newlines\n"
				"9. replace multiple space by single space\n"
				"10. replace tab -> \\t, new line -> \\n, backslash -> \\\n"
				"11. print one word per line\n"
				"12. vertical histogram of words\n"
				"13. vertical histogram of frequency of characters\n"
				"14. print all input lines longer than 80\n"
				"15. remove trailing blanks and tabs from each line of input\n"
				"16. reverse a string\n"
				"17. replce tab by space\n"
				"18. replace space minimum no. of tabs\n"
				"19. \n"
				"20. remove comments in a C program\n"
				"21. check for unbalanced parentheses\n"
				"22. exit\n");
		printf("enter your choice:");
		ch = readInput();

		switch(ch){
			case 1: helloWorld(); 
					break;

			case 2: print();
					break;

			case 3: fahrenheitCelsius();
					break;

			case 4: celsiusFahrenheit();
					break;

			case 5: fahrenheitCelsiusReverse();
					celsiusFahrenheitReverse();
					break;

			case 6: getChar();
					break;

			case 7: printEOF();
					break;

			case 8:	countSpace();
					break;
			
			case 9: replaceSpace();
					break;

			case 10: replace();
					 break;

			case 11: printWord();
					 break;

			case 12: verticalHistograms();
					 break;
			
			case 13: verticalHistogramsFreq();
					 break;

			case 14: printLines();
					 break;
			
			case 15: removeTrailingSpace();
					 break;

			case 16: reverse();
					 break;

			case 17: detab();
					 break;
			
			case 18: entab();
					 break;
			
/*			case 19: 
					 break;

			case 20: removeComments();
					 break;
		
			case 21: balance();
					 break;
*/
			case 22: exit(EXIT_SUCCESS);				
			
			default: printf("invalid choice\n");	
		}
	}
}

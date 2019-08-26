#include "header.h"

void celsiusFahrenheit(void)
{
	float fahr;
	float celsius;

	printf("Celsius\tFahrenheit\n");

	for(celsius = LOW; celsius <= HIGH; celsius += STEP){
		fahr = (celsius * FIVE)/NINE + ISIZE;
		printf("%.2f\t%.2f\n", celsius, fahr);
	}

}

void celsiusFahrenheitReverse(void)
{
	float fahr;
	float celsius;

	printf("Celsius\tFahrenheit\n");

	for(celsius = HIGH; celsius >= LOW; celsius -= STEP){
		fahr = (celsius * FIVE)/NINE + ISIZE;
		printf("%.2f\t%.2f\n", celsius, fahr);
	}

}

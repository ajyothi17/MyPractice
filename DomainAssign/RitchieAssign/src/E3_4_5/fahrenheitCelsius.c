#include "header.h"

void fahrenheitCelsius(void)
{
	float fahr;
	float celsius;

	printf("Fahrenheit\tCelsius\n");

	for(fahr = LOW; fahr <= HIGH; fahr += STEP){
		celsius = FIVE * (fahr - ISIZE) / NINE;
		printf("%.2f\t\t%.2f\n", fahr, celsius);
	}

}

void fahrenheitCelsiusReverse(void)
{
	float fahr;
	float celsius;

	printf("Fahrenheit\tCelsius\n");

	for(fahr = HIGH; fahr >= LOW; fahr -= STEP){
		celsius = FIVE * (fahr - ISIZE) / NINE;
		printf("%.2f\t\t%.2f\n", fahr, celsius);
	}

}

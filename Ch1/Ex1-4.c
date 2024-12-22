#include <stdio.h>
/* Print a table of celsius to fahrenheit
    temperatures in the range 0, 20, 40, ..., 300  celsius*/
int main()
{
    printf("Celsius to Fahrenheit(0f - 300f)\n");
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    celsius = lower;
    while (celsius <= upper) {
        fahr = 9.0 / 5.0 * celsius + 32; 
        printf("%3.0f\t%6.1f\n", celsius, fahr);
        celsius += step;
    }
}
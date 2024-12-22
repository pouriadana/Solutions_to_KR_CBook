#include <stdio.h>
/* Print a table of fahrenheit to celsius
    temperatures 0, 20, 40, ..., 300  fahr*/
int main()
{
    printf("Fahrenheit to Celsius (0f - 300f)\n");
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    while (fahr <= upper) {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr += step;
    }
}
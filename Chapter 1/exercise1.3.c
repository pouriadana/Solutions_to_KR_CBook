/* Exercise 1.13 - Chapter 1*/
/* Print a heading above the temperature conversion program */

#include <stdio.h>
int main()
{
    int lower, step, upper;
    float fahr, celsius;

    lower = 0;
    upper = 300;
    step = 20;

    printf("Fahrenheit    Celsius\n");
    fahr = lower;
    while (fahr <= upper) {
        celsius = 5.0/9.0 * (fahr-32.0);
        printf("%10.0f%4c%7.1f\n", fahr, ' ', celsius);
        fahr = fahr + step;
    }
}
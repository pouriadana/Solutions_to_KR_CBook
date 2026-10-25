/* Page 12 - Chapter 1*/

#include <stdio.h>
int main()
{
    int lower, step, upper;
    float fahr, celsius;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    while (fahr <= upper) {
        celsius = 5.0/9 * (fahr-32);
        printf("%3.0f    %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}
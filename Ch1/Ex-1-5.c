#include <stdio.h>
int main()
{
    printf("Fahrenheit to Celsius (300f - 0f)\n");
    int fahr;
    for (fahr = 300; fahr >= 0; fahr = fahr - 20) 
        printf("%3d\t%6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
}
#include <stdio.h>

double to_celsius(int f);

int main()
{
    for (int i = 0; i <= 300; i = i + 20) {
        printf("%3d\t%6.1f\n", i, to_celsius(i));
    }
}

double to_celsius(int fahr)
{
    return 5.0/9.0 * (fahr - 32);
}
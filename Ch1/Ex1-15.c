#include <stdio.h>

int to_celsius(int f);

int main()
{
    for (int i = 0; i <= 300; i = i + 20) {
        printf("%3d\t%6d\n", i, to_celsius(i));
    }
}

int to_celsius(int fahr)
{
    return 5 * (fahr - 32) / 9;
}
/* first in-text program of section Functions 1.7 */
/* function "power" */

#include <stdio.h>

int power(int m, int n);

int main()
{
    int i;

    for (i = 0; i < 10; ++i)
        printf("%d %d %d\n", i, power(2, i), power(-3, i));
    return 0;
}

int power(int base, int n)
{
    int i;
    int result;

    i = 0;
    result = 1;
    for (i = 0; i < n; ++i)
        result *= base;
    return result;
}
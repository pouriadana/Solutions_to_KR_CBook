/* Print a histogram of characters in input */
/* Edition: Use one function to print different arrays of alphabet and numbers */
#include <stdio.h>
#define NEWLINE '\n'
#define DRAWSYM '='

void phistogram(int a[], int start, int end);

int main()
{
    int c;
    int i;
    int nother;
    int alpha[26];
    int numerals[10];

    for (i = 0; i < 26; ++i)
        alpha[i] = 0;
    for (i = 0; i < 10; ++i)
        numerals[i] = 0;

    nother = 0;
    while ((c = getchar()) != EOF) {
        if (c >= 'A' && c <= 'Z')
            alpha[c - 'A']++;
        else if (c >= 'a' && c <= 'z')
            alpha[c - 'a']++;
        else if (c >= '0' && c <= '9')
            numerals[c - '0']++;
        else
            nother++;
    }

    phistogram(alpha, 'A', 'Z');
    phistogram(numerals, '0', '9');
}

void phistogram(int a[], int start, int end)
{
    int i, j;
    for (i = start; i <= end; ++i) {
        printf("%2c|", i);
        for (j = 0; j < a[i-start]; ++j)
            putchar(DRAWSYM);
        putchar(NEWLINE);
    }
}
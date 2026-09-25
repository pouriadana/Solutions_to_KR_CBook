#include <stdio.h>
#define NEWLINE '\n'
#define DRAWSYM '='

int main()
{
    int c;
    int i;
    int j;
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

    for (i = 'A'; i <= 'Z'; ++i) {
        printf("%2c|", i);
        for (j = 0; j < alpha[i-'A']; ++j) {
            putchar(DRAWSYM);
        }
        putchar(NEWLINE);
    }

    for (i = '0'; i <= '9'; ++i) {
        printf("%2c|", i);
        for (j = 0; j < numerals[i-'0']; ++j)
            putchar(DRAWSYM);
        putchar(NEWLINE);
    }
}
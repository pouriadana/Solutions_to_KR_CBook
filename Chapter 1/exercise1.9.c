#include <stdio.h>

// (input -> output)replace each string of 1 or more blanks by a single blank
int main()
{
    int c;
    char r;

    r = 'A';
    while ((c = getchar()) != EOF) {
        if (c == ' ' && r != ' ')
            putchar(c);
        if (c != ' ')
            putchar(c);
        r = c;
    }
}
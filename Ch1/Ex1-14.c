#include <stdio.h>

#define OUT 0
#define IN 1
#define ALEPH 26

int main()
{
    int c;
    int faleph[ALEPH];

    for (int i = 0; i < ALEPH; ++i) {
        faleph[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if ('A' <= c && 'Z' >= c) {
            ++faleph[c - 'A'];
        }
        else if ('a' <= c && 'z' >= c) {
            ++faleph[c - 'a'];
        }
    }

    for (int i = 0; i < ALEPH; ++i) {
        printf("%c\t", 'A' + i);
        for (int inner_i = 0; inner_i < faleph[i]; ++inner_i) {
            putchar('#');
            putchar(' ');
        }
        putchar('\n');
    }
}
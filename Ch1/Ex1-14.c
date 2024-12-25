#include <stdio.h>

#define DIGIT 10
#define ALEPH 26

int main()
{
    int c;
    int faleph[ALEPH];
    int fdigit[DIGIT];

    for (int i = 0; i < ALEPH; ++i) {
        faleph[i] = 0;
    }
    for (int i = 0; i < DIGIT; ++i) {
        fdigit[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if ('A' <= c && 'Z' >= c) {
            ++faleph[c - 'A'];
        }
        else if ('a' <= c && 'z' >= c) {
            ++faleph[c - 'a'];
        }
        else if ('0' <= c && '9' >= c) {
            ++fdigit[c - '0'];
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
    for (int i = 0; i < DIGIT; ++i) {
        printf("%c\t", '0' + i);
        for (int inner_i = 0; inner_i < fdigit[i]; ++inner_i) {
            putchar('#');
            putchar(' ');
        }
        putchar('\n');
    }
}
#include <stdio.h>

#define OUT 0
#define IN 1
#define UPPER 15

int main()
{
    int c, lword, state;
    int freq[UPPER];

    for (int i = 0; i < UPPER; ++i) {
        freq[i] = 0;
    }

    lword = 0;
    state = OUT;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            state = OUT;
            ++freq[lword];
            lword = 0;
        }
        else if (state == OUT) {
            state = IN;
        }
        if (state == IN) {
            ++lword;
        }
    }

    int x = 0;
    for (int i = 0; i < UPPER; ++i) {
        ++x;
        for (int inner_i = 0; inner_i < UPPER; ++inner_i) {
            if (freq[inner_i] >= x) {
                printf("#\t");
            }
            else {
                printf(" \t");
            }
        }
        putchar('\n');
    }
    printf("\n");
}
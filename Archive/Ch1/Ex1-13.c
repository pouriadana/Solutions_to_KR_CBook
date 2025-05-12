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
    for (int i = 0; i < UPPER; ++i) {
        printf("%d ", freq[i]);
    }
    printf("\n");
}
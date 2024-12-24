/* Program to print a horizental histogram of the lengths of the words
    in a text stream */
/* Known bug: a dot, comma, exclaimation mark, or a question mark count 
    in measuring the length of a word */
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
        printf("%15s %d\t", "Char length:", i);
        for (int inner_i = 0; inner_i < freq[i]; ++inner_i) {
            putchar('#');
        }
        putchar('\n');
    }
    printf("\n");
}
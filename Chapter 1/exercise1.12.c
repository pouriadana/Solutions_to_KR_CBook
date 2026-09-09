#include <stdio.h>
#define OUT 0
#define IN  1
// mody word count program to print input one word per line
int main()
{
    int c, state;

    state = OUT;
    while ((c = getchar()) != EOF) {
        if (c == '\n' || c == ' ' || c == '\t') {
            if (state == IN)
                putchar('\n');
            state = OUT;
        }
        else if (state == OUT) {
            state = IN;
        }
        if (state == IN) {
            putchar(c);
        }
    }
}
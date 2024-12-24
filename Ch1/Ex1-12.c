#include <stdio.h>

#define OUT 0
#define IN 1

int main()
{
    int c, nl, nw, nc, state;

    nl = nw = nc = 0;
    state = OUT;
    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n') {
            ++nl;
            putchar(c);
        }
        if (c == ' ') {
            putchar(c);
        }
        if (c == ' ' || c == '\t' || c == '\n') {
            state = OUT;
        }
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
        if (state == IN) {
            putchar(c);
        }
    }
    printf("%d %d %d\n", nl, nw, nc);
}
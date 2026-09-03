#include <stdio.h>

// counts blanks, tabs, newlines
int main()
{
    int c;
    int nb, nt, nn;

    nb = nt = nn = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ')
            nb++;
        if (c == '\t')
            nt++;
        if (c == '\n')
            nn++;
    }
    printf("Blanks: %d\nTabs: %d\nNewlines: %d\n", nb, nt, nn);
}
#include <stdio.h>
int main()
{
    long blanks_nc, tabs_nc, newlines_nc;
    int c;

    blanks_nc = tabs_nc = newlines_nc = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            ++blanks_nc;
        }
        if (c == '\t') {
            ++tabs_nc;
        }
        if (c == '\n') {
            ++newlines_nc;
        }
    }
    printf("%10s\t%ld\n", "Blanks", blanks_nc);
    printf("%10s\t%ld\n", "Tabs", tabs_nc);
    printf("%10s\t%ld\n", "Newlines", newlines_nc);
}
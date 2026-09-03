#include <stdio.h>

// (input -> output)replace each tab, backspace and '\' by \t, \b, and \\ respectively. 
int main()
{
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\t')
            printf("\\t");
        else if (c == '\b')
            printf("\\b");
        else if (c == '\\') /* what's the point of this? */
            printf("\\\\");
        else
            putchar(c);
    }
}
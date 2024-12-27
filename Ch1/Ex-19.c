#include <stdio.h>

#define MAXLINE 1000

int getmyline(char input[], int lim);

int main()
{
    char line[MAXLINE];
    int n;

    while ((n = getmyline(line, MAXLINE)) > 1) {
        printf("%s\n", line);
        // reverse character here
    }
}

int getmyline(char input[], int lim)
{
    int c, i;

    for (i = 0; (c = getchar()) != EOF && c != '\n' && i < lim - 1; ++i) {
        input[i] = c;
    }
    input[i] = '\0';
    return i;
}
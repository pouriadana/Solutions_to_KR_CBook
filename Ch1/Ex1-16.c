#include <stdio.h>

#define MAXLINE 100     // set to 100 for demonstration purposes

int getmyline(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
    int len, max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = len = 0;
    while ((len = getmyline(line, MAXLINE)) > 0) {
        if (len > MAXLINE) {
            line[MAXLINE - 2] = '\n';
        }
        if (len > max) {
            copy(longest, line);
            max = len;
        }
    }
    if (max > 0) {
        printf("\n%d\n%s", max, longest);
    }
}

int getmyline(char line[], int lim)
{
    int i, c, extra;
    extra = 0;

    for (i = 0; (c = getchar()) != EOF && c != '\n' && i < lim-1; ++i) {
        line[i] = c;
    }
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    if (c != '\n' && c != EOF) {
        ++extra;
        while ((c = getchar()) != '\n' && c != EOF) {
            ++extra;
        }
    }
    return i + extra;
}

void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}
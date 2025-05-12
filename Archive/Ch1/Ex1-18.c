#include <stdio.h>

#define MAXLINE 1000     // set to 100 for demonstration purposes

int getmyline(char line[], int maxline);
void processline(char line[], int lim);
int calulatelength(char line[]);

int main()
{
    int len, max;
    char line[MAXLINE];

    max = len = 0;
    while ((len = getmyline(line, MAXLINE)) > 0) {
        if (len > MAXLINE) {
            line[MAXLINE - 2] = '\n';
        }
        printf("%d\n", len);
        printf("Line's length before processing:\t%d\n", calulatelength(line));
        processline(line, len);
        printf("Line's length after processing:\t%d\n", calulatelength(line));
        // if the length of line is 1, it means it's a blank line
        // therefore, it will be skipped
        if (calulatelength(line) > 1) {
            printf("%s", line);
        }
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

void processline(char line[], int len)
{
    // printf("line[len - 1]: %d\n", line[len - 1]);
    if (len > 1) {
        while (len > 1 && (line[len - 2] == ' ' || line[len - 2] == '\t')) {
            line[len - 2] = '\n';
            line[len - 1] = '\0';
            --len;
        }
    }
}

int calulatelength(char line[])
{
    int i;

    for (i = 0; line[i] != '\0'; ++i)
        ;
    return i;
}
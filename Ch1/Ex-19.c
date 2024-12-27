#include <stdio.h>

#define MAXLINE 1000

int getmyline(char input[], int lim);
int revline(char toreverse[], char originalline[], int lim);

int main()
{
    char line[MAXLINE];
    char rline[MAXLINE];
    int n;

    while ((n = getmyline(line, MAXLINE)) > 1) {
        printf("original:\t%s\n", line);
        // reverse character here
        revline(rline, line, n);
        printf("Reversed:\t%s\n", rline);
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

int revline(char toreverse[], char originalline[], int lim)
{
    int i, j;

    j = 0;
    for (i = lim - 1; i >= 0; --i, ++j) {
        //printf("inside loop\n");
        toreverse[j] = originalline[i];
    }
    toreverse[j] = '\0';
    return i;
}
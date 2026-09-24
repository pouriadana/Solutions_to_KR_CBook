#include <stdio.h>
#define NEWLINE '\n'
#define MAXWLENGTH 50 // maximum word length
#define IN 1
#define OUT 0
#define DRAWSYM '='

/* Display a histogram of the length of the words in input */
/* Horizontal Version */

int main()
{
    int i, j;
    int c;
    int lword;
    int lmax;
    int state;
    int lwords[MAXWLENGTH];

    lword = lmax = 0;
    for (i = 0; i < MAXWLENGTH; ++i)
        lwords[i] = 0;

    state = OUT;
    while ((c = getchar()) != EOF) {
        if (c == '\n' || c == '\t' || c == ' ') {
            if (state == IN) {  // prevent consecutive whitespace to cause invalid count save
                lwords[lword]++;
                if (lword > lmax)
                    lmax = lword;
                lword = 0;
            }
            state = OUT;
        }
        else if (state == OUT)
            state = IN;
        if (state == IN)
            lword++;
    }

    for (i = 1; i <= lmax; ++i) {
        printf("%d ", i);
        for (j = 0; j < lwords[i]; ++j) {
            putchar(DRAWSYM);
        }
        putchar(NEWLINE);
    }
}


/* NOTICE */
/* This program is buggy. Dots, commas, and similar punctuations
should not be counted in when counting the length of a word, but
they are if they come immediately before or after a word or 
they will be considered a word if they are delimted by whitespace
on both sides. 
A symbol such as '>' should not be counted as a word (?). */
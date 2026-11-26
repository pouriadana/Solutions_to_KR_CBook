/* exercise 4.7 - Chapter 4 */
/* implement ungets - puts back a string into input */

#include <stdio.h>
#include <ctype.h>

#define MAX 1000
enum boolean {FALSE, TRUE} ;

int getline(char line[], int size);
void ungets(char []);
enum boolean alldigits(char []);

int main()
{
	char line[MAX];

	while (getline(line, MAX) > 0) {
		if (alldigits(line))
			printf("\t%s", line);
		else {
			ungets(line);
			printf("unrecognized string pattern detected\n\"\n%s\"\n"
			        "exiting...\n", line);
			break;
		}
	}
	printf("\t%s", line);
}

int getline(char line[], int size)
{
	int i, c;

	for (i = 0; i < size-1 && (c = getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;
	if (c == '\n')
		line[i++] = c;
	line[i] = '\0';
	return i;
}

#define BUFFSIZE 100

char buffer[BUFFSIZE];
int bufp = 0;		/* next free position in buf */

int getch(void)		/* get a (possibly pushed back) character */
{
	if (bufp <= 0)
		return getchar();
	else
		return buffer[--bufp];
}

void ungetch(int c)
{
	if (bufp >= BUFFSIZE)
		printf("ungetch: too many characters\n");
	else
		buffer[bufp++] = c;
}

void ungets(char s[])
{
	int i;
	for (i = 0; s[i] != '\0' && s[i] != '\n' && s[i] != EOF; i++) {
		ungetch(s[i]);
	}
	if (s[i] == '\n')
		ungetch(s[i++]);
	ungetch('\0');
}

enum boolean alldigits(char s[])
{
	int i;
	for (i = 0; s[i] != '\0' && s[i] != '\n'; i++)
		if ( !isdigit(s[i]) )
			return FALSE;
	return TRUE;
}
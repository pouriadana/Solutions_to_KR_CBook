/* The calculator program from 4.3 - Chapter 4 p.76 */

#include <stdio.h>
#include <stdlib.h>		// atof()
#include <ctype.h>

#define MAXOP 100	// maximum length of the operator or operant
#define NUMBER '0'

int getop(char s[]);
void push(double val);
double pop(void);

int main()
{
	char op[MAXOP];
	int type;

	while ((type = getop(op)) != EOF) {
		switch(type) {
		case NUMBER:
			push(atof(op));
			break;

		case '+':
			push(pop() + pop());
			break;

		case '\n':
			printf("\t%g\n", pop());
			break;

		default:
			printf("Unrecognized token\n");
			break;
		}

	}
}		

#define MAXVAL 1000

int sp = 0;
double stack[MAXVAL];

void push(double val)
{
	if (sp < MAXVAL)
		stack[sp++] = val;
	else
		printf("error: stack full. can't push %g\n", val);
}

double pop()
{
	if (sp < 0) {
		printf("error: stack empty.\n");
		return 0.0;
	}
	else
		return stack[--sp];
}

int getch();
void ungetch(int);

int getop(char s[])
{
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c;		/* not a number */
	i = 0;
	if (isdigit(c))		/* collect the integer part */
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')		/* collect the fractional part */
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';		// i always refers to the last read character in the array
	if (c != EOF)
		ungetch(c);
	return NUMBER;
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
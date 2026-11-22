/* exercise 4-3 - CHhapter 4 */

#include <stdio.h>
#include <stdlib.h>		// atof()
#include <ctype.h>

#define MAXOP 100	// maximum length of the operator or operant
#define NUMBER '0'
#define NEGNUMBER '?'

int getop(char s[]);
void push(double val);
double pop(void);

int main()
{
	char op[MAXOP];
	int type;
	double op2;

	while ((type = getop(op)) != EOF) {
		switch(type) {
		case NUMBER:
			push(atof(op));
			break;
		case NEGNUMBER:
			push(-1 * atof(op));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '*':
			push(pop() * pop());
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: division by zero detected\n");
			break;
		case '%':
			op2 = pop();
			if ((int)op2 != 0.0)
				push((int)pop() % (int)op2);
			else
				printf("error: division by zero over modulo\n");
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
	int i, c, c2, sign;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (c == '-' || c == '+')		/* collect negative or positive numbers with unary '-', '+' */
		if (isdigit(c2 = getch()) || c2 == '.') {
			s[0] = c2;
			sign = (c == '-') ? -1 : 1;
			c = c2;
		}
		else
			ungetch(c2);
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
	if (sign == -1)
		return NEGNUMBER;
	else
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
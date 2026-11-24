/* exercise 4-3 - CHhapter 4 */

#include <stdio.h>
#include <stdlib.h>		// atof()
#include <ctype.h>		// isdigit(), isalpha()
#include <math.h>		// sin(), pow(), exp()
#include <string.h>		// strlen()

#define MAXOP 100	// maximum length of the operator or operant
#define NUMBER '0'
#define PRINT ':'
#define DUPLICATE '#'
#define SWAP '&'
#define CLEAR '!'
#define SIN '1'
#define POW '2'
#define EXP '3'
#define SVAR '4'	// single-letter variable
#define ASGN '='	// assign command

int getop(char s[]);
void push(double val);
double pop(void);
void ptop(void);
void swap(void);
void clear(void);
void varpush(char);
char varpop(void);

int main()
{
	char op[MAXOP];		// holds operand or operator
	int vardecl[1000];
	double varvalues[1000];
	int type;
	double op2;

	while ((type = getop(op)) != EOF) {
		switch(type) {
		case NUMBER:
			push(atof(op));
			break;
		case SVAR:
			varpush(op[0]);
			break;
		case ASGN:
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
		case PRINT:
			ptop();
			break;
		case DUPLICATE:
			op2 = pop();
			push(op2);
			push(op2);
			break;
		case SWAP:
			swap();
			break;
		case CLEAR:
			clear();
			break;
		case SIN:
			push(sin(pop()));
			break;
		case POW:
			op2 = pop();
			push(pow(pop(), op2));
			break;
		case EXP:
			push(exp(pop()));
			break;
		default:
			printf("Unrecognized token\n");
			break;
		}

	}
}		

#define MAXVAL 1000

int sp = 0;
int vsp = 0;
double stack[MAXVAL];
char   vstack[MAXVAL];	// holds single-letter variables in itself

void push(double val)
{
	if (sp < MAXVAL)
		stack[sp++] = val;
	else
		printf("error: stack full. can't push %g\n", val);
}

double pop()
{
	if (sp > 0)
		return stack[--sp];
	else {
		printf("error: stack empty.\n");
		return 0.0;
	}
		
}

void ptop(void)
{
	if (sp > 0)	
		printf("\t%g\n", stack[sp-1]);
	else
		printf("\tstack is empty. nothing to display.\n");
}

void swap(void)
{
	double x, y;
	if (sp > 1) {
		x = pop();
		y = pop();
		push(x);
		push(y);
	}
	else
		printf("error: swap can't operate on 1 or fewer elements.\n");
}

void clear(void)
{
	sp = 0;
}

char varpop(void)
{
	if (vsp > 0)
		return vstack[--vsp];
	else {
		printf("error: variable stack empty\n");
		return ' ';
	}
}

void varpush(char c)
{
	if (vsp < MAXVAL)
		vstack[vsp++] = c;
	else
		printf("error: variable stack empty\n");
}

int getch();
void ungetch(int);
const char strsin[] = "sin";
const char strpow[] = "pow";
const char strexp[] = "exp";
int isstreq(const char [], const char []);

int getop(char s[])
{
	int i, c, c2;

	while ((s[0] = c = getch()) == ' ' || c == '\t' || c == '\n')
		;
	s[1] = '\0';
	i = 0;
	if (isalpha(c)) {
		while (isalpha(s[++i] = c = getch()))
			;
		s[i] = '\0';
		if (c != EOF)
			ungetch(c);
		if (strlen(s) == 1)		/* handle single letter variable */
			return SVAR;
		if (isstreq(s, strsin))
			return SIN;
		else if (isstreq(s, strpow))
			return POW;
		else if (isstreq(s, strexp))
			return EXP;
		else
			return s[i-1];
	}
	if (c == '-' || c == '+')		/* collect negative or positive numbers with unary '-', '+' */
		if (isdigit(c2 = getch()) || c2 == '.') {
			s[++i] = c2;
			c = c2;
		}
		else
			ungetch(c2);
	if (!isdigit(c) && c != '.')
		return c;		/* not a number */
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

int isstreq(const char s[], const char t[])
{
	int i;
	for (i = 0; s[i] != '\0' && t[i] != '\0' && s[i] == t[i]; i++)
		;
	return (strlen(s) == i) ? 1 : 0;
}
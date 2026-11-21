/* exercise 4.2 - Chapter 4 */

#include <stdio.h>
#include <ctype.h>

#define MAX 1000

int getline(char line[], int size);
double atof(char s[]);

int main()
{
	char line[MAX];
	double atof(char line[]);

	while (getline(line, MAX) > 0) {
		printf("%g\n", atof(line));
	}
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

double atof(char s[])
{
	int i, sign, esign, power;
	double value, enumber, evalue;	/* value of the number | exponent of E | multiple of 10 */

	i=0;
	value = 0.0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	for (; isdigit(s[i]); i++) {
		value = value * 10 + (s[i] - '0');
	}
	if (s[i] == '.')
		i++;
	power = 10;
	for (; isdigit(s[i]); i++) {
		value += (s[i] - '0') / (double) power;
		power *= 10;
	}
	if (s[i] == 'e' || s[i] == 'E')
		i++;
	esign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	enumber = 0;
	for (; isdigit(s[i]); i++)
		enumber = enumber * 10 + (s[i] - '0');
	evalue = 1;
	for (i = 0; i < enumber; i++) {
		evalue *= 10;
	}
	if (esign == -1)
		evalue = 1/evalue;
	return value*sign*evalue;
}
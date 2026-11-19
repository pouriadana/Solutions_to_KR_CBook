/* exercise 4.1 - Chapter 4 */
/* Find the rightmose occurance of t in s in strrindexx(t, s) */

/* Section 4.1 - Chapter 4 */
#include <stdio.h>

#define MAX 1000

int getline(char line[], int size);
int strindex(char line[], char pattern[]);
int strrindex(char line[], char patter[]);

char pattern[] = "ould";
int main()
{
	int rmindex;

	rmindex = 0;	// rightmost index
	char line[MAX];
	while ((getline(line, MAX)) > 0) {
		if ((rmindex =strrindex(line, pattern)) >= 0) {
			printf("%s\n (%d)\n", line, rmindex);
		}
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

int strindex(char line[], char pattern[])
{
	int i, j, k;

	for (i = 0; line[i] != '\0'; ++i) {
		for (j = i, k = 0; line[j] == pattern[k] && pattern[k] != '\0'; ++j, ++k)
			;
		if (k > 0 && pattern[k] == '\0')
			return i;
	}
	return -1;
}

int strrindex(char line[], char pattern[])
{
	int i, j, k, last;

	last = -1;
	for (i = 0; line[i] != '\0'; ++i) {
		for (j = i, k = 0; line[j] == pattern[k] && pattern[k] != '\0'; ++j, ++k)
			;
		if (k > 0 && pattern[k] == '\0')
			last = i;
	}
	return last;
}

/* My solution:
int strindex(char line[], char pattern[])
{
	int i, i2, j;

	i = 0;
	while (line[i] != '\0' && line[i] != pattern[0])
		++i;
	if (line[i] == '\0')
		return -1;
	j = 0;
	for (; i < MAX && line[i] != '\0'; ++i) {
		i2 = i;
		while (line[i2] == pattern[j]) {
			i2++;
			j++;
		}
		if (pattern[j] == '\0')
			return i;
		else
			j = 0;
	}
	return -1;
}
*/
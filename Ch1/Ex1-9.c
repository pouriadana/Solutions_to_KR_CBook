#include <stdio.h>
int main()
{
    int back;
    int front;

    back = getchar();
    putchar(back);
    while ((front = getchar()) != EOF) {
        if (front != ' ') {
            if (front != '\t')
                putchar(front);
        }
        if (front == ' ') {
            if (back != ' ') {
                putchar(front);
            }
        }
        if (front == '\t') {
            putchar(' ');
            front = ' ';
        }
        back = front;
    }
}
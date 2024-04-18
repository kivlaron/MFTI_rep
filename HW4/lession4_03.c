#include <stdio.h>

int main(void) {
int x, a, b, c;

scanf ("%d", &x);
a = (x%10)/1;
b = (x%100)/10;
c = (x%1000)/100;
x = a > b ? a : b;
printf ("%d", x > c ? x : c);
}

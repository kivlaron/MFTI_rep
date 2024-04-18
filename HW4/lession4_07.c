#include <stdio.h>

int main(void) {
int x1, x2, x3, x4, x5;

scanf ("%d%d%d%d%d", &x1, &x2, &x3, &x4, &x5);
x1 = x1 > x2 ? x1 : x2;
x1 = x1 > x3 ? x1 : x3;
x1 = x1 > x4 ? x1 : x4;
x1 = x1 > x5 ? x1 : x5;
printf ("%d", x1);
}

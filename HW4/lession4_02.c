#include <stdio.h>

int main(void) {
int a, b, c, st;

scanf ("%d%d%d", &a, &b, &c);
st = (a > b) ? a : b;
printf ("%d", (st > c) ? st : c);
}

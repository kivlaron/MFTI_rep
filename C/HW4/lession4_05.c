#include <stdio.h>

int main(void) {
int x1, y1, x2, y2;
float k, b;


scanf ("%d%d%d%d", &x1, &y1, &x2, &y2);

k = (float)(y2 - y1)/(x2 - x1);
b = y1*(float)(y2 - y1)/(y2 - y1) - x1*(float)(y2 - y1)/(x2 - x1);

printf ("%.2f%s%.2f", k, " ", b);
}

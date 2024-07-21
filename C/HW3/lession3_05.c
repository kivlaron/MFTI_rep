#include <stdio.h>

int main(void) {
int a, mul;

scanf ("%d", &a);
mul = (a%10)*((a%100)/10)*(a/100);
printf ("%d", mul);
}


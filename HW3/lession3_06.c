#include <stdio.h>

int main(void) {
int a, sum;

scanf ("%d", &a);
sum = ((a%10)/1) + ((a%100)/10) + ((a%1000)/100);
printf ("%d", sum);
}


#include <stdio.h>

int main(void) {
int month;

scanf ("%d", &month);
if (((month < 3) && (month > 0)) || (month == 12)) printf ("%s", "winter");
if ((month > 2) && (month < 6)) printf ("%s", "spring");
if ((month > 5) && (month < 9)) printf ("%s", "summer");
if ((month >= 9) && (month <= 11)) printf ("%s", "autumn");
}

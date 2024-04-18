#include <stdio.h>

int main(void) {
int x1, x2;

scanf ("%d%d", &x1, &x2);
if (x1 < x2) printf ("%s", "Less");
else if (x1 == x2) printf ("%s", "Equal");
else printf ("%s", "Above");
}

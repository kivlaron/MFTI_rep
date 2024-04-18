#include <stdio.h>

int main(void) {
int x1, x2, x3;

scanf ("%d%d%d", &x1, &x2, &x3);
if ((x1 < x2) && (x2 < x3)) printf ("%s", "YES");
else printf ("%s", "NO");
}

#include <stdio.h>
#include <stdint.h>

int main (void) {
    uint32_t a, b;

    scanf ("%d%d", &a, &b);
    do {
        if (a > b)
            a -= b;
        else
            b -= a;
    } while ((a > b) || (b > a));
    printf ("%d", a);
}

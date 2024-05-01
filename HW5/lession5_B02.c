#include <stdio.h>

int main (void) {
    int a, b = 0;

    scanf ("%d%d", &a, &b);
    if (a <= b) {
        for (int i = a; i <= b; i ++) {
            printf ("%d ", i*i);
        }
    }
}

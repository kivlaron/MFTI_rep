#include <stdio.h>

int main (void) {
    int a, b;

    scanf ("%d%d", &a, &b);
    if (a <= b) {
        int sum = 0;
        for (int i = a; i <= b; i ++) {
            sum += i*i;
        }
        printf ("%d ", sum);
    }
}

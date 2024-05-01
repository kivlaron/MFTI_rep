#include <stdio.h>

int main (void) {
    int inputNumber = 0;

    scanf ("%d", &inputNumber);
    if (inputNumber <= 100) {
        for (int i = 1; i <= inputNumber; i ++) {
            printf ("%d %d %d\n", i, i*i, i*i*i);
        }
    }
}

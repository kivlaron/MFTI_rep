#include <stdio.h>
#include <stdint.h>

int main (void) {
    int32_t num;
    uint16_t count = 0;

    do {
        scanf ("%d", &num);
        if (num%2 == 0)
            count ++;
    } while (num != 0);
    printf ("%d", count - 1);
}

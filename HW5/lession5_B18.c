#include <stdio.h>
#include <stdint.h>

int main (void) {
    uint16_t num;
    uint64_t sum = 1, prev = 0;

    scanf ("%hu", &num);
    printf ("1 ");
    for (uint32_t i = 1; i < num; i ++) {
        sum += prev;
        prev = sum - prev;
        printf ("%ld ", sum);
    }
}

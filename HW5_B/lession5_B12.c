#include <stdio.h>
#include <stdint.h>

int main (void) {
    uint32_t num;
    uint8_t min, max, t;

    scanf ("%d", &num);
    min = max = num%10;
    num /= 10;
    while (num != 0) {
        t = num%10;
        min = (t < min) ? t : min;
        max = (t > max) ? t : max;
        num /= 10;
    }
    printf ("%d %d", min, max);
}

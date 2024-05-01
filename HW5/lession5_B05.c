#include <stdio.h>
#include <stdint.h>

int main (void) {
    int32_t num;
    uint16_t summ = 0;

    scanf ("%u", &num);
    if (num >= 0) {
        do {
            summ += num%10;
            num /= 10;
        } while (num != 0);
        printf ("%d", summ);
    }
}

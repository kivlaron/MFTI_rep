#include <stdio.h>
#include <stdint.h>

int main (void) {
    int32_t num;
    uint16_t count = 0;

    do {
        scanf ("%d", &num);
        if (num == 0)
            break;
        count ++;
    } while (1);
    printf ("%d", count);
}

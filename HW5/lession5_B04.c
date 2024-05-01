#include <stdio.h>
#include <stdint.h>

int main (void) {
    int32_t num;
    uint8_t count = 0;

    scanf ("%u", &num);
    if (num >= 0) {
        do {
            num /= 10;
            count ++;
        } while (num != 0);
        if (count == 3) {
            printf ("YES");
        } else {
            printf ("NO");
        }
    }
}

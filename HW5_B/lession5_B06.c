#include <stdio.h>
#include <stdint.h>

int main (void) {
    int32_t num;
    uint8_t t = 0;

    scanf ("%u", &num);
    if (num < 0)
        num *= -1;
    if (num > 0) {
        t = num%10;
        num /= 10;
        do {
            if (num%10 == t) {
                printf ("YES");
                return 0;
            }
            t = num%10;
            num /= 10;
        } while (num != 0);
    }
    printf ("NO");
}

#include <stdio.h>
#include <stdint.h>

int main (void) {
    int32_t num;
    int8_t t;

    scanf ("%d", &num);
    if (num < 0)
        num *= -1;
    if (num > 0) {
        t = num%10;
        num /= 10;
        do {
            if (t <= num%10) {
                printf ("NO");
                return 0;
            }
            t = num%10;
            num /= 10;
        } while (num != 0);
    }
    printf ("YES");
}

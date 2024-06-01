#include <stdio.h>
#include <stdint.h>

int main (void) {
    int32_t num;
    uint8_t t = 0;

    scanf ("%d", &num);
    if (num < 0)
        num *= -1;
    if (num > 0) {
        do {
            t = num%10;
            num /= 10;
            int32_t num_tmp = num;
            do {
                if (num_tmp%10 == t) {
                    printf ("YES");
                    return 0;
                }
                num_tmp /= 10;
            } while (num_tmp != 0);
        } while (num != 0);
    }
    printf ("NO");
}

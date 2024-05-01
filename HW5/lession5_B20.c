#include <stdio.h>
#include <stdint.h>

int main (void) {
    uint32_t num;

    scanf ("%d", &num);
    if (num > 1) {
        for (uint32_t i = 2; i < num; i ++) {
            if ((num%i == 0)) {
                printf ("NO");
                return 0;
            }
        }
        printf ("YES");
    } else
        printf ("NO");
}

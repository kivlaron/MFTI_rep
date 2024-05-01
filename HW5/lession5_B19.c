#include <stdio.h>
#include <stdint.h>

int main (void) {
    uint32_t num, sum = 0;

    scanf ("%u", &num);
    do {
        sum += num%10;
        num /= 10;
    } while (num != 0);
    if (sum == 10)
        printf ("YES");
    else
        printf ("NO");
}

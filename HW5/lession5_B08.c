#include <stdio.h>
#include <stdint.h>

int main (void) {
    int32_t num;
    uint8_t count = 0;

    scanf ("%d", &num);
    do {
        if (num%10 == 9)
            count ++;
        num /= 10;
    } while (num != 0);
    if (count == 1)
        printf ("YES");
    else
        printf ("NO");
}

#include <stdio.h>
#include <stdint.h>

int main (void) {
    int32_t num;

    scanf ("%d", &num);
    do {
        if ((num%10)%2 != 0) {
            printf ("NO");
            return 0;
        }
        num /= 10;
    } while (num != 0);
    printf ("YES");
}

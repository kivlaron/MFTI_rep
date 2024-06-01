#include <stdio.h>
#include <stdint.h>

int main (void) {
    int32_t num, res;

    scanf ("%d", &num);
    if (num >= 0) {
        res = num%10;
        num /= 10;
        while (num != 0) {
            res *= 10;
            res += num%10;
            num /= 10;
        }
        printf ("%d", res);
    }
}

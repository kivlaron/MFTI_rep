#include <stdio.h>
#include <stdint.h>

int main (void) {
    uint32_t num;

    scanf ("%d", &num);
    if (num > 10) {
        for (int32_t i = 10; i <= num; i ++) {
            int32_t tmp = i, mul = tmp%10, sum = tmp%10;
            tmp /= 10;
            do {
                mul *= tmp%10;
                sum += tmp%10;
                tmp /= 10;
            } while (tmp != 0);
            if (mul == sum)
                printf ("%d ", i);
        }
    }
}

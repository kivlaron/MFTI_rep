#include <stdio.h>
#include <stdint.h>

int main (void) {
    uint32_t num;
    uint8_t evenCount = 0, notEvenCount = 0;

    scanf ("%d", &num);
    do {
        if ((num%10)%2 == 0)
            evenCount ++;
        else
            notEvenCount ++;
        num /= 10;
    } while (num != 0);
    printf ("%d %d", evenCount, notEvenCount);
}

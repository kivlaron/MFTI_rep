#include <stdio.h>
#include <stdint.h>

void evenSum(uint32_t n);


int main(int argc, char **argv)
{
    uint32_t n;
    scanf("%ud", &n);
    evenSum(n);
}

void evenSum(uint32_t n) {
    uint16_t sum = 0;
    do {
        sum += n%10;
        n /= 10;
    } while (n != 0);
    printf((sum%2 == 0) ? "YES" : "NO");
}



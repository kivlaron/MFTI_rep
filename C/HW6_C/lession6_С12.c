#include <stdio.h>
#include <stdint.h>

float sinus(float x);
float fact(uint32_t x);
float powr(float x, uint8_t p);
float const ACC = 0.001;

int main(int argc, char **argv)
{
    float x;
    scanf("%f", &x);
    if ((x >= 0) && (x <= 90))
        printf("%.3f", sinus(x*3.14159/180));
}

float sinus(float x) {
    float res = 0, it;
    uint8_t i = 1;
    do {
        it = (powr(-1, i - 1)*powr(x, 2*i - 1))/fact(2*i - 1);
        res += it;
        i ++;
    } while (((it > 0) ? it : -it) > ACC);
    return res;
}

float fact(uint32_t x) {
    uint32_t res = 1;
    for (uint32_t i = 1; i <= x; i ++)
        res *= i;
    return (float)res;
}

float powr(float x, uint8_t p) {
    float res = 1;
    for (uint8_t i = 1; i <= p; i ++)
        res *= x;
    return res;
}

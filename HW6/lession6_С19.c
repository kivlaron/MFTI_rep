#include <stdio.h>

int digitToNum(char c);

int main(int argc, char **argv)
{
    int dig_sum = 0;
    char c;
    while ((c = getchar()) != '.')
        dig_sum += digitToNum(c);
    printf("%d", dig_sum);
}

int digitToNum(char c) {
    if ((c >= '0') && (c <= '9'))
        return c - 48;
    return 0;
}

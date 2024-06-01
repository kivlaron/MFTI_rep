#include <stdio.h>

int isDigit(char c);

int main(int argc, char **argv)
{
    int dig_count = 0;
    char c;
    while ((c = getchar()) != '.')
        dig_count += isDigit(c);
    printf("%d", dig_count);
}

int isDigit(char c) {
    if ((c >= '0') && (c <= '9'))
        return 1;
    return 0;
}
